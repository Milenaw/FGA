//
// Created by benjamin on 15.10.15.
//

#include "Set.h"

Set::Set(int order, std::vector<EW>* all) : order(order), all(all), bitset(order) {
}

Set::~Set() {

}

Set::Set(const Set& origin) {
    this->bitset = origin.bitset;
    this->all = origin.all;
}

Set Set::merge(const Set& other) const {
    Set set(order, all);
    set.bitset = this->bitset | other.bitset;
    return set;
}

Set Set::intersection(const Set& other) const {
    Set set(order, all);
    set.bitset = this->bitset & other.bitset;
    return set;
}

std::vector<EW*> Set::get() const {
    std::vector<EW*> result;
    for (int i = 0 ; i < order ; ++i) {
        if (bitset[i] == 1) {
            result.push_back(&(all->at(i)));
        }
    }
}

void Set::add(EW* element) {
    bitset[element->getId()] = 1;
}