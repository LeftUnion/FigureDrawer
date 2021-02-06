#include <Foo.hpp>

#include <QMessageBox>

namespace Foo {

const QString SomeClass::M_RETURN_STRING = "Hello World!";

QString SomeClass::hello()
{
    return M_RETURN_STRING ;
}

}
