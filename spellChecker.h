#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Node {
    public:
        Node();
        ~Node();
        void changeStoredCharacter(char);
        char returnStoredCharacter();
        Node * returnPointer(char);
        void setPointer(char,Node*);
        bool returnWordCompleted();
        void setWordCompleted(bool);
    protected:
    private:
        char storedCharacter;
        bool wordCompleted;
        //Holds pointer to 26 letters
        Node * pointerArray[26];

};


class spellChecker
{
    public:
        spellChecker();
        virtual ~spellChecker();
        void execute();
        bool compileDictionary();
        void checkWord(std::string);
        void cleanUpNodes(Node *);
    protected:
    private:
        Node * headNode;
        Node * beforeSpellError;

};

#endif // SPELLCHECKER_H
