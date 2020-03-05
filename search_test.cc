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
	int i = 0;
	int cnt1 = 10000;
	int cnt2 = 10000;
	double nprobes_total = 0;
	double nprobes_total1 = 0;
	double nprobes_total2 = 0;
	double load = 0;
	double cnt = 0;
	int probe_total = 0;
	int probe_num = 0;
	while(load<0.5){
		seed = time(0);
		srand(seed);
		int number = rand() % 100001;
		nprobes_total = nprobes_total + hashTable.insert(number);
		cnt++;
		double size = (double)hashTable.size();
		double capacity = (double)hashTable.capacity();
		load = size/capacity;
		hashTable.setLoad(load);
		load = hashTable.load_factor();
	}
	
	for(i=0;i<10000;i++){
		seed = time(0);
		srand(seed);
		int number = rand() % 100001;
		hashTable.find(number, probe_num);
		//printf("probe: %d\n", probe_num);
		probe_total = probe_total + probe_num;
		probe_num = 0; 		
	}
	double doub_probe = (double) probe_total;
	printf("50%% full: %f\n", doub_probe/10000);
	probe_total = 0;
	
	
	while(load<0.9){
		seed = time(0);
		srand(seed);
		int number = rand() % 100001;
		nprobes_total = nprobes_total + hashTable.insert(number);
		cnt++;
		double size = (double)hashTable.size();
		double capacity = (double)hashTable.capacity();
		load = size/capacity;
		hashTable.setLoad(load);
		load = hashTable.load_factor();	
	}
	for(i=0;i<10000;i++){
		seed = time(0);
		srand(seed);
		int number = rand() % 100001;
		hashTable.find(number, probe_num);
		probe_total = probe_total + probe_num;
		probe_num = 0; 		
	}
	doub_probe = (double) probe_total;
	printf("90%% full: %f\n", doub_probe/10000);
}