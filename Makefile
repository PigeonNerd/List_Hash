test_list: main.cpp  cache_element.o list_map.h
	g++ -g -Wall main.cpp  cache_element.o -o test_list

cache_element.o: cache_element.cpp cache_element.h
	g++ -g cache_element.cpp -c -o cache_element.o

clean:
	rm *.o test_list
