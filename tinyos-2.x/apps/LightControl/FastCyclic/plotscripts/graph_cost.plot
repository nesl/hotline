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
#set xrange [0:300]
set logscale y
set xlabel "Iterations"
set ylabel "Local cost"
set title "Value of local component of objective fn"

set output "cost_iter.eps"

plot "local_cost_0.dat" u 1:2 title 'Sensor 0' with lines ls 1, \
     "local_cost_1.dat" u 1:2 title 'Sensor 1' with lines ls 2, \
     "local_cost_2.dat" u 1:2 title 'Sensor 2' with lines ls 3, \
     "local_cost_3.dat" u 1:2 title 'Sensor 3' with lines ls 4, \
     "local_cost_4.dat" u 1:2 title 'Sensor 4' with lines ls 5, \
     "local_cost_5.dat" u 1:2 title 'Sensor 5' with lines ls 1, \
     "local_cost_6.dat" u 1:2 title 'Sensor 6' with lines ls 2, \
     "local_cost_7.dat" u 1:2 title 'Sensor 7' with lines ls 3, \
     "local_cost_8.dat" u 1:2 title 'Sensor 8' with lines ls 4, \
     "local_cost_9.dat" u 1:2 title 'Sensor 9' with lines ls 5
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 1, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 2, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 3, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 4, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 5, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 1, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 2, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 3, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 4, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 5, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 1, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 2, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 3, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 4, \
#     "local_cost_.dat" u 1:2 title 'Sensor ' with lines ls 5

