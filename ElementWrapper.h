/* 
 * File:   ElementWrapper.h
 * Author: benjamin
 *
 * Created on September 23, 2015, 5:43 PM
 */

#ifndef ELEMENTWRAPPER_H
#define	ELEMENTWRAPPER_H

#include "Element.h"

class ElementWrapper {
public:
    ElementWrapper(Element& element);
    ElementWrapper(const ElementWrapper& orig);
    virtual ~ElementWrapper();
    bool operator==(const ElementWrapper& secound) const;
    ElementWrapper& operator+(const ElementWrapper& secound) const;
    int getId();
private:
    Element element; //Hier ist das Element drin, alles andere verweist auf diese Speicherstelle
};

#endif	/* ELEMENTWRAPPER_H */

