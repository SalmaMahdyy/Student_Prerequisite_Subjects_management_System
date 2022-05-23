#include "Course.h"

string course::getname()
{
    return name;
}

string course::getcode()
{
    return code;
}
string course::get_prerequiredcourse(int index)
{
    return pre[index];
}
course::course()
{

}

course::~course()
{

}