#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime> // Header file needed to use time
using namespace std;

int
main (int argc, char* argv[])
{
	HashTable hashTable;
	unsigned seed;
	seed = time(0);
	srand(seed);
	int number = rand() % 100001;
	printf("number is %d\n", number);
	double nprobes_total = 0;
	double load = 0;
	double cnt = 0;
	while(cnt<5){
		nprobes_total = nprobes_total + hashTable.insert(number);
		cnt++;
		double size = (double)hashTable.size();
		double capacity = (double)hashTable.capacity();
		load = size/capacity;
		printf("load is %f\n",load);
		hashTable.setLoad(load);
		load = hashTable.load_factor();
		
	}
	printf("50%% full: %f\n", nprobes_total/cnt);
}