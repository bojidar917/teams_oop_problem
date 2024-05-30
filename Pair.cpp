#include "Pair.h"

#include <iostream>

Pair::Pair()
{
}

Pair::Pair(const Person &p1, const Person &p2)
    : boss(p1), employee(p2)
{
}

void Pair::changeBoss(const Person &newBoss)
{
    this->boss = newBoss;
}

void Pair::print() const
{
    std::cout << "Boss ->" << this->boss << "employee -> " << this->employee << std::endl;
    // std::cout << this->employee << std::endl;
    // this->boss.print();
    // std::cout << "--->";
    // this->employee.print();

}
