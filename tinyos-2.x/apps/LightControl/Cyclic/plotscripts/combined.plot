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
set key right
set key top

set term postscript enhanced color lw 2 "Times" 21

# Plot specific config
unset label
unset log
set size 1.0,0.5
set xrange [0:1500]
set logscale y
set xlabel "Time[s]"
set ylabel "Normalized Distance from Optimizer"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node3_comp_time.eps"

plot "nodes3degree2/run0/estimate_distance.dat" u 1:3 title 'Original-Light' with lines ls 1, \
    "../../../FastCyclic/sim/plots/nodes3degree2/run0/estimate_distance.dat" u 1:3 title 'Hotline-Light' with lines ls 2

# Plot specific config
unset label
unset log
set xrange [0:1000]
set logscale y
set xlabel "Iteration Number"
set ylabel "Normalized Distance from Optimizer"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node3_comp_iter.eps"

plot "nodes3degree2/run0/estimate_distance.dat" u 2:3 title 'Original-Light' with lines ls 1, \
    "../../../FastCyclic/sim/plots/nodes3degree2/run0/estimate_distance.dat" u 2:3 title 'Hotline-Light' with lines ls 2

# Plot specific config
unset label
unset log
set size 1.0,0.5
set xrange [0:1500]
set logscale y
set xlabel "Time[s]"
set ylabel "Norm. Dist."
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node5_comp_time.eps"

plot "nodes5degree1/run0/estimate_distance.dat" u 1:3 title 'Original-Light' with lines ls 1, \
    "../../../FastCyclic/sim/plots/nodes5degree1/run0/estimate_distance.dat" u 1:3 title 'Hotline-Light' with lines ls 2

# Plot specific config
unset label
unset log
set size 1.0,0.5
set xrange [0:1000]
set logscale y
set xlabel "Iteration"
set ylabel "Norm. Dist."
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node5_comp_iter.eps"

plot "nodes5degree1/run0/estimate_distance.dat" u 2:3 title 'Original-Light' with lines ls 1, \
    "../../../FastCyclic/sim/plots/nodes5degree1/run0/estimate_distance.dat" u 2:3 title 'Hotline-Light' with lines ls 2

