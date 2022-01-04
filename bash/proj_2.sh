#!/bin/bash
filename='test.tex'

start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_1=$(($end/100 - $start/100))

start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_2=$(($end - $start))


start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_3=$(($end - $start))


start=`date +%s%N`
./generate_latex.sh input.txt result result
end=`date +%s%N`
time_elapsed_4=$(($end - $start))



echo '\documentclass{article}
\usepackage{pgfplots} 
\pgfplotsset{compat=1.16}
\begin{document} 
\section{Equations}
\newline Time elapsed to generate 2 equations (1)' >> $filename

echo $time_elapsed_1 >> $filename


echo 'ns \newline Time elapsed to generate 2 equations (2)' >> $filename
echo $time_elapsed_2 >> $filename
echo 'ns' >> $filename

echo '\newline Time elapsed to generate 2 equations (3)' >> $filename
echo $time_elapsed_3 >> $filename
echo 'ns' >> $filename

echo '\newline Time elapsed to generate 2 equations (4)' >> $filename
echo $time_elapsed_4 >> $filename
echo 'ns' >> $filename

echo '
\begin{tikzpicture}
\begin{axis}[ybar, title={\textbf{Time to execute equations [ns]}}, symbolic x coords={Run1, Run2, Run3, Run4},
  legend pos = north west, axis y line=none, axis x line=bottom, nodes near coords, enlarge x limits=0.2, ] 
\addplot+ coordinates {(Run1, ' >> $filename 

echo $time_elapsed_1 >> $filename

echo ') (Run2, ' >> $filename

echo $time_elapsed_2 >> $filename

echo ') (Run3, ' >> $filename

echo $time_elapsed_3 >> $filename

echo ') (Run4, ' >> $filename 

echo $time_elapsed_4 >> $filename

echo ')}; 
\end{axis} 
\end{tikzpicture} 
\end{document}'>> $filename


pdflatex test.tex


echo "Done!"
