/*****************************************************************************
*
*  Author:           Sudhir Ray
*  Email:            sray0228@my.msutexas.edu
*  Label:            P02
*  Title:            AutoComplete in Linear Time
*  Course:           CMPS 3013
*  Semester:         Spring 2023
*
*  Description:
*        The class loads all of the values in the linked list. It also has
*        functionality to search the words.
*  Usage:
*        Create the list and load it with words     
*  Files:
*        N/A
*****************************************************************************/
//List.hpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * wordNode
 * 
 * Description:
 *      Node used to store the words from the dictionary into
 * 		  the linked list
 * 
 * Public Methods:
 *            wordNode   : overloaded constructor  
 * 
 * Private Methods:
 *                N/A
 *       
 * 
 * Usage: 
 *       N/A
 * 
 *      
 */

struct wordNode
{
    string word;
    wordNode *next;

/**
 * Public: wordNode
 * 
 * Description:
 *     Constructor that recieves a string and creates a new node. 
 * 
 * Params:
 *      string  :	word for the node
 * 
 * Returns:
 *      N/A
*/
    wordNode(string value)
    {
        word = value;
        next = nullptr;
    }
};

/**
 * Class LinkedList
 *
 * Description:
 *            A linked list that stores all the words passed from
 * the file.
 * Public Methods:
 *                                LinkedList()
 *            void                Insert(string value)
 *            vector<string>      findWords(string target) 
 *
 * Private Methods:
 *               N/A
 *
 * Usage:
 *        N/A
 */

class LinkedList
{
    wordNode *head;
    wordNode *tail;

public:
/**
 * Public: LinkedList
 * 
 * Description:
 *     Default constructor that sets head and tail nodes to NULL 
 * 
 * Params:
 *      N/A
 * 
 * Returns:
 *      N/A
*/
    LinkedList()
    {
        head = tail = nullptr;
    }

    /**
     * Public : Insert
     *
     * Description:
     *      Add word in linkedList.
     *
     * Params:
     *      string     :  word to be inserted
     *
     * Returns:
     *      void
     */

    void Insert(string value)
    {

        wordNode *temp = new wordNode(value);
        if (head == nullptr) {
			    head = temp;
			    tail = temp;
        }
        else {
          tail->next = temp;
          tail = temp;
          temp->next = nullptr;
        }
    }

/**
     * Public : findWords
     *
     * Description:
     *      find the word in the linked list and return a vector of 
     *      matching words
     * Params:
     *      string     :  the word to be compared to
     *
     * Returns:
     *      vector     :  the vector of all the matching words
     */

vector<string> findWords(string target)
    {
        vector<string> result;
        wordNode *current = head;
        while (current != nullptr)
        {

            if (current->word.substr(0, target.size()) == target)
            {
                result.push_back(current->word);
            }
            current = current->next;
        }
        return result;
    }
};
