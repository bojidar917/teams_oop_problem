#include <stdexcept>
#include <iostream>

#include "Group.h"

Group::Group() : people(nullptr), size(0), capacity(0)
{
}

Group::Group(const Group &other) : Group()
{
    copy(other);
}

Group &Group::operator=(const Group &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Group::~Group()
{
    clear();
}

Group &Group::operator+=(const Person &newP)
{
    addPerson(newP);
    return *this;
}

Group Group::operator+(const Person &newP)
{
    Group result = *this;
    result += newP;
    return result;
}

Group &Group::operator-=(const char *egn)
{

    removePerson(egn);
    return *this;
}

Group Group::operator-(const char *egn)
{
    Group result = *this;
    result -= egn;
    return result;
}

int Group::operator()() const
{
    return this->size;
}

bool Group::operator()(const Person &person) const
{
    return checkPersonInGroup(person.getEgn()); 
}

void Group::print() const
{
    std::cout << "__________Printing Group_____________" << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        this->people[i].print();
    }
    
}

void Group::clear()
{
    delete [] this->people;
}

void Group::copy(const Group &other)
{    
    this->size = other.size;
    this->capacity = other.capacity;
    this->people = new Person[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        this->people[i] = other.people[i];
    }
}

void Group::resize()
{
    if(this->capacity == 0)
        this->capacity = 1;

    int newCapacity = this->capacity * 2 + 1;
    Person* temp = new Person[newCapacity];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = this->people[i];
    }
    delete [] this->people;
    this->people = temp;
    this->capacity = newCapacity;   
}

bool Group::checkEgn(const Person &groupPerson, const Person &otherPerson) const
{
    return groupPerson == otherPerson;
}

bool Group::checkPersonInGroup(const char *egn) const
{
    for (int i = 0; i < this->size; i++)
    {
        if(this->people[i] == egn)
            return true;
    }
    
    return false;
}

void Group::addPerson(const Person &newP)
{
    if(checkPersonInGroup(newP.getEgn()))
        throw std::invalid_argument("Person is already in the group");
    
    if(this->size == this->capacity)
        resize();

    this->people[this->size++] = newP;
}

void Group::removePerson(const char *egn)
{
    if(!checkPersonInGroup(egn))
        throw std::invalid_argument("person with this egn is not in the grouo");
    int index = -1;
    for (int i = 0; i < this->size; i++)
    {
        if(this->people[i] == egn)
            index = i;
    }

    if(index != -1)
    {
        for (int i = index; i < this->size - 1; i++)
        {
            this->people[i] = this->people[i+1];
        }
        this->size--;
    }
}
