#include "Person.h"

Person::Person()
{
}

Person::Person( int age )
{
    setAge( age );
}

Person::~Person()
{
}


bool Person::operator==( const Person& lhs )
{
    return getAge() == lhs.getAge();
}