/* 
 * File:   Table.cpp
 * Author: benjamin
 * 
 * Created on September 21, 2015, 6:01 PM
 */

#include "Table.h"

Table::Table(unsigned int size):size(size){
    this->table = new Element*[size][size]; //Erstellt die Tabelle im Heap
}

Table::Table(const Table& orig) {
}

Table::~Table() {
    delete[] this->table; //Löscht die Tabelle wieder aus dem heap 
}

