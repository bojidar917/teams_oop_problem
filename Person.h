#pragma once

#include <iostream>

class Person
{
public:
    Person();
    Person(const char* fname, const char* mname, const char* lname, const char* egn);
    Person(const char* fname, const char* lname, const char* egn);

    bool operator==(const Person& other) const;
    bool operator==(const char* eng) const;
    bool operator!=(const Person& other) const;
    
    void validateEgn(const char* egn);

    void setFName(const char* fname);
    void setMName(const char* mname);
    void setLName(const char* lname);

    const char* getEgn() const {return this->egn;}
    const char* getFName() const {return this->firstName;}
    const char* getMName() const {return this->middleName;}
    const char* getLName() const {return this->lastName; }

    void print() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& str); 

private:
    char firstName[31];
    char middleName[31];
    char lastName[31];
    char egn[11];
};