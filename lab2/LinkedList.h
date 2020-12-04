/*
 * LinkedList.h
 * 
 * Comp 15 Lab 2
 * Edited by Sam Lacet-Brown, Sept 2020
 *
 * The LinkedList class is a linked list of planet nodes with the ability to
 * insert planets at the front and back, and print the list.
 *
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <ostream>

#include "Zip.h"


class LinkedList
{
public:
    // Default constructor
    LinkedList();

    // Assignment Operator
    LinkedList &operator= (const LinkedList &rhs);

    // Inserts a planet (at the front and back of the list, respectively)
    void insert_planet(Planet);
    void insert_planet_at_back(Planet);
 
    // Advances the pointer of curr_pos and returns the name of next Planet
    Planet get_next_planet();

    int get_length() const;
    void print(std::ostream &output) const;

private:
    struct Node {
            Planet  info;
            Node   *next;
            Node *last;
    };

    int   length;
    Node *front;
    Node *back;
    Node *curr_pos;
};

#endif
