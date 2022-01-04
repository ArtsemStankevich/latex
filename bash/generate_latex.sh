#!/bin/bash

function wrap_text_in_section(){
	echo '\'"${1}{$2} $3 \end{$2}"
}
start_all=`date +%s%N`
result_dir=$2
result_file=$3.tex

readarray -t arr < $1

mkdir -p $result_dir

rm file
touch file

#check is file exist
if [ -a "$result_dir" ] ; then
	read -p "Directory ${result_dir} is exist. Do you want to rewrite?[y/n]: " -n 1 -r
	if [[ $REPLY =~ ^[Yy]$ ]] ; then
		rm -r $result_dir
		mkdir $result_dir
	else
		exit
	fi
fi


if ! [[ -w "$result_dir" ]] ; then
	echo $result_dir":permission denied!"
	exit
fi 


mkdir $result_dir/"charts_tmp"
echo `cat src/latex_header.txt` > $result_file

let i=0

for input in "${arr[@]}"
do

    start=`date +%s%N`

    echo $input>tmp.txt
    input_arr=($input)
    res=$(./roots < tmp.txt)
    echo $res >> $result_file
    chart_tmp=${input_arr[0]}" "${input_arr[1]}"  "${input_arr[2]}" "${input_arr[3]}" "${input_arr[7]}" "${input_arr[8]}" "${input_arr[9]}
    echo $chart_tmp > file
    ./chart.r file $i"img"
    echo '\\\' >> $result_file

    echo "\includegraphics[width=0.5\textwidth]{charts_tmp/"$i"img.png}" >> $result_file
    end=`date +%s%N`
    time_elapsed=$(($end - $start))
    echo "\newline $time_elapsed nanoseconds elpased" >> $result_file
    echo "\clearpage " >> $result_file
  let i=i+1
done
end_all=`date +%s%N`
time_elapsed_all=$(($end - $start))
echo "\newline $time_elapsed_all nanoseconds elpased for entire script" >> $result_file

    echo "\includegraphics[width=\linewidth]{charts_tmp/"$i"img.png}" >> $result_file
let i=i+1
done

echo `cat src/latex_end.txt` >> $result_file
pdflatex $result_file
echo
