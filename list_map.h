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
	void addToFront(const T& key, const C& value);
	void addToTail(const T& key, const C& value);
	void orderedAdd(const T& key, C& value);

	// void erase(T key);
	bool contains(T key);
	C evict_eldest();
	C getByIndex(int index);
	C getByKey(T key);
private:
	list< pair<T, C> > orderedList;
	map< T, typename list< pair<T, C> >::iterator >lookupMap;
	typename list< pair<T, C> >::iterator findPosition(C& value);
	
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
	// lookupMap.clear();
	// orderedList.clear();
}

/*
	add item to the fron of the list	
*/
template < class T, class C >
void listMap<T, C>:: addToFront(const T& key, const C& value) {
	class map< T, typename list< pair<T, C> >::iterator >:: iterator it;
	it = lookupMap.find(key);
	if( it != lookupMap.end()) {
		orderedList.erase(it->second);
		lookupMap.erase(it);
	}
	orderedList.push_front(make_pair(key, value));
	lookupMap.insert(make_pair(key, orderedList.begin())); 
}

/*
	add item to the tail of the list	
*/
template < class T, class C >
void listMap<T, C>:: addToTail(const T& key, const C& value) {
	class map< T, typename list< pair<T, C> >::iterator >:: iterator it;
	it = lookupMap.find(key);
	if( it != lookupMap.end()) {
		orderedList.erase(it->second);
		lookupMap.erase(it);
	}
	orderedList.push_back(make_pair(key, value));
	lookupMap.insert(make_pair(key, --orderedList.end())); 
}

/*
	find correct position to put/re-put item
	based user define ">"
*/
template <class T, class C>
typename list< pair<T, C> >::iterator listMap<T, C>::findPosition(C& value) {
	typename list< pair<T, C> >::iterator it;
	for(it = orderedList.begin(); it != orderedList.end(); it++) {
		if( value > it->second) {
			return it;
		}
	}
	return orderedList.begin();
}

/*
	add item to the pre-defined position
*/
template < class T, class C >
void listMap<T, C>:: orderedAdd(const T& key, C& value) {
	class map< T, typename list< pair<T, C> >::iterator >:: iterator it;
	it = lookupMap.find(key);
	if( it != lookupMap.end()) {
		orderedList.erase(it->second);
		lookupMap.erase(it);
	}
	typename list< pair<T, C> >::iterator it2;
	it2 = findPosition(value);
	it2 = orderedList.insert(it2, make_pair(key, value));
	lookupMap.insert(make_pair(key, it2));
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

/*
	get item by its key, and put it to the 
	front of the list
*/
template <class T, class C>
C listMap<T, C>::getByKey(T key) {
	class map< T, typename list< pair<T, C> >::iterator >:: iterator it;
	it = lookupMap.find(key);

	// here need to somehow reset the timestamp ?
	orderedList.splice( orderedList.begin(), orderedList, it->second);
	 return it->second->second;
}

/*
	evict an item from the tail of the list
*/
template <class T, class C>
C listMap<T, C>::evict_eldest() {
	typename list< pair<T, C> >::iterator it;
	it = orderedList.back();
	orderedList.pop_back();
	lookupMap.erase(it);
	return it->second;
}

/*
	this is for test purpose
*/
template <class T, class C>
C listMap<T, C>::getByIndex(int index) {
	class list< pair<T, C> >::iterator it;
	it = orderedList.begin();
	for(int i = 0 ; i < index; i ++) {
		it ++;
	}
	return it->second;
}

// /*
// 	erase item
// */
// template <class T, class C>
// void listMap<T, C>::erase(T key) {
// 	// need to deal with the list
// 	C value = lookupMap[key];
// 	lookupMap.erase(key);
// 	delete value;
// }
#endif