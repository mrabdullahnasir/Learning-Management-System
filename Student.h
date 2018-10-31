#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;
class Course;
class Student:public User
{
    public:
        Student();
        Student(string r,string s,string f,string l,string p,string u);
        ~Student();
        void setRollRum(string r);
        void setStatus(string s);
        string getRollNum();
        string getStatus();
        void populateUserData(ifstream& in,string f);
        void addCourse(string c);
        vector<string> getCourses();
        string menu1();
        void viewResourcesTab(Course* ptr);
        void viewAssignmentsTab(Course* ptr);
        void viewMarksTab(Course* ptr,string u);
    protected:
    private:
        string rollNum;
        string status;
        vector<string> enrolledCourse;
};

#endif // STUDENT_H
