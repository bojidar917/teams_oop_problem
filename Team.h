#pragma once

#include "Group.h"
#include "Pair.h"

class Team : public Group
{
public:
    Team();
    Team(const Team& other);
    Team& operator=(const Team& other);
    ~Team();

    bool operator()(const Person& person1, const Person& person2);

    void printRelations() const;

private:
    Pair* pairs;
    int size;
    int capacity;

    void clear();
    void copy(const Team& other);
    void resize();

    void makeNewPair(const Person& person1, const Person& person2);
    int checkIfPairExist(const Person& person) const;
};