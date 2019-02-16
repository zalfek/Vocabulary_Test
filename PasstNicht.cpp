//
// Created by Aleksejs on 15.01.2019.
//

#include "PasstNicht.h"

PasstNicht::PasstNicht() {
this->questions = new multimap<int, std::multimap<string, int>>;
    auto *words = new multimap<string, int>;
    words->insert(make_pair("Hammer",0));
    words->insert(make_pair("Mixer",1));
    words->insert(make_pair("Zange",0));
    words->insert(make_pair("Schraubenzieher",0));
this->questions->insert(make_pair(1,*words));

    auto *words1 = new multimap<string, int>;
    words1->insert(make_pair("Kochloeffel",0));
    words1->insert(make_pair("Schuessel",0));
    words1->insert(make_pair("Scaelter",0));
    words1->insert(make_pair("Meterstab",1));
    this->questions->insert(make_pair(2,*words1));

    auto *words2 = new multimap<string, int>;
    words2->insert(make_pair("Maler",0));
    words2->insert(make_pair("Elektriker",0));
    words2->insert(make_pair("Mechaniker",0));
    words2->insert(make_pair("Arzt",1));
    this->questions->insert(make_pair(3,*words2));

    auto *words3 = new multimap<string, int>;
    words3->insert(make_pair("bohren",0));
    words3->insert(make_pair("telefonieren",1));
    words3->insert(make_pair("schneiden",0));
    words3->insert(make_pair("reparieren",0));
    this->questions->insert(make_pair(4,*words3));

    auto *words4 = new multimap<string, int>;
    words4->insert(make_pair("schaelen",0));
    words4->insert(make_pair("ruhren",0));
    words4->insert(make_pair("streichen",1));
    words4->insert(make_pair("mischen",0));
    this->questions->insert(make_pair(5,*words4));

    auto *words5 = new multimap<string, int>;
    words5->insert(make_pair("Zutat",1));
    words5->insert(make_pair("Farbe",0));
    words5->insert(make_pair("Pinsel",0));
    words5->insert(make_pair("Leiter",0));
    this->questions->insert(make_pair(6,*words5));

    auto *words6 = new multimap<string, int>;
    words6->insert(make_pair("Schwamm",0));
    words6->insert(make_pair("Kuechentuch",0));
    words6->insert(make_pair("Eimer",0));
    words6->insert(make_pair("Nagel",1));
    this->questions->insert(make_pair(7,*words6));
}

const multimap<string, int> &PasstNicht::getQuestion(int position) const {
    Citer i = this->questions->begin();
    for (int j = 0; j < position; ++j) {
        i++;
    }
    return i->second;
}

 string PasstNicht::getWord(int question, int position) const {
    CI i = this->getQuestion(question).begin();
     for (int j = 0; j < position; ++j) {
         i++;
     }
    return i->first ;
}

int PasstNicht::getScore(int question, int position){
    CI i = this->getQuestion(question).begin();
    for (int j = 0; j < position; ++j) {
        i++;
    }
    return i->second ;
}

int PasstNicht::size() const {
    return this->questions->size();
}


