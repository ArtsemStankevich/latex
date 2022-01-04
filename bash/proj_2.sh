start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_1=$(($end - $start))

start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_2=$(($end - $start))


start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_3=$(($end - $start))

#!/bin/bash
latex <<theend
\documentclass{article}
\begin{document}
Time elapsed to generate 2 equations (1)
$time_elapsed_1
\newline

Time elapsed to generate 2 equations (2)
$time_elapsed_2
\newline

\end{document}
theend




echo "Done!"
