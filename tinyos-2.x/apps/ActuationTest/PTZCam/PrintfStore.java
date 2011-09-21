/*
 * "Copyright (c) 2006 Washington University in St. Louis.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL WASHINGTON UNIVERSITY IN ST. LOUIS BE LIABLE TO ANY PARTY
 * FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING
 * OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF WASHINGTON
 * UNIVERSITY IN ST. LOUIS HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * WASHINGTON UNIVERSITY IN ST. LOUIS SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND WASHINGTON UNIVERSITY IN ST. LOUIS HAS NO
 * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
 * MODIFICATIONS."
 */

/**
 * @author Kevin Klues (klueska@cs.wustl.edu)
 * @version $Revision: 1.2 $
 * @date $Date: 2008/08/06 16:20:46 $
 */

import java.io.*;
import java.lang.System;

import net.tinyos.message.*;
import net.tinyos.tools.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class PrintfStore implements MessageListener {

    private static String[] sources = {
        "15", "172.17.4.185", 
        "16", "172.17.4.180", 
        "17", "172.17.4.175", 
        "18", "172.17.4.170", 
        "11", "172.17.4.186", 
        "12", "172.17.4.181", 
        "13", "172.17.4.171", 
        "8", "172.17.4.177" 
    };

    private MoteIF moteIF;
    private FileWriter fstream;
    private BufferedWriter out;
    private boolean newlog;

    public PrintfStore(MoteIF moteIF, String filename) {
        this.moteIF = moteIF;
        try {
            this.fstream = new FileWriter(filename);
            this.out = new BufferedWriter(this.fstream);
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
        this.moteIF.registerListener(new PrintfMsg(), this);
        this.newlog = true;
    }

    public void messageReceived(int to, Message message) {
        PrintfMsg msg = (PrintfMsg)message;
        try {
            for (int i=0; i<msg.totalSize_buffer(); i++) {
                char nextChar = (char)(msg.getElement_buffer(i));
                if (nextChar != 0) {
                    if (this.newlog) {
                        this.out.write(System.currentTimeMillis() + " ");
                        this.newlog = false;
                    }
                    this.out.write(nextChar);
                    if (nextChar == '\n') {
                        this.newlog = true;
                    }
                }
            }
            this.out.flush();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
        for (int i=0; i<msg.totalSize_buffer(); i++) {
            char nextChar = (char)(msg.getElement_buffer(i));
            if (nextChar != 0) {
                System.out.print(nextChar);
            }
        }
    }

    private static void usage() {
        System.err.println("usage: PrintfStore [-base <filename>]");
    }

    public static void main(String[] args) throws Exception {
        String filebase = null;

        if (args.length == 2) {
            if (!args[0].equals("-base")) {
                usage();
                System.exit(1);
            }
            filebase = args[1];
        }

        for (int i=0; i<sources.length; i+=2) {
            String filename;
            if ( filebase == null ) {
                filename = "MoteLog_" + sources[i] + ".txt";
            } else {
                filename = filebase + "/MoteLog_" + sources[i] + ".txt";
            }
            String psource = "network@" + sources[i+1] + ":10002";
            PhoenixSource phoenix = 
                BuildSource.makePhoenix(psource, PrintStreamMessenger.err);
            System.out.print(phoenix);
            System.out.println("Log file: " + filename);
            MoteIF mif = new MoteIF(phoenix);
            PrintfStore client = new PrintfStore(mif, filename);
        }
    }
}
