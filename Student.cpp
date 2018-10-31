#include "Student.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "Course.h"
using namespace std;
Student::Student()
{}
Student::Student(string r,string s,string f,string l,string p,string u):User(f,l,p,u)
{
    rollNum=r;
    status=s;
}
Student::~Student()
{}
void Student::setRollRum(string r)
{
    rollNum=r;
}
void Student::setStatus(string s)
{
    status=s;
}
string Student::getRollNum()
{
    return rollNum;
}
string Student::getStatus()
{
    return status;
}
void Student::populateUserData(ifstream& in,string f)
{
    rollNum=f;
    string tFirstName,tLastName,tUserName,tPassword;
    in >> status >> tFirstName >> tLastName >> tUserName >> tPassword;
    setFirstName(tFirstName);
    setLastName(tLastName);
    setUsername(tUserName);
    setPassword(tPassword);
    //cout << rollNum << status << getFirstName() << getLastName() << getUsername() << getPassword() << endl;
}
void Student::addCourse(string c)
{
    enrolledCourse.push_back(c);
}
vector<string> Student::getCourses()
{
    return enrolledCourse;
}
string Student::menu1()
{
    string userChoice="";
    unsigned int courseChoice=0;
    string course="";
    cout << endl << "You are enrolled in the following courses: " << endl;
    for(unsigned int n=0; n<enrolledCourse.size(); n++)
        cout << n+1 << ". " << enrolledCourse[n] << endl;
    do
    {
        cout << endl << "Please choose which Course you want to browse: ";
        cin >> courseChoice;
        if(!(courseChoice>0 && courseChoice<(1+enrolledCourse.size())))
            cout << "Invalid Input!" << endl;
    }
    while(!(courseChoice>0 && courseChoice<(1+enrolledCourse.size())));
    course=enrolledCourse[courseChoice-1];
    return course;
}
void Student::viewResourcesTab(Course* ptr)
{
    cout << "The Resources for this course are: " << endl;
    for(unsigned int n=0; n<(ptr->getResources()).size(); n++)
    {
        cout << n+1 << ". " <<(ptr->getResources())[n] << endl;
    }
}
void Student::viewAssignmentsTab(Course* ptr)
{
    cout << "The Assignments for this course are: " << endl;
    for(unsigned int n=0; n<(ptr->getAssignments()).size(); n++)
    {
        cout << n+1 << ". " <<(ptr->getAssignments())[n] << endl;
    }
}
void Student::viewMarksTab(Course* ptr,string u)
{
    int index=0;
    for(unsigned int n=0; n<(ptr->getEnrolledStud()).size(); n++)
    {
        if(((ptr->getEnrolledStud()[n]).getUsername())==u)
        {
            index=n;
            break;
        }
    }
    cout << "Your marks for this course are: " << (ptr->getMarks())[index] << endl;
}
