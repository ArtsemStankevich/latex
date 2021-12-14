#!/bin/bash

function wrap_text_in_section(){
	echo '\'"${1}{$2} $3 \end{$2}"
}

result_dir=$2
result_file=$3.tex

readarray -t arr < $1

mkdir -p $result_dir

rm -r tmp_charts
#rm file

mkdir tmp_charts

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


echo `cat src/latex_header.txt` > $result_dir/$result_file

for input in "${arr[@]}"
do
   echo $input>tmp.txt
    input_arr=($input)
    res=$(./roots <tmp.txt)
    title=x^2*${input_arr[0]}+x*${input_arr[1]}+${input_arr[2]}
    echo $(wrap_text_in_section 'section' "$title" '$res') >> $result_dir/$result_file
    
    echo $input_arr[0]>tmp.txt    
    #input_arr[0] = a,input_arr[1]=b, input_arr[2]=c    
    #input_arr[6] = chart from, input_arr[7]= chart to, input_arr[8]= chart colour    
#./chart.r

    echo $res >> $result_dir/$result_file
done

echo `cat src/latex_end.txt` >> $result_dir/$result_file
#DODAJ TU POLECENIE DLA GENERACJI PDF Z $result_dir/$result_file.tex
echo


