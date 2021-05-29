#!/bin/bash

NAME='../push_swap'
CNT=100
TESTS=(3 4 5 10 100 500)
OK="OK"

for t in ${TESTS[@]}; do
	i=0
	echo $t testing...
	for (( c = 0; c < $CNT; c++ )); do
		echo -en \\r$c/$CNT
		ARGS=`ruby -e "puts (1..$t).to_a.shuffle.join(' ')"`
		$NAME $ARGS > out.txt
		CHECK=`cat out.txt | ../checker	$ARGS`
		if [ "$CHECK" = "$OK" ]; then
			((i++))
		else
			echo -e \\n$ARGS\\n
		fi
		cat out.txt | grep -e '^[prs]' | wc -l >> test$t.txt
	done
	echo -e \\r$i/$CNT OK!
	echo $t:
	./count < test$t.txt
	rm test$t.txt
done
