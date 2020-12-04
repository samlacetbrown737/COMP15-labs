/* ArrayList.h
 *
 * Comp 15 Lab 1
 * Edited by Sam Lacet-Brown, Sept 2020
 *
 * The ArrayList class is an ordered list of strings with the ability to
 * add, remove, find, and print the list. Memory is managed internally and
 * the list can grow and shrink to accommodate insertion and removal.
 *
 */

#include <string>
#include <ostream>

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

class ArrayList
{
    public: 
        ArrayList();
        ~ArrayList();

        void insert(std::string item);
        bool remove(std::string item);
        int  find(std::string item);


        void print(std::ostream &out);
        int size();

    private:
        static const int DEFAULT_SIZE = 5;
        std::string *arr; 
        std::string *transfer;
        int numItems;
        int capacity; 

        // Helper function for remove()
        void shift();

        //Helper function for insert() and remove();
        void checkSize();
        
        // You write these functions
        void expand();
        void shrink();
        void resize(int);

};

#endif 
