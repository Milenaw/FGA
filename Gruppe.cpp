/*
 * File:   Gruppe.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#include "Gruppe.h"
#include "ElementWrapper.h"

Gruppe::Gruppe() {
    
}

Gruppe::Gruppe(std::vector<const Element&> elemente) {
	for(auto& a: elemente)
		this->addElement(a);
	if(!this->create())
		std::cerr<<"Nicht abgeschlossen\n"
	this->getE();
	if(!this->neutral)
		std::cerr<<"Kein neutrales Element\n"
	if(!this->checkAsso())
		std::cerr<<"Nicht assoziativ\n"
	if(!this->checkInvers())
		std::cerr<<"Es existieren nicht für alle Elemente inverse"
}

void Gruppe::addElement(const Element& element) {
	for(auto& a: elemente) {
		if(element==a) {
			std::clog<<"Mehrfaches Element ignoriert";
			return;
		}
	}
    EW add(element, order);
    this->elemente.push_back(add);
    order++;
}

void Gruppe::create() {
    for (int i = 0; i < elemente.size();++i) {
        if (!elemente[i].calculate(&elemente)) {
            closure=false;
            return;
        }
    }
    closure=true;
}

bool Gruppe::checkAsso() {
    for (auto& a : elemente) {
        for (auto& b : elemente) {
            for (auto& c : elemente) {
                if (!((a+b)+c == a +(b+c))) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Gruppe::getE() {
	for(auto& a : elemente) {
		int count=0;
		for(auto& b : elemente){
			if(a==a+b) {
				count++;
			}
		}
		if(count==this->order) {
			this->e=a;
			return true;
		}
	}
	return false;
}

bool Gruppe::checkInvers() {
	for(auto& a : elemente) {
		bool test=false;
		for(auto& b : elemente) {
			if(a+b==this->e)
				test=true;
		}
		if(test==false)
			return false;
	}
	return true;
}
