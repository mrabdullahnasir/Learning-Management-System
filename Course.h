#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>
#include "Instructor.h"
#include "Student.h"
using namespace std;
class Course
{
    public:
        Course();
        Course(string n,string c,string o,int cap);
        ~Course();
        void setCourseName(string n);
        void setCourseCode(string c);
        void setOfferingSchool(string o);
        void setCapacity(int cap);
        string getCourseName();
        string getCourseCode();
        string getOfferingSchool();
        int getCapacity();
        void readFile(char fName[12],int c,User** ptr);
        void displayRoster();
        vector<string> getResources();
        void addResource(string r);
        vector<string> getAssignments();
        void addAssigment(string a);
        vector<string> getMarks();
        void addMarks(string m,int ind);
        vector<Student> getEnrolledStud();
    protected:
    private:
        string courseName;
        string courseCode;
        string offeringSchool;
        int capacity;
        vector<Student> enrolledStud;
        vector<Instructor> instructors;
        vector<string> resources;
        vector<string> assignments;
        vector<string> marks;
};

#endif // COURSE_H
