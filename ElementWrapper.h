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
    ElementWrapper(const Element& element, int id);
    ElementWrapper(const ElementWrapper& orig);
    ElementWrapper(const string& strid);
    virtual ~ElementWrapper();
    bool operator==(const ElementWrapper& second) const;
    bool operator==(const Element& second) const;
    ElementWrapper& operator=(const ElementWrapper& left);
    string toString() const;
    const ElementWrapper& operator+(const ElementWrapper& second) const;
    const ElementWrapper& operator-(const ElementWrapper& second) const;
    int getId();
    bool calculate(const std::vector<ElementWrapper>* alle);
    int id=-1;
    int inverse=-1;
private:
    Element element; //Hier ist das Element drin, alles andere verweist auf diese Speicherstelle
    std::vector<const ElementWrapper*> links;
};

typedef ElementWrapper EW;

#endif	/* ELEMENTWRAPPER_H */

