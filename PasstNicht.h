//
// Created by Aleksejs on 15.01.2019.
//

#ifndef EXERCISE_9_2_ALEKSEJS_MARMISS_PASSTNICHT_H
#define EXERCISE_9_2_ALEKSEJS_MARMISS_PASSTNICHT_H

#include <map>
using namespace std;
/**
 * \class PasstNicht
 *
 * \brief A class that implements a "which word doesn't fit" exercise
 *
 * @author Aleksejs Marmiss
 * @date 16.01.2019
 * @version 1.0
*/
class PasstNicht {
private:
/**
 * multimap which contains questions(another multimap which contains a set of words with values representing correctness).
 */
    std::multimap<int, std::multimap<string, int>> *questions;
    /**
 * Constant iterator map<string, int>.
 */
    typedef std::map<string, int>::const_iterator CI;
    /**
 * Constant iterator multimap<int, std::multimap<string, int>>.
 */
    typedef multimap<int, std::multimap<string, int>>::const_iterator Citer;

public:
    /**
     * Default constructor.
     */
    PasstNicht();
    /**
     * Method that allows to check the number of questions(size of a map).
     * @return size of a map.
     */
    int size() const;
    /**
     * Getter for accessing a question(value of the specific key(index)).
     * @return a map that contains the words
     */
   const multimap<string, int> &getQuestion(int) const;
   /**
    * Method that allows to check if the answer is correct.
    * @param question index(key) of a question.
    * @param position index of the word that was choosen as the answer.
    * @return 1 if the answer is correct and 0 if not.
    */
    int getScore(int question, int position);
    /**
     * Method that allows to access the key(word)
     * @return a word(string) at specified index.
     */
    string getWord(int, int) const;



};


#endif //EXERCISE_9_2_ALEKSEJS_MARMISS_PASSTNICHT_H
