#include <iostream>

#include "Person.h"
#include "Group.h"
#include "Team.h"

void testGroup()
{
    Person me("Bo", "Jo", "Kahn", "0123456789");
    Person you("Jo", "Mo", "Shmo", "1234567890");
    // me.print();
    Person he("Vo", "Do", "Go", "2345678901");
    Person theOther("Soo", "Ko", "3456789012");
    Person thatOne("Po", "Ro", "TO", "4567890123");

    Group newGroup;
    newGroup += me;
    newGroup += you;
    newGroup += he;
    newGroup += theOther;

    newGroup.print();
}

void testTeams()
{
    Person me("Bo", "Jo", "Kahn", "0123456789");
    Person you("Jo", "Mo", "Shmo", "1234567890");
    Person he("Vo", "Do", "Go", "2345678901");

    Team team;
    team += me;
    team += you;
    team += he;

    team.print();

    team(me, you);
    team(he, me);

    team.printRelations();
}

void checkPeople()
{
    Person me("Bo", "Jo", "Kahn", "0123456789");
    const Person& someP = me;
    Person you("Jo", "Mo", "Shmo", "1234567890");
    const Person& moreP = you;

    if(someP != moreP)
        std::cout << "Fuck you";
}

int main()
{
    // checkPeople(); //works fine
    // testGroup() //works fine
    testTeams(); // works fine


    return 0;
}