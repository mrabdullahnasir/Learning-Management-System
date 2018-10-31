#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
using namespace std;
class Course;
class User
{
    public:
        User();
        User(string f,string l,string p,string u);
        ~User();
        void setFirstName(string f);
        void setLastName(string l);
        void setPassword(string p);
        void setUsername(string u);
        string getFirstName();
        string getLastName();
        string getPassword();
        string getUsername();
        virtual void populateUserData(ifstream& in,string f);
        virtual string getRollNum();
        virtual void addCourse(string c);
        virtual void addCourseTaught(string c);
        virtual string menu1();
        virtual void viewResourcesTab(Course* ptr);
        virtual void viewAssignmentsTab(Course* ptr);
        virtual void viewMarksTab(Course* ptr,string u);
    protected:
    private:
        string firstName;
        string lastName;
        string password;
        string username;
};

#endif // USER_H
