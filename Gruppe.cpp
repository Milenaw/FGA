/*
 * File:   Gruppe.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#include "Gruppe.h"
#include "Element.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Gruppe::Gruppe(const std::vector<Element>& elemente) {
    this->elemente = elemente;
    this->order = this->elemente.size();
    table.resize(order * order);
    for (int first = 0; first < this->order; first++) {
        for (int secound = 0; secound < this->order; secound++) {
            Element result(elemente[first], elemente[secound]);
            int index = getIndexFromElement(result);
            if (index == -1) {
                throw 1;
            }
            const Element* res;
            res=&elemente[0];
            res+=index;
            table[I(first, secound)] = res;
        }
    }
    for (int i=0;i<order;i++) {
    	for (int j=0;j<i;j++) {
    		if(this->elemente[i]==this->elemente[j]) {
    			throw 2;
    		}
    	}
    }
}

void Gruppe::writeVector(string filename) {
	ofstream wout("Gruppe.txt");
	for(unsigned int i=0;i<this->elemente.size();i++) {
		wout<<this->elemente[i].toString()+"\n";
	}
	wout.close();
}
std::vector<Element> readVector(string filename) {
	ifstream win ("Gruppe.txt");
	unsigned int lines;
	string line;
	while (getline(win, line))
		++lines;
	vector<Element> elemente;
	elemente.resize(lines);
	int count=0;
	while (getline(win, line)) {
		elemente[count]=Element(line);
		count++;
	}
	win.close();
	return elemente;
}

int Gruppe::I(int first, int secound) {
    return (first) * (this->order) + secound;
}

const Element* Gruppe::verknupfe(const Element* first, const Element* second) {
	const Element* start=&this->elemente[0];
	const Element reselement=elemente[I(first-start, second-start)];
	return &reselement;
}

int Gruppe::getIndexFromElement(const Element& element) {
    for (int i = 0; i < this->order; i++) {
        if (this->elemente[i] == element) {
            return i;
        }
    }
    return -1;
}

bool Gruppe::checkAsso() { //Prüft die Assoziativität O(n^3)
    for (int a = 0; a < order; a++) {
        for (int b = 0; b < order; b++) {
            for (int c = 0; c < order; c++) {
                if (!((a*b)*c == a*(b*c))) {
                    return false;
                }
            }
        }
    }
    asso = true;
    return true;
}

Element Gruppe::getE() {
    for (int e = 0; e < order; e++) {
        int counter = 0;
        for (int i = 0; i < order; i++) {
            if (table[I(e,i)] == table[I(i,e)] && table[I(i,e)] == table[i]) {
                counter ++;
            }
        }
        if (counter == order) {
            this->e = e;
            this->neutral = true;
            this->neutral=true;
            return elemente[e];
        }
    }
    this->neutral=false;
    return elemente[0];
}

bool Gruppe::checkNeutral() {
	if(this->neutral==true) {
		return true;
	}
	else {
		return false;
	}
}

bool Gruppe::checkInvers() {
    this->invers.resize(order);
    for (int i = 0; i < order; ++i) {
        bool invers = false;
        for (int ii = 0; ii < order; ++ii) {
            if (table[I(i,ii)] == table[e]) {
                invers = true;
                this->invers[i] = ii;
                continue;
            }
        }
        if (!invers) {
            return false;
        }
    }
    this->inverse = true;
    return true;
}