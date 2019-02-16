//
// Created by Aleksejs on 13.01.2019.
//

#ifndef EXERCISE_9_2_ALEKSEJS_MARMISS_VOCABULARY_H
#define EXERCISE_9_2_ALEKSEJS_MARMISS_VOCABULARY_H
using namespace std;

#include <map>
#include <vector>

/**
 * \class Vocabulary
 *
 * \brief A class that implements a Vocabulary.
 *
 * @author Aleksejs Marmiss
 * @date 16.01.2019
 * @version 1.0
*/
class Vocabulary {
private:
    /**
* multimap which contains words as keys and vector with translations as a values.
*/
    multimap<string, vector<string>> *map;
    /**
* Constant iterator map<string, vector<string>>.
*/
    typedef std::map<string, vector<string>>::const_iterator CI;
public:
    /**
* Default constructor
*/
    Vocabulary();
    /**
    * Method that allows to check the number of words in the map.
    * @return size of a map.
    */
    unsigned int size() const;
    /**
* Getter for accessing a word(key).
* @return a word(key) as a string.
*/
    string getWord(unsigned int position) const;
    /**
* Getter for accessing the vector with translations(value).
* @return a vector<string>.
*/
    vector<string>  getTranslation(string word) const;
};


#endif //EXERCISE_9_2_ALEKSEJS_MARMISS_VOCABULARY_H
