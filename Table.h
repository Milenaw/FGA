/* 
 * File:   Table.h
 * Author: benjamin
 *
 * Created on September 21, 2015, 6:01 PM
 * 
 * Diese Klasse stellt die Verknüpfungstabelle da, sie verwaltet ein 2 dimensionales array mit pointers auf die Elemente
 * 
 */

#ifndef TABLE_H
#define	TABLE_H

#include "Element.h"

class Table {
public:
    Table(unsigned int size);
    Table(const Table& orig);
    virtual ~Table();
private:
    Element* table; //Das Array
    unsigned int size; //Die Ordnung der Gruppe, ist wichtig um das 2 dimensionale array zu verwalten
};

#endif	/* TABLE_H */

