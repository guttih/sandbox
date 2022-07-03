// File: Person.h created: 2022-07-03
#ifndef _PERSON__H_
#define _PERSON__H_

class Person
{
private:
    int m_age = 0;

public:
    Person();
    Person( int age );
    ~Person();

    int getAge()
    {
        return m_age;
    }
    void setAge( int value )
    {
        m_age = value;
    }
};

#endif
