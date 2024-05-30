#pragma once

#include "Person.h"

class Group
{
public: //g4
    Group();
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();

public: //operators
    Group& operator+=(const Person& newP);
    Group operator+(const Person& newP);

    Group& operator-=(const char* egn);
    Group operator-(const char* egn);

    int operator()() const;
    bool operator()(const Person& person) const;

public: // methods
    void print() const;

private: //members
    Person* people;
    int size;
    int capacity;

private: // methods
    void clear();
    void copy(const Group& other);
    void resize();

    bool checkEgn(const Person& groupPerson, const Person& otherPerson) const;
    bool checkPersonInGroup(const char* egn) const;
    void addPerson(const Person& newP);
    void removePerson(const char* egn);

};