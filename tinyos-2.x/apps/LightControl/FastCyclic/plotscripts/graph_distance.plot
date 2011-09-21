# Common config
set style line 1 lt 1 ps 2 lc rgb "#CC5318" lw 2
set style line 2 lt 2 ps 2 lc rgb "#181BCC" lw 2
set style line 3 lt 3 ps 2 lc rgb "#37A4FF" lw 2
set style line 4 lt 4 ps 2 lc rgb "#FFB777" lw 2
set style line 5 lt 5 ps 2 lc rgb "#5E5F99" lw 2
set style line 6 lt 6 ps 2 lc rgb "#000000" lw 2

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
set autoscale
#set size 1.0,0.5
set xrange [0:200]
set logscale y
set xlabel "Iteration"
set ylabel "Cost"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node3_event_iter.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 2:3 title 'Static-WC' with lines ls 1, \
     "../sim/plots/static/adaptive/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 2:3 title 'Static-adapt' with lines ls 2, \
     "../sim/plots/dynamic/WC/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC' with lines ls 3, \
     "../sim/plots/dynamic/adaptive/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 2:3 title 'Dyn-adapt' with lines ls 4
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
#set xrange [0:100]
set logscale y
set xlabel "Time [s]"
set ylabel "Cost"
#set title "Normalized Distance of Estimates from Optimal Output Intensities"

set output "node3_event_time.eps"

plot "../sim/plots/static/WC/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 1:3 title 'Static-WC' with lines ls 1, \
     "../sim/plots/static/adaptive/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 1:3 title 'Static-adapt' with lines ls 2, \
     "../sim/plots/dynamic/WC/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 1:3 title 'Dyn-WC' with lines ls 3, \
     "../sim/plots/dynamic/adaptive/ring/alphaset1/nodes3degree1/event1/run0/objective_fn.dat" u 1:3 title 'Dyn-adapt' with lines ls 4
#   "../../Cyclic/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Cyclic' with lines ls 3, \
#   "../sim/plots/dynamic/adaptive/timestamps/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-Adp-time' with lines ls 4, \
#   "../sim/plots/dynamic/WC/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Dyn-WC-ring' with lines ls 2, \
#    "../sim/plots/static/adaptive/ring/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'Static-Adp-ring' with lines ls 5
#    "../../FastConsensus/sim/plots/alphaset1/nodes7degree1/run0/objective_fn.dat" u 2:3 title 'FC' with lines ls 5

