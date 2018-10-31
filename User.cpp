#include "User.h"
#include <iostream>
#include <fstream>
#include "Course.h"
using namespace std;
User::User()
{}
User::User(string f,string l,string p,string u)
{
    firstName=f;
    lastName=l;
    password=p;
    username=u;
}
User::~User()
{}
void User::setFirstName(string f)
{
    firstName=f;
}
void User::setLastName(string l)
{
    lastName=l;
}
void User::setPassword(string p)
{
    password=p;
}
void User::setUsername(string u)
{
    username=u;
}
string User::getFirstName()
{
    return firstName;
}
string User::getLastName()
{
    return lastName;
}
string User::getPassword()
{
    return password;
}
string User::getUsername()
{
    return username;
}
void User::populateUserData(ifstream& in,string f)
{}
string User::getRollNum()
{
    return "";
}
void User::addCourse(string c)
{}
void User::addCourseTaught(string c)
{}
string User::menu1()
{
    return "";
}
void User::viewResourcesTab(Course* ptr)
{}
void User::viewAssignmentsTab(Course* ptr)
{}
void User::viewMarksTab(Course* ptr,string u)
{}
