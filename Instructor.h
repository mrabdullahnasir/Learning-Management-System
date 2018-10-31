#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "User.h"
#include <iostream>
using namespace std;
class Course;
class Instructor:public User
{
    public:
        Instructor();
        Instructor(string d,string q,string f,string l,string p,string u);
        ~Instructor();
        void setDesignation(string d);
        void setQualification(string q);
        string getDesignation();
        string getRollNum();
        string getQualification();
        void populateUserData(ifstream& in,string f);
        void addCourseTaught(string c);
        vector<string> getCourses();
        string menu1();
        void viewResourcesTab(Course* ptr);
        void viewAssignmentsTab(Course* ptr);
        void viewMarksTab(Course* ptr,string u);
    protected:
    private:
        string designation;
        string qualification;
        vector<string> coursesTaught;
};

#endif // INSTRUCTOR_H
