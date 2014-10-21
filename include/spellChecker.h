#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
#include <string>

class Node {
    public:
        Node();
        ~Node();
        void changeStoredCharacter(char);
        char returnStoredCharacter();
        Node * returnPointer(char);
        void setPointer(char,Node*);
    protected:
    private:
        char storedCharacter;
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
    protected:
    private:
        Node * headNode;
        Node * beforeSpellError;

};

#endif // SPELLCHECKER_H
