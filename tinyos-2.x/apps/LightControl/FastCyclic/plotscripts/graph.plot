# Common config
#set style line 1 lt 1 ps 2 lc rgb "#CC5318" lw 2
#set style line 2 lt 2 ps 2 lc rgb "#181BCC" lw 2
#set style line 3 lt 3 ps 2 lc rgb "#37A4FF" lw 2
#set style line 4 lt 4 ps 2 lc rgb "#FFB777" lw 2
#set style line 5 lt 5 ps 2 lc rgb "#5E5F99" lw 2

set style line 1 lt 1 ps 1.5 lc rgb "#5E5F99" lw 2 
set style line 2 lt 2 ps 1.5 lc rgb "black" lw 2 
#set style line 2 lt 2 ps 1.5 lc rgb "#181BCC" lw 2 
set style line 3 lt 3 ps 1.5 lc rgb "purple" lw 2
#set style line 3 lt 3 ps 1.5 lc rgb "#00A4FF" lw 2
set style line 4 lt 4 ps 1.5 lc rgb "black" lw 2
#set style line 4 lt 4 ps 1.5 lc rgb "#CC5318" lw 2
#set style line 4 lt 4 ps 1.5 lc rgb "#FFB777" lw 2
set style line 5 lt 5 ps 1.5 lc rgb "#5E5F99" lw 2
set style line 6 lt 6 ps 1.5 lc rgb "red" lw 2
set style line 7 lt 7 ps 1.5 lc rgb "black" lw 2
set style line 8 lt 8 ps 1.5 lw 1.5


unset key
set grid
set key nobox
set key inside
set key right
set key top

set term postscript enhanced color lw 2 "Times" 21

# Plot specific config
unset label
unset log
set autoscale
#set size 1.0,0.5
set xrange [0:100]
set logscale y
set xlabel "Iteration number, {/Symbol m}"
set ylabel "F(I)"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "n7_seq_iter_d1.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Ring' with lines ls 1, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq1/run0/objective_fn.dat" u 2:3 title 'Seq1' with lines ls 2, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq3/run0/objective_fn.dat" u 2:3 title 'Seq3' with lines ls 3, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq4/run0/objective_fn.dat" u 2:3 title 'Seq4' with lines ls 4, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq7/run0/objective_fn.dat" u 2:3 title 'GColor' with lines ls 5, \
     "../sim/plots/static/WC/nodeid/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Nodeid' with lines ls 6, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Random' with lines ls 7
#   "../../Cyclic/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Cyclic' with lines ls 3, \
#   "../sim/plots/dynamic/adaptive/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-Adp-time' with lines ls 4, \
#   "../sim/plots/dynamic/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC-ring' with lines ls 2, \
#    "../sim/plots/static/adaptive/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Static-Adp-ring' with lines ls 5
#    "../../FastConsensus/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'FC' with lines ls 5

# Plot specific config
unset label
unset log
set autoscale
#set size 1.0,0.5
set xrange [0:20]
set logscale y
set xlabel "Iteration number, {/Symbol m}"
set ylabel "F(I)"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "n7_seq_iter_d1_zoom.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Ring' with lines ls 1, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq1/run0/objective_fn.dat" u 2:3 title 'Seq1' with lines ls 2, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq3/run0/objective_fn.dat" u 2:3 title 'Seq3' with lines ls 3, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq4/run0/objective_fn.dat" u 2:3 title 'Seq4' with lines ls 4, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree1/seq7/run0/objective_fn.dat" u 2:3 title 'GColor' with lines ls 5, \
     "../sim/plots/static/WC/nodeid/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Nodeid' with lines ls 6, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Random' with lines ls 7, \
     1064 title 'User values' with lines ls 8, \
     898 notitle with lines ls 8
#   "../../Cyclic/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Cyclic' with lines ls 3, \
#   "../sim/plots/dynamic/adaptive/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-Adp-time' with lines ls 4, \
#   "../sim/plots/dynamic/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC-ring' with lines ls 2, \
#    "../sim/plots/static/adaptive/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Static-Adp-ring' with lines ls 5
#    "../../FastConsensus/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'FC' with lines ls 5

# Plot specific config
unset label
unset log
set autoscale
#set size 1.0,0.5
set xrange [0:100]
set logscale y
set xlabel "Iteration number, {/Symbol m}"
set ylabel "F(I)"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "n7_seq_iter_d2.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Ring' with lines ls 1, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq1/run0/objective_fn.dat" u 2:3 title 'Seq1' with lines ls 2, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq3/run0/objective_fn.dat" u 2:3 title 'Seq3' with lines ls 3, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq4/run0/objective_fn.dat" u 2:3 title 'Seq4' with lines ls 4, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq7/run0/objective_fn.dat" u 2:3 title 'GColor' with lines ls 5, \
     "../sim/plots/static/WC/nodeid/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Nodeid' with lines ls 6, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Random' with lines ls 7
#   "../../Cyclic/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Cyclic' with lines ls 3, \
#   "../sim/plots/dynamic/adaptive/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-Adp-time' with lines ls 4, \
#   "../sim/plots/dynamic/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC-ring' with lines ls 2, \
#    "../sim/plots/static/adaptive/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Static-Adp-ring' with lines ls 5
#    "../../FastConsensus/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'FC' with lines ls 5

# Plot specific config
unset label
unset log
set autoscale
#set size 1.0,0.5
set xrange [0:20]
set logscale y
set xlabel "Iteration number, {/Symbol m}"
set ylabel "F(I)"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "n7_seq_iter_d2_zoom.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Ring' with lines ls 1, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq1/run0/objective_fn.dat" u 2:3 title 'Seq1' with lines ls 2, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq3/run0/objective_fn.dat" u 2:3 title 'Seq3' with lines ls 3, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq4/run0/objective_fn.dat" u 2:3 title 'Seq4' with lines ls 4, \
     "../sim/plots/static/WC/ring/alphaset1/nodes7degree2/seq7/run0/objective_fn.dat" u 2:3 title 'GColor' with lines ls 5, \
     "../sim/plots/static/WC/nodeid/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Nodeid' with lines ls 6, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree2/run0/objective_fn.dat" u 2:3 title 'Random' with lines ls 7, \
     1872 title 'User values' with lines ls 8, \
     1535 notitle with lines ls 8
#   "../../Cyclic/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Cyclic' with lines ls 3, \
#   "../sim/plots/dynamic/adaptive/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-Adp-time' with lines ls 4, \
#   "../sim/plots/dynamic/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC-ring' with lines ls 2, \
#    "../sim/plots/static/adaptive/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Static-Adp-ring' with lines ls 5
#    "../../FastConsensus/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'FC' with lines ls 5

