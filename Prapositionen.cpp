//
// Created by Aleksejs on 14.01.2019.
//

#include "Prapositionen.h"

Prapositionen::Prapositionen(){

    this->prepMap = new multimap<string,string>();
    prepMap->insert({"abhaengen", "von"});
    prepMap->insert({"absehen", "von"});
    prepMap->insert({"achten", "auf"});
    prepMap->insert({"beruhen", "auf"});
    prepMap->insert({"aufhoeren", "mit"});
    prepMap->insert({"denken", "an"});
    prepMap->insert({"hoffen", "auf"});
    prepMap->insert({"sich aergern", "uber"});
    prepMap->insert({"sich erinern", "an"});
    prepMap->insert({"sich kuemmern", "um"});
    prepMap->insert({"sich distanzieren", "von"});
    }

int Prapositionen::size() const {
    return this->prepMap->size();
}

multimap<string, string> *Prapositionen::getPrepMap() const {
    return prepMap;
}

string Prapositionen::getWord(unsigned int position) const {

    CI i = prepMap->begin();
    for (int j = 0; j < position; ++j) {
        i++;
    }
    return i->first;
}
string Prapositionen::getPrep(unsigned int position) const {

    CI i = prepMap->begin();
    for (int j = 0; j < position; ++j) {
        i++;
    }
    return i->second;
}