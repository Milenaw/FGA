/* 
 * File:   ElementWrapper.h
 * Author: benjamin
 *
 * Created on September 23, 2015, 5:43 PM
 */

#ifndef ELEMENTWRAPPER_H
#define	ELEMENTWRAPPER_H

class ElementWrapper {
public:
    ElementWrapper();
    ElementWrapper(const ElementWrapper& orig);
    virtual ~ElementWrapper();
    bool operator==(const ElementWrapper& secound) const;
    ElementWrapper& operator+(const ElementWrapper& secound) const;
    
private:

};

#endif	/* ELEMENTWRAPPER_H */

