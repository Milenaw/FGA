/*
 * File:   Element.h
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:07 PM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H

#include <vector>
#include <string>

using namespace std;

class Element {
public:
	int number;			//Wäre cool wenn wir hieraus eine Template-Klase machen würden, und dies dann beliebigen Typ hat
	Element();
    Element(int number);
    Element(const Element& first,const Element& secound); //Konstruktor aus der Verknüpfung
    bool operator==(const Element& secound); //Vergleichsoperator
    Element operator*(const Element& secound);
    static vector<Element> getElements();
    string toString(void);
    Element(string string);
private:

};

#endif	/* ELEMENT_H */

