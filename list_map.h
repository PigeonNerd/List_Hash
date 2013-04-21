#ifndef __LIST_MAP_H
#define __LIST_MAP_H
#include <map>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
template < class T, class C >
class listMap{
public:
	listMap();
	~listMap();
	void orderedInsert(T key, C& value);
	void addToFront(T key, C& value);
	void addToTail(T key, C& value);
	void erase(T key);
	bool contains(T key);
	C evict_eldest();
	T getByIndex(int index);
	T getByKey(T key);
private:
	map<T, C>lookupMap;
	list<T>orderedList;
};


#define DEFAULT_SIZE 100

/*
	constructor of list map
*/
template < class T, class C >
listMap<T, C>::listMap() {}

/*
	destructor of list map
*/
template < class T, class C >
listMap<T, C>::~listMap() {
	lookupMap.clear();
	orderedList.clear();
}

/*
	insert item as pre-defined order
*/
template <class T, class C>
void listMap<T, C>::orderedInsert(T key, C& value) {
	lookupMap[key] = value;
	class list <C>::iterator it;
	for (it = orderedList.begin(); it != orderedList.end(); it++ ) {
		// the operator is defined in C class
		if( value > (*it)) {
			orderedList.insert(it, value);
			break;
		}
	}
	orderedList.push_back( value );
}

/*
	add item to the fron of the list	
*/
template <class T, class C>
void listMap<T, C>::addToFront(T key, C& value) {
	lookupMap[key] = value;
	orderedList.push_front( key );
}

/*
	add item to the tail of the list	
*/
template <class T, class C>
void listMap<T, C>::addToTail(T key, C& value) {
	lookupMap[key] = value;
	orderedList.push_back( key );
}

/*
	erase item
*/
template <class T, class C>
void listMap<T, C>::erase(T key) {
	// need to deal with the list
	C value = lookupMap[key];
	lookupMap.erase(key);
	delete value;
}

/*
	test if the map contains the item
*/
template <class T, class C>
bool listMap<T, C>::contains(T key) {
	if(lookupMap.find(key) != lookupMap.end()) {
		return true;
	}
	return false;
}

// right now, it is assumed that the list contains T 
template <class T, class C>
C listMap<T, C>::evict_eldest() {
	C ret = orderedList.front();
	lookupMap.erase(ret);
	orderedList.pop_front();
	return ret;
}

template <class T, class C>
T listMap<T, C>::getByIndex(int index) {
	class list<T>::iterator it;
	it = orderedList.begin();
	for(int i = 0 ; i < index; i ++) {
		it ++;
	}
	return *it;
}

template <class T, class C>
T listMap<T, C>::getByKey(T key) {
	
	return lookupMap[key];
}
#endif