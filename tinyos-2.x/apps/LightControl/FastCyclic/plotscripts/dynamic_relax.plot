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
set autoscale
#set size 1.0,0.5
#set xrange [0:1000]
set logscale y
set xlabel "Iteration"
set ylabel "Cost"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "dy_node7_d1_iter.eps"

plot "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dynamic-r0' with lines ls 1, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dy-relax-r0' with lines ls 2, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run1/objective_fn.dat" u 2:3 title 'Dynamic-r1' with lines ls 3, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run1/objective_fn.dat" u 2:3 title 'Dy-relax-r1' with lines ls 4, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run2/objective_fn.dat" u 2:3 title 'Dynamic-r2' with lines ls 5, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run2/objective_fn.dat" u 2:3 title 'Dy-relax-r2' with lines ls 6

# Plot specific config
unset label
unset log
set autoscale
#set size 1.0,0.5
#set xrange [0:400]
set logscale y
set xlabel "Time [s]"
set ylabel "Cost"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "dy_node7_d1_time.eps"

plot "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 1:3 title 'Dynamic-r0' with lines ls 1, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run0/objective_fn.dat" u 1:3 title 'Dy-relax-r0' with lines ls 2, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run1/objective_fn.dat" u 1:3 title 'Dynamic-r1' with lines ls 3, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run1/objective_fn.dat" u 1:3 title 'Dy-relax-r1' with lines ls 4, \
     "../sim/plots/dynamic/WC/timestamps/alphaset1/nodes7degree1/run2/objective_fn.dat" u 1:3 title 'Dynamic-r2' with lines ls 5, \
     "../sim/plots/dynamic/WC/timestamps/relax/alphaset1/nodes7degree1/run2/objective_fn.dat" u 1:3 title 'Dy-relax-r2' with lines ls 6

