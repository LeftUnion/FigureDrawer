#ifndef FOO_HPP
#define FOO_HPP

#include <QString>

namespace Foo {

class SomeClass
{

public:
    SomeClass() = default;
    QString hello();

private:
    static const QString M_RETURN_STRING;

};

}

#endif // FOO_HPP
