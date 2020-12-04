/*
 * Planet.h
 * 
 * Comp 15 Lab 2
 * Edited by Elizabeth Hom, Sept 2020
 *
 * The Planet class contains functions and info regarding a Planet object.
 *
 */

#ifndef PLANET_H_
#define PLANET_H_

#include <string>
#include <ostream>

class Planet
{
public:
	// Constructors
    Planet();
    Planet(std::string name);

    void print(std::ostream &out) const;

    // Assignment operator
    bool operator== (const Planet &other);
    
private:
    std::string name;
};

#endif
