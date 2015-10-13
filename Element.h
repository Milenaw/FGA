/*
 * File:   Element.h
 * Author: benjamin
 * 
 * Klasse die vom User implementiert wird. Wichtig dabei ist ein Vergleichsoperator, der Konstruktor und der Verknüpfungskonstruktor.
 *
 * Created on September 7, 2015, 9:07 PM
 */

#ifndef ELEMENT_H
#define    ELEMENT_H

#include <vector>
#include <string>

using namespace std;

class Gruppe;

class Element {
public:
    Element(int number); //Der Konstruktor, wird vom Benutzer definiert und implementiert

    Element(const Element& first, const Element& secound); //Konstruktor aus der Verknüpfung

    bool operator==(const Element& secound) const; //Vergleichsoperator

    string toString(void) const; // Für die Ausgabe

    Element(string string); //Deserialisieren

    string serialize(); //Serialisieren (kann toString benutzen, aber auch unabhängig implementiert werden, wenn toString nicht alle informationen enthält)

private:
    int number; //Stellt die Restklasse da
};

#endif	/* ELEMENT_H */

