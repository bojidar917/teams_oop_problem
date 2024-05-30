#include "Team.h"

#include <stdexcept>
#include <iostream>
#include <cstring>

Team::Team() : Group(), pairs(nullptr), size(0), capacity(0)
{
}

Team::Team(const Team &other) : Team()
{
    clear();
}

Team &Team::operator=(const Team &other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

Team::~Team()
{
    clear();
}

bool Team::operator()(const Person &person1, const Person &person2)
{
    if(Group::operator()(person1) && Group::operator()(person2))
    {
        int index = checkIfPairExist(person2); 
        if(index != -1)
        {
           this->pairs[index].changeBoss(person1); 
        }
        else
        {
            makeNewPair(person1, person2);
        }
        return true;
    }
    else throw std::invalid_argument("both people must be at the team");

    // return false;
}

void Team::printRelations() const
{
    std::cout << "Printing relations..." << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        this->pairs[i].print();
    }
}

void Team::clear()
{
    delete [] this->pairs;
}

void Team::copy(const Team &other)
{
    this->size = other.size;
    this->capacity = other.capacity;

    this->pairs = new Pair[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->pairs[i] = other.pairs[i];
    }
}

void Team::resize()
{
    if(this->capacity == 0)
        this->capacity = 1;

    this->capacity += this->capacity*2 + 1;
    Pair* temp = new Pair[this->capacity];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = this->pairs[i];
    }
    delete [] this->pairs;
    this->pairs = temp;
}

void Team::makeNewPair(const Person &person1, const Person &person2)
{
    if(this->size == this->capacity)
        resize();

    Pair newPair(person1, person2);
    this->pairs[this->size++] = newPair;
}

int Team::checkIfPairExist(const Person &person) const
{
    int index = -1;
    for (int i = 0; i < this->size; i++)
    {
        // if(strcmp(this->pairs[i].getEmployee().getEgn(), person.getEgn()) == 0)
        // if(this->pairs[i].getEmployee() == person.getEgn())
        if(this->size > 0)
        {
            this->pairs[i].getEmployee().print();
            if(this->pairs[i].getEmployee() == person)
                index = i;
        }
    }
    return index;
}
