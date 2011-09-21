# Common config
set style line 1 lt 1 ps 2 lc rgb "#CC5318" lw 2
set style line 2 lt 2 ps 2 lc rgb "#181BCC" lw 2
set style line 3 lt 3 ps 2 lc rgb "#37A4FF" lw 2
set style line 4 lt 4 ps 2 lc rgb "#FFB777" lw 2
set style line 5 lt 5 ps 2 lc rgb "#5E5F99" lw 2

unset key
set grid
set key nobox
set key inside
set key left
set key top

set term postscript enhanced color lw 2 "Times" 21

# Plot specific config
unset label
unset log
#set xrange [0:300]
set xlabel "Time[s]"
set ylabel "Estimate of optimizer"
set title "Estimate for optimal output intensity of all lights"

set output "light_time.eps"

plot "estimate_0.dat" u 1:3 title 'Light 0' with lines ls 1, \
    "estimate_1.dat" index 0 u 1:3 title 'Light 1' with lines ls 2, \
    "estimate_2.dat" index 0 u 1:3 title 'Light 2' with lines ls 3, \
    "estimate_3.dat" index 0 u 1:3 title 'Light 3' with lines ls 5

# Plot specific config
unset label
unset log
#set xrange [0:300]
set xlabel "Iterations"
set ylabel "Estimate of optimizer"
set title "Estimate for optimal output intensity of all lights"

set output "light_iter.eps"

plot "estimate_0.dat" u 2:3 title 'Light 0' with lines ls 1, \
    "estimate_1.dat" index 0 u 2:3 title 'Light 1' with lines ls 2, \
    "estimate_2.dat" index 0 u 2:3 title 'Light 2' with lines ls 3, \
    "estimate_3.dat" index 0 u 2:3 title 'Light 3' with lines ls 5

