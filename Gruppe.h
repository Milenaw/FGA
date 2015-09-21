/*
 * File:   Gruppe.h
 * Author: benjamin
 *
 * Created on September 7, 2015, 9:11 PM
 */

#ifndef GRUPPE_H
#define	GRUPPE_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Element;

class Gruppe {
public:
    Gruppe(const std::vector<Element>& elemente);
    bool checkAsso();
    bool checkNeutral();//Prüft nicht selber auf Existens, da dies schon von getE() erledigt wurde
    Element getE();
    bool checkInvers();
    void writeVector(string filename);
    vector<Element> readVector(string filename);

private:
    //Gruppenaxiome: Abgeschlossenheit ist durch den konstruktor schon sichergestellt

    bool asso = false;//assoziativ?
    bool neutral = false;//Gibt es neutrales Element?
    bool inverse = false;//existieren Inverse?

    int order; //Ordnung der Gruppe
    vector<Element> elemente; //Die Elemente der Gruppe
    vector<const Element*> table; //Die Verknüpungstabelle der Gruppe
    vector<int> invers; //Die Inversen
    int I(int first, int secound);
    const Element* verknupfe(const Element* first, const Element* second);
    int getIndexFromElement(const Element& element);
    int e;
};

#endif	/* GRUPPE_H */
