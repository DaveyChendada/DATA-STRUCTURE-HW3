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
	int index = floor(1000*((value*A)-floor(value*A)));
	if(map[index]==-1){
		map[index] = value;
		this->nElem++;
		return nprobes;
	}
	else{
		while(map[index]!=-1){
			index = (index + 1)%1000;
			nprobes++;
			if(nprobes>=nSlot){
				return -1;
			}
		}
		map[index] = value;
		this->nElem++;
		return nprobes;
	}
	
	
}

void HashTable::setSize(int value){
	this->nElem = value;
}

void HashTable::setLoad(double value){
	this->load = value;
}

bool HashTable::find(int value, int& nProbes){
	int nprobes = 0;
	int index = floor(1000*((value*A)-floor(value*A)));
	while(nprobes<1001 && map[index]!=-1){
		if(map[index]==value){
			return true;
		}
		index = (index+1)/1000;
		nprobes++;
		nProbes = nprobes;
	}
	return false;
	
}