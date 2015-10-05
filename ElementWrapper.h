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
    ElementWrapper(Element& element, int id);
    ElementWrapper(const ElementWrapper& orig);
    virtual ~ElementWrapper();
    bool operator==(const ElementWrapper& secound) const;
    ElementWrapper* operator+(const ElementWrapper& secound) const;
    int getId();
    void calculate(const std::vector<ElementWrapper>* alle);
private:
    Element element; //Hier ist das Element drin, alles andere verweist auf diese Speicherstelle
    std::vector<ElementWrapper> links;
};

typedef ElementWrapper EW;

#endif	/* ELEMENTWRAPPER_H */

