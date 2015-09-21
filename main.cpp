/*
 * File:   main.cpp
 * Author: benjamin
 *
 * Created on September 7, 2015, 8:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Gruppe.h"
#include "Element.h"

using namespace std;

int main(int argc, char** argv) {
    try {
        Gruppe gruppe(Element::getElements());
        bool asso = gruppe.checkAsso();
        gruppe.getE();
        bool invers = gruppe.checkInvers();
        bool neutral = gruppe.checkNeutral();
        if (asso && invers && neutral) {
            cout<< "Die Gruppe wurde erfolgreich erstellt" << endl;
            cout<< "Gebe einen Dateinamen zum Speichern an:" << endl;
            string datei;
            cin >> datei;
            cout<< "Gruppe wurde erfolgreich gespeichert" << endl;
        }
    } catch (int e) {
        if (e == 1) {
            cerr << "Die Gruppe ist nicht abgeschlossen" << endl;
            return 0;
        } else if (e==2) {
                    cerr << "Gruppe enthält gleiche Elemente" << endl;
        } else {
            cerr << "Unbekannter Fehler" << endl;
        }
    }
}