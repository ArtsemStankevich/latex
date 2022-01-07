#!/bin/bash


start_all=`date +%s%N`
result_file="../latex_output/"$2.tex

count=0
while [ "$count" -le $1 ] ;
do
 arr[$count]=$((RANDOM% 21 + 1))' '$((RANDOM% 21))' '$((RANDOM% 21))' '$((RANDOM% 21))' '$((RANDOM% 21))' '$((RANDOM% 3))' '$((RANDOM % 25))' '$((RANDOM% 21))' 'Yellow
 let "count += 1"
done

touch "tmp_data_for_chart.txt"
touch "tmp_data_for_roots.txt"
echo `cat src/latex_header.txt` > $result_file

let i=0

for input in "${arr[@]}"
do
    start=`date +%s%N`
    echo $input>"tmp_data_for_roots.txt"
    input_arr=($input)
    res=$(./roots < tmp_data_for_roots.txt)
    res_sect=$res
    echo $res_sect >> $result_file
    chart_tmp=${input_arr[0]}" "${input_arr[1]}"  "${input_arr[2]}" "${input_arr[3]}" "${input_arr[7]}" "${input_arr[8]}" "${input_arr[9]} 
    echo $chart_tmp > "tmp_data_for_chart.txt"
    echo '\\\' >> $result_file
    echo "\includegraphics[width=0.5\textwidth]{res/"$i"img.png}" >> $result_file
    end=`date +%s%N`
    time_elapsed=$(($end - $start))
    echo "\newline $time_elapsed nanoseconds elpased" >> $result_file
    echo "\clearpage " >> $result_file
let i=i+1
done
end_all=`date +%s%N`
time_elapsed_all=$(($end - $start))
echo "\newline $time_elapsed_all nanoseconds elpased for entire script" >> $result_file
echo `cat src/latex_end.txt` >> $result_file
rm "tmp_data_for_roots.txt"
rm "tmp_data_for_chart.txt"
echo
