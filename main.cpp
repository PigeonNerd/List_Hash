#include "cache_element.h"
#include "list_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>


using namespace std;

int main() {
	stringstream ss;
	time_t now;
	listMap < string, cache_element> myMap;

	for(int i = 20; i >= 0 ; i --) {
		time(&now);
		cout<< asctime(localtime(&now)) << endl;
		cache_element ca(now, i);
		ss << i;
		myMap.addToTail(ss.str(), ca);
		ss.str("");
		sleep(2);
	}

	for(int i = 0; i < 20 ; i ++) {
		string p = myMap.getByIndex(i);
		cout<< P << endl;
	}






	printf("It is ok \n");
	return 0;
}