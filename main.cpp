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
    vector<Element> menge;
    for(int i=0; i<5;i++) {
        Element t(i);
        menge.push_back(t);
    }
    try {
        Gruppe gruppe(menge);
        cout << gruppe.getE() << endl;
    } catch (int e) {
        if(e==0) {
            cerr<<"Group creation aborted, since not all group axioms are satisfied. "<<endl;
        } else {
            cerr<<"Unknown error, program terminated!"<<endl;
            exit(1);
        }
    }   
}
