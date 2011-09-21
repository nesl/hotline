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
set logscale y
set xlabel "Time[s]"
set ylabel "Normalized Distance"
set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "light_distance_time.eps"

plot "estimate_distance.dat" u 1:3 notitle with lines ls 1

# Plot specific config
unset label
unset log
#set xrange [0:300]
set logscale y
set xlabel "Iteration"
set ylabel "Normalized Distance"
set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "light_distance_iter.eps"

plot "estimate_distance.dat" u 2:3 notitle with lines ls 1

