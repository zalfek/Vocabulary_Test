/**
@mainpage



@author Aleksejs Marmiss
@date 16.01.2019
@version 1.0
*/


#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Vocabulary.h"
#include "Prapositionen.h"
#include "PasstNicht.h"

using namespace std;

bool isCorrect(const std::pair<const std::__cxx11::basic_string<char>,int> value) {
    return value.second==1;
}


int main() {
    std::clock_t start;
    double duration;

    cout<< "Welcome to the Vocabulary Quiz!!! "<<endl;
    cout<< "In this quiz, you will be asked 12 questions. You should type in the answer in the way its mentioned in the task description."<<endl;
    cout<< "Quiz consists of 3 Modules: "<<endl;
    cout<< "1)Translation"<<endl;
    cout<< "2)Prepositions"<<endl;
    cout<< "3)Which word doesn't fit"<<endl;
    cout<< " Each module consists of 4 questions."<<endl;
    cout<< "The score depends on the duration of the test and on the number of correctly answered questions."<<endl;
    cout<< "The lower is coefficient the better."<<endl;
    cout<< "Please press enter twice when you will be ready"<<endl;

    std::cin.sync();
    std::cin.get();
    start = std::clock();
    int score = 0;
    //Create a new vocabulary.
    auto * a = new Vocabulary();
    string answer;
    srand(time(NULL));
    //Loop which produces 4 questions and checks the answer.
    for (unsigned int i = 0; i < 4; ++i) {
        std::array<int,5> questions;
        bool unique;
        int random;
        //"Do while" which allows to generate an unique index for each question to avoid duplicate questions.
        do {
            random = rand() % a->size();
            unique = true;
            for (int j = 0; j < questions.size() ; ++j) {
                if(questions[j] == random){
                    unique = false;

                }
            }
        }while(!unique);
        //Save current question to the array of previous questions.
        questions.at(i) = random;
        cout<< "Please translate the following word into English language: "<<a->getWord(random)<<endl;
        cin>>answer;
        //Transformation of the answer to lower case.
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        bool correct = false;
        unsigned int cnt=0;
        //This loop iterate through the vector of translations and check if the given answer exists in the vector
        while (!correct && cnt != a->getTranslation(a->getWord(random)).size()){
            correct = (answer == a->getTranslation(a->getWord(random)).at(cnt));
            cnt++;
        }
        if(correct){
            score++;
            cout<<"Correct! Total score is: "<<score<<endl;
            cout<< "*******************************************************************"<<endl;
        }
        else{
            cout<<"Not correct! The correct answer is: "<<a->getTranslation(a->getWord(random)).at(0)<<endl;
            cout<< "*******************************************************************"<<endl;
        }

    }
    //Creating a new object which contains "preposition" questions.
    auto * b = new Prapositionen();
    for (unsigned int i = 0; i < 4; ++i) {
        std::array<int, 5> questions;
        bool unique;
        int random;
        //"Do while" which allows to generate an unique index for each question to avoid duplicate questions.
        do {
            random = rand() % b->size();
            unique = true;
            for (int j = 0; j < questions.size(); ++j) {
                if (questions[j] == random) {
                    unique = false;

                }
            }
        } while (!unique);
        //Save previously chosed random numbers to array.
        questions.at(i) = random;
        cout << "Please specify the correct preposition for the following verb: " << b->getWord(random) << endl;
        cin >> answer;
        //transform the answer to lowercase.
        std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
        bool correct = false;
        unsigned int cnt = 0;
        //The while loop which checks if the answer is correct.
        while (!correct && cnt < b->size()) {
            auto search = b->getPrepMap()->find(answer);
            correct = (answer == b->getPrep(random));
            cnt++;
        }
        if (correct) {
            score++;
            cout << "Correct! Total score is: " << score << endl;
            cout<< "*******************************************************************"<<endl;
        } else {
            cout<<"Not correct! The correct answer is: "<<b->getPrep(random)<<endl;
            cout<< "*******************************************************************"<<endl;
        }
    }
    //Create an object containing a "which word doesn't fit" questions.
        auto * c = new PasstNicht();
        for (unsigned int i = 0; i < 4; ++i) {
            std::array<int,5> questions;
            bool unique;
            int random;
            //"Do while" which allows to generate an unique index for each question to avoid duplicate questions.
            do {
                random = rand() % c->size();
                unique = true;
                for (int j = 0; j < questions.size() ; ++j) {
                    if(questions[j] == random){
                        unique = false;

                    }
                }
            }while(!unique);
            //Save previously chosed random numbers to array.
            questions.at(i) = random;
            cout<< "Please choose a word which doesn't fit to the set(and enter the number of the word 1/2/3/4):  "<<endl;
            //Print set of words.
            for (int k = 0; k < c->getQuestion(random).size(); ++k) {
                cout<<c->getWord(random,k)<<"/";
            }
            cout<<endl;
            int answer;
            //While loop which checks if the answer is correct.
            while(!(cin>>answer)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }
            //Add a value(in case of correct answer value is 1 otherwise 0) to the score.
            score += c->getScore(random,answer-1);
            if (c->getScore(random,answer-1) == 1){
                cout << "Correct! Total score is: " << score << endl;
                cout<< "*******************************************************************"<<endl;
            }else{
                auto it = std::find_if (c->getQuestion(random).begin(), c->getQuestion(random).end(), isCorrect);
                cout<<"Not correct! The correct answer is: "<<it->first<<endl;
                cout<< "*******************************************************************"<<endl;
            }

    }
    //Calcculate the duration of the test.
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Test is completed. You answered correctly on "<<score<<" questions out of 12"<<endl;
    cout<<"Your time is: "<<duration<<" seconds"<<endl;
    cout<<"Your total score is: "<<duration/score<<endl;
    return 0;
}