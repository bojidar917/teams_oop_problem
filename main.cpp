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
    //The idea explained:
    //First, I choose to derive the Group class, because I understood the assignment like: team "is a" group
    //Second, my idea was to structure all the information about team members in pairs. This way we can
    //set hierarchy of managers and workers. I was discussing (with myself) two other options:
    //1. save "boss" pointer to each Person (new class member). This way every person would know his boss
    //2. make new groups and save each relationship there. (Something like dictionary, but it was too much worl)
    //if there is better way (probably there is way better ways than mine), please note that in the comments
    //Known problems with this solution: I think it is not that memory efficient, because we pass constantly
    //different types from left to right, and there are probably many
    //problems with the exception handling.


    // checkPeople(); //works fine
    // testGroup() //works fine
    testTeams(); // works fine


    return 0;
}