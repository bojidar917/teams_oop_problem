#pragma once

#include "Person.h"

class Relation
{
public:
    Relation();
    Relation(const Person& p1, const Person& p2);

    const Person& getEmployee() const {return this->employee;}

    void changeBoss(const Person& newBoss);

    void print() const;

private:
    Person boss;
    Person employee;
};