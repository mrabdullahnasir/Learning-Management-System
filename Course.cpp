#include "Course.h"
#include <iostream>
#include <fstream>
using namespace std;
Course::Course()
{}
Course::Course(string n,string c,string o,int cap)
{
    courseName=n;
    courseCode=c;
    offeringSchool=o;
    capacity=cap;
}
Course::~Course()
{
}
void Course::setCourseName(string n)
{
    courseName=n;
}
void Course::setCourseCode(string c)
{
    courseCode=c;
}
void Course::setOfferingSchool(string o)
{
    offeringSchool=o;
}
void Course::setCapacity(int cap)
{
    offeringSchool=cap;
}
string Course::getCourseName()
{
    return courseName;
}
string Course::getCourseCode()
{
    return courseCode;
}
string Course::getOfferingSchool()
{
    return offeringSchool;
}
int Course::getCapacity()
{
    return capacity;
}
void Course::readFile(char fName[12],int c,User** ptr)
{
    
}
void Course::displayRoster()
{
}
vector<string> Course::getResources()
{
    return resources;
}
void Course::addResource(string r)
{
    resources.push_back(r);
}
vector<string> Course::getAssignments()
{
    return assignments;
}
void Course::addAssigment(string a)
{
    assignments.push_back(a);
}
vector<string> Course::getMarks()
{
    return marks;
}
void Course::addMarks(string m,int ind)
{
    marks[ind]=m;
}
vector<Student> Course::getEnrolledStud()
{
    return enrolledStud;
}
