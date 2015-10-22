//
// Created by benjamin on 15.10.15.
//

#include "Set.h"



template <int ORDER> Set<ORDER>::Set(std::vector<EW>* all) {
    this->bitset.reset();
    this->all = all;
}

template <int ORDER> Set<ORDER>::Set(const Set& origin) {
    this->bitset = origin.bitset;
    this->all = origin.all;
}

template <int ORDER> Set<ORDER> Set<ORDER>::merge(const Set& other) const {
    Set<ORDER> set(all);
    set.bitset = this->bitset |= other.bitset;
    return set;
}

template <int ORDER> Set<ORDER> Set<ORDER>::intersection(const Set& other) const {
    Set<ORDER> set(all);
    set.bitset = this->bitset &= other.bitset;
    return set;
}

template <int ORDER> std::vector<EW*> Set<ORDER>::get() const {
    std::vector<EW*> result;
    for (int i = 0 ; i < ORDER ; ++i) {
        if (bitset[i] == 1) {
            result.push_back(&(all->at(i)));
        }
    }
}

template <int ORDER> void Set<ORDER>::add(EW* element) {
    bitset[element->getId()] = 1;
}