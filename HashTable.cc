#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h> double floor(double x); 
using namespace std;

#define A 0.618

HashTable::HashTable(void){
	int i =0;
	load = 0;
	nSlot = 1000;
	map = new int[1000];
	nElem = 0;
	for(i=0;i<1000;i++){
		map[i] = -1;
	}
}


HashTable::~HashTable(void){
	delete[] map;
}

int HashTable::insert(int value){
	int nprobes = 0;
	int temp = value / nSlot;
	int index = value - temp*nSlot;
	while(map[index]!=-1){
		double a = floor(A*index);
		int b = (int) a;
		double tmp = A*index - b;
		double tmp2 = tmp*index;
		double tmp3 = floor(tmp2);
		index = (int) tmp3;
		nprobes ++;
		if(nprobes>=nSlot){
			return -1;
		}
	}
	map[index] = value;
	nElem++;
	load = nElem/nSlot;
	return nprobes;
}