#ifndef __CACHE_ELEMENT_H
#define __CACHE_ELEMENT_H
#include "list_map.h"
#include <time.h>
using namespace std;

extern const int LIKELY_RANGE;
class cache_element {
public:
	cache_element();
	cache_element(time_t access, unsigned long size);
	time_t get_access();
	unsigned long get_size();
	void set_access(time_t access);
	void set_size(unsigned long size);
	bool operator > (cache_element);
private:
	time_t access;
	unsigned long size;
};
#endif