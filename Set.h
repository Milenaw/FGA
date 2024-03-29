//
// Created by benjamin on 15.10.15.
//

#ifndef FGA_SET_H
#define FGA_SET_H
#include <vector>

template <class T>
class Set {
public:
	Set();
    Set(std::vector<T*>& elements);
    Set(const Set<T>& origin);

    void addElement(const T& element);
    bool isElement(const T& element);
    bool isSubset(const Set& S);
    bool elementOfSubset(const Set<Set>& S);
    Set merge(const Set& other);
    Set intersection(const Set& other);
    std::vector<T*> get() const;
    int order() const; //Number of elements in the set
    const Set<T>& operator=(const Set& other);
    bool operator==(const Set& second);
private:
    std::vector<T*> elements; //Pointer to the original Elements
};


#endif //FGA_SET_H
