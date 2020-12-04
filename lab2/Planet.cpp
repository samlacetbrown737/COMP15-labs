/*
 * Planet.cpp
 * 
 * Comp 15 Lab 2
 * Edited by Elizabeth Hom, Sept 2020
 * 
 * The Planet class contains functions and info regarding a Planet object.
 */

#include <fstream>

#include "Planet.h"

using namespace std;

/* Default constructor
 *    Purpose: Creates a Planet object with the default name "Earth"
 * Parameters: none
 *    Returns: none
 */
Planet::Planet()
{
    name = "Earth";
}

/* Parametrized constructor
 *    Purpose: Creates a Planet object with the given name
 * Parameters: string - name of planet
 *    Returns: none
 */
Planet::Planet(string name)
{
    this->name = name;
}

/* print
 *    Purpose: Prints out the name associated with a Planet object
 * Parameters: ostream & - where to print
 *    Returns: none
 */
void Planet::print(ostream &out) const
{
    out << name;
}

/* Assignment operator
 *
 * Note: the assignment operator is overloaded and returns true if two planets
 *       have the same name.
 */
bool Planet::operator== (const Planet &other)
{
    return (name == other.name);
}

