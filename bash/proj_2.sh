#!/bin/bash
filename='test.tex'
echo > $filename
start=`date +%s%N`
./generate_latex.sh 20 result0
end=`date +%s%N`
time_elapsed_1=$(($end - $start))

start=`date +%s%N`
./generate_latex.sh 10 result1
end=`date +%s%N`
time_elapsed_2=$(($end - $start))


start=`date +%s%N`
./generate_latex.sh 100 result2
end=`date +%s%N`
time_elapsed_3=$(($end - $start))


start=`date +%s%N`
./generate_latex.sh 50 result4
end=`date +%s%N`
time_elapsed_4=$(($end - $start))



echo '\documentclass{article}
\usepackage{pgfplots} 
\pgfplotsset{compat=1.16}
\begin{document} 
\section{Equations}
\newline Run 0: Time elapsed to generate 20 equations' >> $filename

echo $time_elapsed_1 >> $filename


echo 'ns \newline Run1: Time elapsed to generate 10 equations' >> $filename
echo $time_elapsed_2 >> $filename
echo 'ns' >> $filename

echo '\newline Run 2: Time elapsed to generate 100 equations' >> $filename
echo $time_elapsed_3 >> $filename
echo 'ns' >> $filename

echo '\newline Run3: Time elapsed to generate 50 equations' >> $filename
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

pdflatex -interaction=nonstopmode test.tex 


echo "Done!"

