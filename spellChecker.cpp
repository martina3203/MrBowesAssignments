#include "spellChecker.h"

Node::Node()
{
    storedCharacter = ' ';
    wordCompleted = false;
    //Set all the pointers to NULL
    for (int i = 0; i < 26; i++)
    {
        pointerArray[i] = NULL;
    }
}

Node::~Node()
{

}

void Node::changeStoredCharacter(char input)
{
    storedCharacter = input;
}

char Node::returnStoredCharacter()
{
    return storedCharacter;
}

Node * Node::returnPointer(char selectedCharacter)
{
    switch(selectedCharacter)
    {
        case 'A':
        case 'a':
            return pointerArray[0];
        case 'B':
        case 'b':
            return pointerArray[1];
        case 'C':
        case 'c':
            return pointerArray[2];
        case 'D':
        case 'd':
            return pointerArray[3];
        case 'E':
        case 'e':
            return pointerArray[4];
        case 'F':
        case 'f':
            return pointerArray[5];
        case 'G':
        case 'g':
            return pointerArray[6];
        case 'H':
        case 'h':
            return pointerArray[7];
        case 'I':
        case 'i':
            return pointerArray[8];
        case 'J':
        case 'j':
            return pointerArray[9];
        case 'K':
        case 'k':
            return pointerArray[10];
        case 'L':
        case 'l':
            return pointerArray[11];
        case 'M':
        case 'm':
            return pointerArray[12];
        case 'N':
        case 'n':
            return pointerArray[13];
        case 'O':
        case 'o':
            return pointerArray[14];
        case 'P':
        case 'p':
            return pointerArray[15];
        case 'Q':
        case 'q':
            return pointerArray[16];
        case 'R':
        case 'r':
            return pointerArray[17];
        case 'S':
        case 's':
            return pointerArray[18];
        case 'T':
        case 't':
            return pointerArray[19];
        case 'U':
        case 'u':
            return pointerArray[20];
        case 'V':
        case 'v':
            return pointerArray[21];
        case 'W':
        case 'w':
            return pointerArray[22];
        case 'X':
        case 'x':
            return pointerArray[23];
        case 'Y':
        case 'y':
            return pointerArray[24];
        case 'Z':
        case 'z':
            return pointerArray[25];
        default:
            std::cout << "Error unrecognized character " << selectedCharacter << std::endl;
            return NULL;
    }
}

void Node::setPointer(char input,Node * newPointer)
{
    switch(input)
    {
        case 'A':
        case 'a':
            pointerArray[0] = newPointer;
            return;
        case 'B':
        case 'b':
            pointerArray[1] = newPointer;
            return;
        case 'C':
        case 'c':
            pointerArray[2] = newPointer;
            return;
        case 'D':
        case 'd':
            pointerArray[3] = newPointer;
            return;
        case 'E':
        case 'e':
            pointerArray[4] = newPointer;
            return;
        case 'F':
        case 'f':
            pointerArray[5] = newPointer;
            return;
        case 'G':
        case 'g':
            pointerArray[6] = newPointer;
            return;
        case 'H':
        case 'h':
            pointerArray[7] = newPointer;
            return;
        case 'I':
        case 'i':
            pointerArray[8] = newPointer;
            return;
        case 'J':
        case 'j':
            pointerArray[9] = newPointer;
            return;
        case 'K':
        case 'k':
            pointerArray[10] = newPointer;
            return;
        case 'L':
        case 'l':
            pointerArray[11] = newPointer;
            return;
        case 'M':
        case 'm':
            pointerArray[12] = newPointer;
            return;
        case 'N':
        case 'n':
            pointerArray[13] = newPointer;
            return;
        case 'O':
        case 'o':
            pointerArray[14] = newPointer;
            return;
        case 'P':
        case 'p':
            pointerArray[15] = newPointer;
            return;
        case 'Q':
        case 'q':
            pointerArray[16] = newPointer;
            return;
        case 'R':
        case 'r':
            pointerArray[17] = newPointer;
            return;
        case 'S':
        case 's':
            pointerArray[18] = newPointer;
            return;
        case 'T':
        case 't':
            pointerArray[19] = newPointer;
            return;
        case 'U':
        case 'u':
            pointerArray[20] = newPointer;
            return;
        case 'V':
        case 'v':
            pointerArray[21] = newPointer;
            return;
        case 'W':
        case 'w':
            pointerArray[22] = newPointer;
            return;
        case 'X':
        case 'x':
            pointerArray[23] = newPointer;
            return;
        case 'Y':
        case 'y':
            pointerArray[24] = newPointer;
            return;
        case 'Z':
        case 'z':
            pointerArray[25] = newPointer;
            return;
        default:
            std::cout << "Error connecting pointers with character" << input << std::endl;
            return;
    }
}

bool Node::returnWordCompleted()
{
    return wordCompleted;
}

void Node::setWordCompleted(bool status)
{
    wordCompleted = status;
    return;
}

spellChecker::spellChecker()
{
    headNode = new Node;
}

spellChecker::~spellChecker()
{
    //dtor

    delete headNode;
    headNode = NULL;
}

void spellChecker::execute()
{
    std::string input;
    compileDictionary();
    while (input != "QUIT")
    {
        std::cout << "Type in a word to be checked" << std::endl;
        std::cin >> input;
        if (input != "QUIT")
        {
            checkWord(input);
        }
    }
    cleanUpNodes(headNode);
}

bool spellChecker::compileDictionary()
{
    std::fstream outputFile;
    std::string currentWord;
    outputFile.open("dictionary.txt");
    if (outputFile.is_open() != false)
    {
        std::cout << "Dictionary Loaded" << std::endl;
        //While there is still words in the file
        while (outputFile >> currentWord)
        {
            Node * traverse = headNode;
            Node * newNode;
            //For every letter in the word
            for (int i = 0; i < currentWord.size(); i++)
            {
                //Add it's letter as a node, if it doesn't already exist
                if (traverse -> returnPointer(currentWord.at(i)) == NULL)
                {
                    newNode = new Node;
                    newNode -> changeStoredCharacter(currentWord.at(i));
                    traverse -> setPointer(currentWord.at(i),newNode);
                    traverse = newNode;
                    //If we are at the last letter
                    if (i+1 == currentWord.size())
                    {
                        newNode -> setWordCompleted(true);
                    }
                }
                //Else we simply move on to the next letter and update the pointer
                else
                {
                    traverse = traverse -> returnPointer(currentWord.at(i));
                    if (i+1 == currentWord.size())
                    {
                        newNode -> setWordCompleted(true);
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Failed to load Dictionary" << std::endl;
        //File was not read
        return false;
    }
    outputFile.close();
    return true;
}

void spellChecker::checkWord(std::string word)
{
    Node * traverse = headNode;
    bool wordExists = false;
    std::vector<std::string> spellSuggestions;
    std::string workingString;
    //Traverse through the string to find out which, if any, letters are missing
    for (int i = 0; i < word.size(); i++)
    {
        //If the letter does exist
        if (traverse -> returnPointer(word.at(i)) != NULL)
        {
            //Add letter to working string
            workingString.push_back(word.at(i));
            traverse = traverse -> returnPointer(word.at(i));
            //If we are at the end of the word
            if ((i+1 == word.size()) && (traverse -> returnWordCompleted() == true))
            {
                //Set the truth flag
                wordExists = true;
            }
        }
        else
        {
            //Save this location to try and find the appropriate word to use.
            beforeSpellError = traverse;
            break;
        }
    }

    //This is where we compile suggestions for the user
    if (wordExists == false)
    {
        //Starting from the error
        traverse = beforeSpellError;
        //Check to see if there is just too many letters
        if (traverse -> returnWordCompleted() == true)
        {
            spellSuggestions.push_back(workingString);
        }
        char currentLetter = 'a';
        for (int i = 0; i < 26; i++)
        {
            if (traverse -> returnPointer(currentLetter) != NULL)
            {
                if (traverse -> returnPointer(currentLetter) -> returnWordCompleted() == true)
                {
                    spellSuggestions.push_back(workingString + currentLetter);
                }
            }
            if (spellSuggestions.size() == 7)
            {
                //That's enough suggestions
                break;
            }
            currentLetter++;
        }

        //Then we print all suggestions
        std::cout << "Suggestions:" << std::endl;
        for (int i = 0; i < spellSuggestions.size(); i++)
        {
            std::cout << spellSuggestions.at(i) << std::endl;
        }
        if (spellSuggestions.size() == 0)
        {
            std::cout << "None Available" << std::endl;
        }
    }
    else
    {
        std::cout << "This word exists." << std::endl;
    }
}

void spellChecker::cleanUpNodes(Node * targetNode)
{
    if (targetNode != NULL)
    {
        char currentLetter = 'a';
        //Cycles through every letter and deletes every node as it goes
        for (int i = 0; i < 26; i++)
        {
            //If there is something in that node
            if (targetNode -> returnPointer(currentLetter) != NULL)
            {
                //Clean it and it's children
                cleanUpNodes(targetNode -> returnPointer(currentLetter));
            }
            currentLetter++;
        }
        delete targetNode;
        targetNode = NULL;
        return;
    }
}

