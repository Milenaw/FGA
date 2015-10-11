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

Gruppe::Gruppe(std::vector<Element>& elemente) {
    for(auto a: elemente) {
        this->addElement(a);
    }
    if(!this->create()) {
        std::cerr<<"Nicht abgeschlossen"<<std::endl; //endl, do a flush on the console, while \n just do a new line
        return;
    }
    if(!this->checkNeutral()) {
        std::cerr<<"Kein neutrales Element"<<std::endl;
        return;
    }
    if(!this->checkAsso()) {
        std::cerr<<"Nicht assoziativ"<<std::endl;
        return;
    }
    if(!this->checkInvers()) {
        std::cerr<<"Es existieren nicht für alle Elemente inverse"<<std::endl;
        return;
    }
    std::cout<<"Gruppe wurde erfolgreich erstellt"<<std::endl;
}

void Gruppe::addElement(const Element& element) {
    for(auto& a: elemente) {
	if(a == element) {
            std::clog<<"Mehrfaches Element ignoriert"<<std::endl;
            return;
        }
    }
    EW add(element, order);
    this->elemente.push_back(add);
    order++;
}

bool Gruppe::create() {
    for (int i = 0; i < elemente.size();++i) {
        if (!elemente[i].calculate(&elemente)) {
            closure=false;
            return false;;
        }
    }
    closure=true;
    return true;
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

bool Gruppe::checkNeutral() {
    for (auto& e : elemente) { //Über alle Elemente iterieren, die neutral sein könnten
        bool t = true;
        for (auto& a : elemente) { //Prüfen ob e neutral ist
            if (!(e+a == a && a + e == a)) { //e ist nicht neutral
                t = false;
                break;
            }
        }
        if (t) {
            neutral = true;
            this->e = &e;
            return true;
        }
    }
    return false;
}

string Gruppe::getE() {
    if(!neutral) {
        if(!this->checkNeutral()) {
            throw 1;
        }
    }
    string r = e->toString();
    return r;
}

bool Gruppe::checkInvers() {
	for(auto& a : elemente) {//suche nach dem Inversen von a
		bool test=false;
		for(auto& b : elemente) {
			if(a+b==*(this->e))
				a.inverse=b.inverse;
				test=true;
		}
		if(!test)
			return false;
	}
	return true;
}
