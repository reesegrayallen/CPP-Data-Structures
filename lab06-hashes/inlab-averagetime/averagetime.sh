#!/bin/bash

# Reese Allen rga2uz averagetime.sh 10-14-20

# read in dictionary
echo "Enter name of dictionary file."
read dict

# read in grid
echo "Enter name of grid file."
read grid 

# 5 commands to record execution time
# print out average run time

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$RUNNING_TIME

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total+RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total+RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total+RUNNING_TIME))

RUNNING_TIME=`./a.out $dict $grid | tail -1`
total=$((total+RUNNING_TIME))

echo $((total/5))
