#include "Instructor.h"
#include <iostream>
#include <fstream>
#include "User.h"
#include "Course.h"
using namespace std;
Instructor::Instructor()
{}
Instructor::Instructor(string d,string q,string f,string l,string p,string u):User(f,l,p,u)
{
    designation=d;
    qualification=q;
}

Instructor::~Instructor()
{}
void Instructor::setDesignation(string d)
{
    designation=d;
}
void Instructor::setQualification(string q)
{
    qualification=q;
}
string Instructor::getDesignation()
{
    return designation;
}
string Instructor::getRollNum()
{
    return designation;
}
string Instructor::getQualification()
{
    return qualification;
}
void Instructor::populateUserData(ifstream& in,string f)
{
    designation=f;
    string tFirstName,tLastName,tUserName,tPassword;
    in >> qualification >> tFirstName >> tLastName >> tUserName >> tPassword;
    setFirstName(tFirstName);
    setLastName(tLastName);
    setUsername(tUserName);
    setPassword(tPassword);
    //cout << designation << qualification << getFirstName() << getLastName() << getUsername() << getPassword() << endl;
}
void Instructor::addCourseTaught(string c)
{
    coursesTaught.push_back(c);
}
vector<string> Instructor::getCourses()
{
    return coursesTaught;
}
string Instructor::menu1()
{
    string userChoice="";
    unsigned int courseChoice=0;
    string course="";
    cout << endl << "You are teaching the following courses: " << endl;
    for(unsigned int n=0; n<coursesTaught.size(); n++)
        cout << n+1 << ". " << coursesTaught[n] << endl;
    do
    {
        cout << endl << "Please choose which Course you want to browse: ";
        cin >> courseChoice;
        if(!(courseChoice>0 && courseChoice<(1+coursesTaught.size())))
            cout << "Invalid Input!" << endl;
    }
    while(!(courseChoice>0 && courseChoice<(1+coursesTaught.size())));
    course=coursesTaught[courseChoice-1];
    return course;
}
void Instructor::viewResourcesTab(Course* ptr)
{
    string userChoice;
    string resourceName;
    do
    {
        cout << "Press 1 to Add a New Resource" << endl;
        cout << "Press 2 to View All Resources" << endl;
        cout << "Press 3 to Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        if(userChoice=="1")
        {
            cout << "Enter the filename of the new resource: ";
            cin >> resourceName;
            ptr->addResource(resourceName);
            cout << "Resource added successfully." << endl;
        }
        else if(userChoice=="2")
        {
            cout << "The Resources for this course are: " << endl << endl;
            for(unsigned int n=0; n<(ptr->getResources()).size(); n++)
                cout << n+1 << ". " <<(ptr->getResources())[n] << endl;
        }
        else if(userChoice=="3")
        {}
        else
            cout << "Invalid Input!" << endl;
    }
    while(userChoice!="3");
}
void Instructor::viewAssignmentsTab(Course* ptr)
{
    string userChoice;
    string assignmentName;
    do
    {
        cout << "Press 1 to Add a new Assignment" << endl;
        cout << "Press 2 to View All Assignments" << endl;
        cout << "Press 3 to Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        if(userChoice=="1")
        {
            cout << "Enter the filename of the new Assignment: ";
            cin >> assignmentName;
            ptr->addAssigment(assignmentName);
            cout << "Assignment added successfully." << endl;
        }
        else if(userChoice=="2")
        {
            cout << "The Assignments for this course are: " << endl << endl;
            for(unsigned int n=0; n<(ptr->getAssignments()).size(); n++)
                cout << n+1 << ". " <<(ptr->getAssignments())[n] << endl;
        }
        else if(userChoice=="3")
        {}
        else
            cout << "Invalid Input!" << endl;
    }
    while(userChoice!="3");
}
void Instructor::viewMarksTab(Course* ptr,string u)
{
    string userChoice;
    string marks;
    do
    {
        cout << "Press 1 to Enter Marks" << endl;
        cout << "Press 2 to View All Marks" << endl;
        cout << "Press 3 to Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        if(userChoice=="1")
        {
            for(unsigned int n=0; n<ptr->getMarks().size(); n++)
            {
                cout << "Enter Marks for " << ((ptr->getEnrolledStud())[n]).getRollNum() << " :";
                cin >> marks;
                ptr->addMarks(marks,n);
            }
        }
        else if(userChoice=="2")
        {
            cout << "Roll Num --- Marks" << endl;
            for(unsigned int n=0; n<ptr->getMarks().size(); n++)
                cout << ((ptr->getEnrolledStud())[n]).getRollNum() << " --- " << (ptr->getMarks())[n] << endl;
        }
        else if(userChoice=="3")
        {}
        else
            cout << "Invalid Input!" << endl;
    }
    while(userChoice!="3");
}
