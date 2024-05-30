#include <stdexcept>
#include <iostream>
#include <cstring>

#include "Person.h"

Person::Person()
{
}

Person::Person(const char *fname, const char *mname, const char *lname, const char *egn)
{
    try
    {
        validateEgn(egn);
        setFName(fname);
        setMName(mname);
        setLName(lname);
    } 
    catch(const std::invalid_argument e)
    {
        // how to display properly error messages when I catch them ???
    }    
}

Person::Person(const char* fname, const char* lname, const char* egn)
{
    try
    {
        validateEgn(egn);
        setFName(fname);
        setLName(lname);
    } 
    catch(const std::invalid_argument)
    {
        throw;
    }
}

bool Person::operator==(const Person &other) const
{
    return strcmp(this->egn, other.egn) == 0;
}

bool Person::operator==(const char *eng) const
{
    return strcmp(this->egn, eng) == 0;
}

bool Person::operator!=(const Person &other) const
{
    return !(*this == other);
}

void Person::validateEgn(const char* egn)
{ 
    if(strlen(egn) < 10 || strlen(egn) > 11)
        throw std::invalid_argument("egn must be exactly 10 characters");
    else
        strcpy(this->egn, egn);
}

void Person::setFName(const char* fname)
{
    if(fname)
        strcpy(this->firstName, fname);
    else
        throw std::invalid_argument("something is wrong with the fist name input");
}

void Person::setMName(const char* mname)
{
    if(mname)
        strcpy(this->middleName, mname);
    else
        throw std::invalid_argument("something is wrong with the middle name input");
}

void Person::setLName(const char* lname)
{
    if(lname)
        strcpy(this->lastName, lname);
    else
        throw std::invalid_argument("something is wrong with the last name input");
}

void Person::print() const
{
    // std::cout << "Printing person" << std::endl;
    std::cout << this->firstName << " ";
    std::cout << this->middleName << " ";
    std::cout << this->lastName << " ";
    std::cout << this->egn << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    person.print();
    return os;
}
