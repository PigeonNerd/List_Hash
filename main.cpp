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
	time(&now);

	listMap<string, cache_element> myMap;

	for(int i = 0 ; i < 20; i ++) {
		ss << i;
		time(&now);
		cache_element ca( now, i);
		myMap.orderedAdd(ss.str(), ca);
		ss.str("");
		sleep(2);
	}


	for(int i = 0; i < 20 ; i ++) {

		cache_element ca2 = myMap.getByIndex(i);
		cout << "time: "<< ca2.get_access() << ", " << ca2.get_size() << endl;
	}


	return 0;
}