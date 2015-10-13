/* 
 * File:   ElementWrapper.h
 * Author: benjamin
 *
 * Created on September 23, 2015, 5:43 PM
 */

#ifndef ELEMENTWRAPPER_H
#define    ELEMENTWRAPPER_H

#include "Element.h"

class ElementWrapper {
public:
    ElementWrapper(const Element& element, int id);

    ElementWrapper(const ElementWrapper& orig);

    ElementWrapper(const string& strid);

    virtual ~ElementWrapper();

    bool operator==(const ElementWrapper& second) const;

    bool operator==(const Element& second) const;

    string toString() const;

    const ElementWrapper& operator+(const ElementWrapper& second) const;

    const ElementWrapper* operator+(const ElementWrapper* second) const;

    const ElementWrapper& operator-(const ElementWrapper& second) const;

    const ElementWrapper* operator-(const ElementWrapper* second) const;

    int getId();

    bool calculate(const std::vector<ElementWrapper>* alle);

    void setInverse(ElementWrapper& inverse);

    ElementWrapper& getInverse() const;

    int calcOrder(ElementWrapper& e);

private:
    int id = -1;
    int order = -1;
    Element element; //Hier ist das Element drin, alles andere verweist auf diese Speicherstelle
    ElementWrapper* inverse;
    std::vector<const ElementWrapper*> links;
};

typedef ElementWrapper EW;

#endif	/* ELEMENTWRAPPER_H */

