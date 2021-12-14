#!/bin/bash

result_dir=$2

readarray -t arr < $1

mkdir -p $result_dir

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


echo `cat src/latex_header.txt` > result/result.tex

for input in "${arr[@]}"
do
   echo $input>tmp.txt
   res=$(./roots <tmp.txt)
    echo $res
    echo $res >> result/result.tex
done




echo `cat src/latex_end.txt` >> result/result.tex
