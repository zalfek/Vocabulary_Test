//
// Created by Aleksejs on 14.01.2019.
//

#ifndef EXERCISE_9_2_ALEKSEJS_MARMISS_PRAPOSITIONEN_H
#define EXERCISE_9_2_ALEKSEJS_MARMISS_PRAPOSITIONEN_H

#include <map>

using namespace std;

/**
 * \class Prapositionen
 *
 * \brief A class that implements a "specify the correct preposition" exercise
 *
 * @author Aleksejs Marmiss
 * @date 16.01.2019
 * @version 1.0
*/
class Prapositionen {
private:
    /**
 * multimap which contains words as keys and prepositions as a values.
 */
    multimap<string, string> *prepMap;
    /**
* Constant iterator map<string, string>.
*/
    typedef std::map<string, string>::const_iterator CI;
public:
    /**
 * Default constructor
 */
    Prapositionen();
    /**
    * Method that allows to check the number words(keys) in the map.
    * @return size of a map.
    */
    int size() const;
    /**
 * Getter for accessing a word(key).
 * @return a word(key) as a string.
 */
    string getWord(unsigned int position) const;
    /**
 * Getter for accessing a map.
 * @return a map that contains the words and prepositions.
 */
    multimap<string, string> *getPrepMap() const;
    /**
 * Getter for accessing a preposition(value) of the given word.
 * @return preposition(value) as a string.
 */
    string getPrep(unsigned int position) const;

};


#endif //EXERCISE_9_2_ALEKSEJS_MARMISS_PRAPOSITIONEN_H
