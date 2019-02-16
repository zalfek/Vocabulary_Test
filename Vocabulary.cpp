//
// Created by Aleksejs on 13.01.2019.
//

#include "Vocabulary.h"
Vocabulary::Vocabulary(){

    this->map = new std::multimap<string, vector<string>>();

    map->insert({"sich", {"oneself", "himself","itself","themselves","yourself"}});
    map->insert({"Zuhause", {"home"}});
    map->insert({"schon", {"already","just","yet","indeed","surely"}});
    map->insert({"dann", {"then", "after that"}});
    map->insert({"immer", {"always"}});
    map->insert({"etwas", {"some","something", "any","somewhat", "slightly", "a little", "a bit", "something" }});

}
    unsigned int Vocabulary::size() const {
        return  this->map->size();
}

string Vocabulary::getWord(unsigned int position) const {

    CI i = map->begin();
    for (int j = 0; j < position; ++j) {
        i++;
    }
    return i->first;
}

vector<string> Vocabulary::getTranslation(const string word) const{
    CI i = map->find(word);
    return  i->second;
}

