/* ArrayList.cpp
 *
 * Comp 15 Lab 0
 * Edited by C.R. Calabrese, Sept 2020
 *
 * The ArrayList class is an ordered list of strings. To use this class, a
 *  client need not worry about the size of the list in memory nor whether it
 *  can fit the number of elements they would like to store.
 *
 * TODO: The ArrayList class is designed to be able to expand and shrink to
 *  best fit the number of items that need to be stored, but it currently
 *  cannot.
 */
#include <ostream>

#include "ArrayList.h"

using namespace std;

// Default Constructor -- initializes an empty ArrayList
ArrayList::ArrayList()
{
    numItems = 0;
    capacity = DEFAULT_SIZE;
    arr      = new string[capacity];
}

// Destructor -- cleans up memory associated with the ArrayList
ArrayList::~ArrayList()
{
    delete [] arr;
    arr = nullptr;
}

/* size
 *    Purpose: For checking the current length of the list
 * Parameters: none
 *    Returns: number of items currently in list, as an int.
 *
 *       Note: here, "size" does not refer to the size of the list in memory,
 *             nor how many elements could fit in the list.
 */
int ArrayList::size()
{
    return numItems;
}

/* insert
 * Purpose: Add the given item to the back of the list
 * Parameters: string item - the value to insert
 * Returns: nothing
 */
void ArrayList::insert(string item)
{
    arr[numItems] = item;
    numItems++;
    checkSize();
}

/* remove
 *    Purpose: remove the specified item from the list, if it is present
 * Parameters: string item - value to remove from the list
 *    Returns: bool - whether the item was removed or not
 */
bool ArrayList::remove(string item)
{
    int index = find(item);
    if (index >= 0)
        arr[index] = "";
    else
        return false;

    shift();
    numItems--;
    checkSize();
    return true;
}

/* checkSize
* Purpose: See if resizing is necessary
* Parameters: none
* Returns: nothing
*/
void ArrayList::checkSize() {
    if(numItems == capacity) {
        expand();
    } else if (numItems < capacity/2) {
        shrink();
    }
}

/* find
 *    Purpose: Given a value, find its position in the list
 * Parameters: string item - the value to search for in the list
 *    Returns: int - the index of item in the list, or -1 if the item was
 *             not found
 *
 *       Note: If a value occurs more than once in the list, find will return
 *             the first index at which it can be found.
 */
int ArrayList::find(string item)
{
    for (int i = 0; i < numItems; i++) {
        if (arr[i] == item) return i;
    }
    return -1;
}

/* shift
 *    Purpose: Shifts elements to the left if there is an empty space
 * Parameters: none
 *    Returns: nothing
 */
void ArrayList::shift()
{
    for (int i = 1; i < numItems; i++) {
        if (arr[i - 1] == "") {
            arr[i - 1] = arr[i];
            arr[i] = "";
        }
    }
}

/* print
 *    Purpose: Prints out each item on the list
 * Parameters: ostream & - where to print
 *    Returns: nothing
 */
void ArrayList::print(ostream &out)
{
    for (int i = 0; i < numItems; i++) {
        out << " - " << arr[i] << endl;
    }
}

/* expand
 *    Purpose: Doubles the capacity of the array
 * Parameters: none
 *    Returns: nothing
 */
void ArrayList::expand()
{
    resize((capacity*2) + 2);
}

/* shrink
 *    Purpose: Halves the capacity of the array
 * Parameters: none
 *    Returns: nothing
 */
void ArrayList::shrink()
{
    resize((capacity/2) + 2);
}

/* Function resize
 *    Purpose: Updates the capacity of the array to the given size
 * Parameters: int newSize - the desired capacity of the list. 
 *             The array will be updated to have space for newSize elements.
 *    Returns: nothing
 * 
 *       Note: If there are any elements past index newSize, 
 *             they will be lost.
 */
void ArrayList::resize(int newSize)
{
    string *transfer = new string[newSize];
    for(int i = 0; i < numItems; i++) {
        transfer[i] = arr[i];
    }
    delete [] arr;
    arr = transfer;
    capacity = newSize;
}
