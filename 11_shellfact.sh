#!/bin/bash
echo "Enter a number"
read num
# if((num<0))
# then 
# echo "let 0"
# elif((num>0))
# then 
# echo "get 0"
# else
# echo "eq 0"
# fi
# fact=1
declare -a arr
for((i=0;i<num;i++))
{
  # echo -n $i
  read j
  arr[i]=$j
}

echo ${arr[@]}


# chmod +x 11_shellfact.sh 
# ./11_shellfact.sh 