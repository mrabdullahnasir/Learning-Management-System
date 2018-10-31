#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
using namespace std;
int main()
{
    string userName;
    string password;
    string userType;
    ifstream in;
    int userCount=0;
    in.open("userList.txt");
    User** usrPtr=new User*[1];
    Course* crsPtr= new Course[5];
    int usrInd=0;
    while(!(in.eof()))
    {
        in >> userType;
        if(userType=="Professor")
            usrPtr[usrInd]=new Instructor;
        else
            usrPtr[usrInd]=new Student;
        usrPtr[usrInd]->populateUserData(in,userType);
        usrInd++;
        userCount=usrInd;
        User** temp = new User*[usrInd+1];
        for(int i=0; i<usrInd; i++)
            temp[i]=usrPtr[i];
        delete [] usrPtr;
        usrPtr=temp;
        temp=NULL;
    }
    in.close();
    char c1file[12]="Course1.txt";
    char c2file[12]="Course2.txt";
    char c3file[12]="Course3.txt";
    char c4file[12]="Course4.txt";
    char c5file[12]="Course5.txt";
    crsPtr[0].readFile(c1file,userCount,usrPtr);
    crsPtr[1].readFile(c2file,userCount,usrPtr);
    crsPtr[2].readFile(c3file,userCount,usrPtr);
    crsPtr[3].readFile(c4file,userCount,usrPtr);
    crsPtr[4].readFile(c5file,userCount,usrPtr);
    string userChoice="";
    string crs="";
    int chosenCrs=0;
    string mainChoice="";
    cout << "Welcome to LMS" << endl;
    do
    {
        cout << "Press 1 to Login" << endl;
        cout << "Press 2 to Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;
        if(mainChoice=="1")
        {
            cout << "Enter Username: ";
            cin >> userName;
            cout << "Enter your Password: ";
            cin >> password;
            for(int n=0; n<userCount; n++)
            {
                if(userName==(usrPtr[n]->getUsername()) && password==(usrPtr[n]->getPassword()))
                {
                    cout << "Logged In successfully." << endl;
                    usrInd=n;
                    break;
                }
                else if(n==userCount-1)
                {
                    cout << "The entered Username and Password combination does not exist. Exiting..." << endl;
                    return 0;
                }
            }
            crs=usrPtr[usrInd]->menu1();
            for(int n=0; n<5; n++)
            {
                if((crsPtr[n].getCourseCode())==crs)
                {
                    chosenCrs=n;
                    break;
                }
            }
            do
            {
                cout << endl << "Press 1 to View List of Resources" << endl;
                cout << "Press 2 to View List of Assignments" << endl;
                cout << "Press 3 to View Roster" << endl;
                cout << "Press 4 to View Your Marks" << endl;
                cout << "Press 5 to Log out" << endl;
                cout << endl << "Enter your choice: ";
                cin >> userChoice;
                if(userChoice=="1")
                    usrPtr[usrInd]->viewResourcesTab(crsPtr+chosenCrs);
                else if(userChoice=="2")
                    usrPtr[usrInd]->viewAssignmentsTab(crsPtr+chosenCrs);
                else if(userChoice=="3")
                    crsPtr[chosenCrs].displayRoster();
                else if(userChoice=="4")
                    usrPtr[usrInd]->viewMarksTab(crsPtr+chosenCrs,userName);
                else if(userChoice=="5")
                {}
                else
                    cout << "Invalid Input!" << endl;
            }
            while(userChoice!="5");
        }
        else if(mainChoice=="2")
        {}
        else
            cout << "Invalid Input!" << endl;
    }
    while(mainChoice!="2");
    delete [] usrPtr;
    return 0;
}
