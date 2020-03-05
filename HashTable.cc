#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h> 
using namespace std;

#define A 0.618

HashTable::HashTable(void){
	int i =0;
	load = 0;
	nSlot = 100;
	map = new int[100];
	nElem = 0;
	for(i=0;i<100;i++){
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
	printf("the index is %d", index);
	while(map[index]!=-1){
		double a = floor(A*index);
		int b = (int) a;
		double tmp = A*index - b;
		double tmp2 = tmp*index;
		double tmp3 = floor(tmp2);
		index = (int) tmp3;
		printf("the index2 is %d", index);
		nprobes= nprobes +1;
		if(nprobes>=nSlot){
			return -1;
		}
	}
	map[index] = value;
	this->nElem++;
	printf("the nprobes is %d", nprobes);
	return nprobes;
}

void HashTable::setSize(int value){
	this->nElem = value;
}

void HashTable::setLoad(double value){
	this->load = value;
}