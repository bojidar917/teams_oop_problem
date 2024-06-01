#include "Relation.h"

#include <iostream>

Relation::Relation()
{
}

Relation::Relation(const Person &boss, const Person &worker)
    : boss(boss), employee(worker)
{
}

void Relation::changeBoss(const Person &newBoss)
{
    this->boss = newBoss;
}

void Relation::print() const
{
    std::cout << "Boss ->" << this->boss << "employee -> " << this->employee << std::endl;
    // std::cout << this->employee << std::endl;
    // this->boss.print();
    // std::cout << "--->";
    // this->employee.print();

}
