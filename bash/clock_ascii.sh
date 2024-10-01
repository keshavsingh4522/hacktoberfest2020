#!/bin/bash

numbers=(
    '    0000000           11111          22222222        333333333                4444       5555555555          6666666    7777777777777       88888888         9999999    '
    '   0000000000       1111111         22222222222      33333333333             44444      55555555555        666666666    7777777777777     88888888888      99999999999  '
    '  0000    0000      111 111         22      2222     33      333            444444     555                66666                  7777    8888     8888    9999     9999 '
    ' 000        000         111                  222             3333          444 444     555               666                     777     888       888    999       999 '
    ' 000        000         111                  222             333          444  444     55               666                     777      8888     8888   9999       999 '
    ' 000        000         111                 2222       33333333          444   444     555555555        66666666666            777       88888  88888    9999       999'
    ' 000        000         111                 222        3333333          444    444     55555555555     66666666666666         7777          8888888       9999     9999 '
    ' 000        000         111               2222            333333       444     444             5555    6666       666        7777         88888888888      999999999999 '
    ' 000        000         111              2222                3333     44444444444444            555    666        6666      7777         8888     8888      9999999 999 '
    ' 000        000         111            22222                  333    444444444444444            555    666        6666      777         8888       8888            9999 '
    ' 0000      0000         111           2222                    333              444              555     666       666      7777         8888       8888           9999  '
    '  0000    0000          111         2222             33      3333              444     5      5555      6666     6666     7777           8888     8888          99999   '
    '   0000000000           111        2222222222222    333333333333               444    55555555555        66666666666     7777             88888888888      99999999     '
    '     000000             111        2222222222222     333333333                 444     55555555            6666666       777                8888888        999999       '
);

dots=(
    ' ## '
    ' ## '
);

len=${#numbers[@]};


function print_number {
    start=$[$1*17];
    start_y=$[$2*17+$3*4+$beg_y];

    for i in `seq 0 $[$len-1]`; 
    do
        echo -ne "\033[$((beg_x+i));${start_y}H\e[1;31m${numbers[$i]:$start:17}\e[0m";
    done
}

function print_dot {
    local pt=$[$1*17+$2*4+beg_y];
    for j in 0 1; 
    do
        echo -ne "\033[$((beg_x+j+3));${pt}H\e[1;94m${dots[$j]}\e[0m";
        echo -ne "\033[$((beg_x+j+10));${pt}H\e[1;94m${dots[$j]}\e[0m";
    done
}

function old_value {
    nrows=`tput lines`; 
    beg_x=$[nrows/2-6]; 
    ncols=`tput cols`;  
    beg_y=$[ncols/2-54];
    
    #in base 10
    nhour=$((10#`date +%H`));
    nmin=$((10#`date +%M`));
    nsec=$((10#`date +%S`));

    print_number $[nhour/10] 0 0; print_number $[nhour%10] 1 0;
    print_dot 2 0;
    print_number $[nmin/10] 2 1; print_number $[nmin%10] 3 1;
    print_dot 4 1;
    print_number $[nsec/10] 4 2; print_number $[nsec%10] 5 2;
}

function print_all {
    t_rows=`tput lines`; 
    beg_x=$((t_rows/2-6));
    t_cols=`tput cols`;  
    beg_y=$((t_cols/2-54));

    if [[ $t_rows -ne $nrows || $t_cols -ne $ncols ]]; then
        nrows=$t_rows;
        ncols=$t_cols;
        check_win $nrows $ncols;
        old_value;
    fi

    hur=$((10#`date +%H`));
    hft=$[hur/10];
    hsd=$[hur%10];
    if [[ $ohft -ne $hft ]]; 
        then
        print_number $hft 0 0;
        ohft=$hft;
    fi
    if [[ $ohsd -ne $hsd ]]; 
        then
        print_number $hsd 1 0;
        ohsd=$hsd;
    fi

    min=$((10#`date +%M`));
    mft=$[min/10]; 
    msd=$[min%10];
    if [[ $omft -ne $mft ]]; 
        then
        print_number $mft 2 1;
        omft=$mft;
    fi
    if [[ $omsd -ne $msd ]]; 
        then
        print_number $msd 3 1;
        omsd=$msd;
    fi

    sec=$((10#`date +%S`));
    sft=$[sec/10]; 
    ssd=$[sec%10];
    if [[ $osft -ne $sft ]]; 
        then
        print_number $sft 4 2;
        osft=$sft;
    fi
    if [[ $ossd -ne $ssd ]]; 
        then
        print_number $ssd 5 2;
        ossd=$ssd;
    fi

}

#check window sizes
function check_win {
    if [[ $1 -lt 14 || $2 -lt 110 ]]; then
        clear;
        echo -ne "\033[8;15;120t"; #change the window size
    fi
    clear;
}

function INIT {
    tput smcup; #Save screen contents
    check_win `tput lines` `tput cols`;
    trap 'EXIT;' SIGINT;
    tput civis; #Set to cursor to be invisible
    old_value;
}

function EXIT {
    tput cvvis; #Set to cursor to be visible
    tput rmcup; #Restore screen contents
    exit 0;
}


INIT;
# read options:
# -t timeout   
#    Cause read to time out and return failure if a complete line
#   of input is not read within timeout seconds. This option has no
#   effect if read is not reading input from the terminal or a pipe.

# -n nchars
#   read returns after reading nchars characters rather
#   than waiting for a complete line of input.

while true; do
    read -t 0.01 -n 1 anykey;
    if [[ $? -eq 0 ]]; then
        EXIT;
    fi
    print_all;
    sleep 0.3; 
done

exit 0;
