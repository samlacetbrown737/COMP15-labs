/*
 * FunkeyTable.cpp --- compare two different methods of handling hash
 * table collisions and two different hash functions.
 *
 * your job:  code the insert functions and expand function
 *  our job:  run the insert functions and report results
 *
 * Based on a previous lab by Ben Hescott, I think.
 *
 * Mark A. Sheldon, Tufts University, Spring 2017
 */

#include <iostream>
#include <stdio.h>
#include <functional>

#include "FunkeyTable.h"

using namespace std;

/*
 * Constructor allocates and initializes two empty tables
 * of the INITIAL_TABLE_SIZE
 */
FunkeyTable::FunkeyTable()
{
        currentTableSize = INITIAL_TABLE_SIZE;
        numItemsInTable  = 0;

        chainedTable     = new ChainNode *[currentTableSize];
        linearTable      = new TableEntry[currentTableSize];

        for (int i = 0; i < currentTableSize; i++) {
                chainedTable[i]        = nullptr;
                linearTable[i].isEmpty = true;
        }
}

/*
 * Delete all nodes in list starting with given node
 */
void FunkeyTable::deleteList(ChainNode *node)
{
    // ChainNode *curr = node;
    // ChainNode *nextNode = node;
    // while (node != NULL) {
    //     nextNode = curr->next;
    //     delete curr;
    //     curr = nextNode;
    // }
    // delete nextNode;
    // node = nullptr;
    ChainNode *curr = node;
    ChainNode *next = curr->next;
    delete curr;
    delete next;
}

/*
 * destructor
 */
FunkeyTable::~FunkeyTable()
{
    delete [] linearTable;
    //deleteList(chainedTable[0]);
    for(int i = 0; i < currentTableSize; i++) {
        if(listLength(chainedTable[i]) > 1) {
            deleteList(chainedTable[i]);
            //delete chainedTable[i];
        } else {
            delete chainedTable[i];
        }
    }
    delete [] chainedTable;
}


static size_t good_hash_function(KeyType key)
{
        return std::hash<KeyType>{}(key);
}

static size_t bad_hash_function(KeyType key)
{
        return key.length();
}

static size_t hashValue(KeyType key, FunkeyTable::HashFunction hashFunction)
{
        if (hashFunction == FunkeyTable::BAD_HASH_FUNCTION)
                return bad_hash_function(key);
        else
                return good_hash_function(key);
}

/*
 * Linear Probing
 *
 * Return number of collisions before finding a spot
 *
 */
int FunkeyTable::insertProbing(KeyType key, ValueType value,
                               HashFunction hashFunction)
{
    int    attempt = 0;
    bool   found   = false;
    size_t loc = hashValue(key, hashFunction) % currentTableSize;

    while (not found) {
        if(linearTable[loc].isEmpty) {
            found = true;
            linearTable[loc].isEmpty = false;
            linearTable[loc].key = key;
            linearTable[loc].value = value;
        }
        attempt++;
        loc++;
    }
    return attempt;
}

/*
 * Return length of list starting at given node
 */
int FunkeyTable::listLength(ChainNode *nodep)
{
    int len = 0;
    ChainNode *curr = nodep;
    while (curr != NULL) {
            len++;
            curr = curr->next;
    }
    return len;
}

/*
 * Chained hashing --- each spot in table is a linked list 
 *
 * Return number of items in that spot before insertion
 */
int FunkeyTable::insertChaining(KeyType key, ValueType value,
                                HashFunction hashFunction)
{
        // TODO: Students write code here
        // STUB: Replace with the correct code
        ChainNode *nextNode = new ChainNode;
        nextNode->key = key;
        nextNode->value = value;
        nextNode->next = nullptr;
        size_t loc = hashValue(key, hashFunction) % currentTableSize;
        int prevLength = listLength(chainedTable[loc]);
        if(chainedTable[loc] != nullptr) {
            nextNode->next = chainedTable[loc];
        }
        chainedTable[loc] = nextNode;
        return prevLength;
}




/*
 * Expand both of the hash tables
 */
void FunkeyTable::expand(HashFunction hashFunction)
{
        FunkeyTable *songDB2 = new FunkeyTable;
        songDB2->currentTableSize = (songDB2->currentTableSize * 2) + 2;
        for (int i = 0; i < currentTableSize; i++) {
                if(chainedTable[i] != nullptr) {
                    songDB2->insertChaining(chainedTable[i]->key,
                        chainedTable[i]->value, hashFunction);
                }
                if(!linearTable[i].isEmpty) {
                    songDB2->insertProbing(linearTable[i].key,
                        linearTable[i].value, hashFunction);
                }
        }
}

void FunkeyTable::printTableEntry(TableEntry entry)
{
        if (entry.isEmpty)
                cout << "empty";
        else
                cout << "key:  "
                     << entry.key
                     << "; value:  {"
                     << entry.value.chartPosition
                     << ", "
                     << entry.value.bpm
                     << "}";
}

void FunkeyTable::printChainNode(ChainNode *nodep)
{
        cout << "key:  " << nodep->key
             << "; value:  {" << nodep->value.chartPosition
             << ", " << nodep->value.bpm << "}";
}

/*
 * Print both hash tables
 * Could break this up into two print functions
 */
void FunkeyTable::print()
{
        cout << "Linear table" << endl;
        
        for (int i = 0; i < currentTableSize; ++i) {
                cout << i << ":  ";
                printTableEntry(linearTable[i]);
                cout << endl;
        }
        cout << endl << "Chained table" << endl;
        
        for (int i = 0; i < currentTableSize; ++i) {
                ChainNode *curr = chainedTable[i];
                cout << i << ":  [ ";
                while (curr != NULL) {
                        printChainNode(curr);
                        curr = curr->next;
                        if (curr != NULL)
                                cout << ", ";
                }
                cout << "]" << endl;
        }
        cout << endl;
}
