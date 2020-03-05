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
	int nprobes_total = 0;
	double load = 0;
	int cnt = 0;
	while(cnt<5){
		seed = time(0);
		srand(seed);
		int number = rand() % 100001;
		nprobes_total = nprobes_total + hashTable.insert(number);
		cnt++;
		load = hashTable.load_factor();
		printf("%Lg\n", nprobes_total/cnt);
	}
	printf("50%% full: %Lg\n", nprobes_total/cnt);
}