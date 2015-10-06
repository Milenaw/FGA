/* 
 * File:   ElementWrapper.h
 * Author: benjamin
 *
 * Created on September 23, 2015, 5:43 PM
 */

#ifndef ELEMENTWRAPPER_H
#define	ELEMENTWRAPPER_H

#include "Element.h"
#include <string>

class ElementWrapper {
public:
    ElementWrapper(const Element& element, int id);
    ElementWrapper(const ElementWrapper& orig);
    virtual ~ElementWrapper();
    bool operator==(const ElementWrapper& secound) const;
    ElementWrapper& operator=(const ElementWrapper& left);
    const ElementWrapper& operator+(const ElementWrapper& secound) const;
    string toString() const;
    int getId();
    bool calculate(const std::vector<ElementWrapper>* alle);
private:
    int id;
    Element element; //Hier ist das Element drin, alles andere verweist auf diese Speicherstelle
    std::vector<const ElementWrapper*> links;
};

typedef ElementWrapper EW;

#endif	/* ELEMENTWRAPPER_H */

