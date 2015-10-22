//
// Created by benjamin on 15.10.15.
//

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Set.h"

using namespace std;
template <class T>
Set<T>::Set(std::vector<T*> elements) {
	for(auto a: elements) {
		if(!this->isElement(a)) {
			this->elements.push_back(a);
		}
	}
}

template <class T>
Set<T>::Set(const Set& origin) {
	this->elements=origin.elements;
}

template <class T>
vector<T*> Set<T>::get() const {
	return this->elements;
}

template <class T>
int Set<T>::order() const {
	return this->elements.size();
}

template <class T>
bool Set<T>::isElement(const T& element) {
	for(auto a:this->elements) {
		if(*a==element) {
			return true;
		}
	}
	return false;
}
template <class T>
bool Set<T>::isSubset(const Set<T>& S) {
	for(auto a: S->elements) {
		if(!this->isElement(a)) {
			return false;
		}
	}
	return true;
}

template <class T>
Set<T> Set<T>::merge(const Set<T>& other) {
	for(auto a : other->elements) {
		if(this->isElement(a)) {
			this->elements.push_back(a);
		}
	}
}

template <class T>
Set<T> Set<T>::intersection(const Set<T>& other) {
	vector<T*> res;
	for(auto a: other->elements) {
		if(this->isElement(a)) {
			res.push_back(a);
		}
	}
	return new Set(res);
}
