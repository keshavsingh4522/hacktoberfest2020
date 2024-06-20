#sorting a array using bash programming
#input and output
#Enter number of elements in  the array : 4
#Enter element at index 1 : 8
#Enter element at index 2 : 3
#Enter element at index 3 : 9
#Enter element at index 4 : 1
#The array before sorting : 8 3 9 1
#The array after sorting : 1 3 8 9

echo -n "Enter number of elements in  the array : "
read n
i=0
declare arr[$n]

function input {
    while [ $i -lt $n ]; do
        echo -n "Enter element at index $((i + 1)) : "
        read arr[$i]
        i=$((i + 1))
    done
}

function display {
    i=0
    for ((i = 0; i < n; i++)); do
        echo -n ${arr[$i]}" "
    done
    echo
}

function sort {
    for ((i = 0; i < n - 1; i++)); do
        for ((j = 0; j < n - i - 1; j++)); do
            c1=${arr[$j]}
            c2=${arr[$((j + 1))]}
            jp1=$((j + 1))
            if [ $c1 -gt $c2 ]; then
                temp=${arr[$j]}
                arr[$j]=${arr[$jp1]}
                arr[$jp1]=$temp
            fi
        done
    done
}

input
echo -n "The array before sorting : "
display
echo -n "The array after sorting :  "
sort
display
