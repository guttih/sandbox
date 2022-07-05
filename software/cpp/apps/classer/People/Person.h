// File: Person.h created: 2022-07-03
#ifndef _PERSON__H_
#define _PERSON__H_

class Person
{
private:
    int m_age;

public:
    Person();
    Person( int age );
    bool operator==( const Person& lhs );
    ~Person();

    int getAge() const
    {
        return m_age;
    }
    void setAge( const int value )
    {
        m_age = value;
    }


};

#endif
