all:compile

compile: 
	gcc brute.c -lm -o brute
	gcc backtrack.c -lm -o backtrack

run1:
	./brute knapsack.txt
run2:
	./backtrack knapsack.txt

clean:
	rm -rf brute backtrack brute_output.txt backtrack_output.txt