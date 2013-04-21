#include "cache_element.h"
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int LIKELY_RANGE = 3;


cache_element::cache_element(){}

cache_element::cache_element(time_t access, unsigned long size) {
	this->access = access;
	this->size = size;
}

/*
	get the access time
*/
time_t cache_element::get_access() {
	return access;
}

/*
	set the acces time
*/
void cache_element::set_access(time_t access) {
	access = access;
}

/*
	get the file size
*/
unsigned long cache_element::get_size() {
	return size;
}

/*
	set the size of the element
*/
void cache_element::set_size(unsigned long size) {
	size = size;
}

/*
	implement the ">" operator
*/
bool cache_element::operator > (cache_element e) {
	if( difftime(access, e.get_access() ) > LIKELY_RANGE ) {
		return true;
	} 
	else if( size > e.get_size()) {
		return false;
	} else {
		return true;
	}
	return false;
}