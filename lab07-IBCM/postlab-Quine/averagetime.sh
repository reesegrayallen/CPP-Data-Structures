
#!/bin/bash

# Reese Allen rga2uz averagetime.sh (modified) 10-21-20

# take in number of iterations as input
echo "enter the exponent for counter.cpp:"
read exp

total=0
five=5

if [[ ${exp} != "quit" ]] ; then
	for ((i=1; i<=five; i++)); do
		echo "Running iteration "${i}"..."
		RUNNING_TIME=`./a.out ${exp} | tail -1`
		echo "time taken: "${RUNNING_TIME}" ms"
		total=$((total+RUNNING_TIME))
	done

echo "5 iterations took "${total}" ms"
echo "Average time was "$((total/5))" ms"
fi
