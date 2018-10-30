#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// static fields to keep track of ids for professors and students
static int prof_cur_id = 1;
static int stud_cur_id = 1;

class Person
{
protected:
    string name;
    int age;
public:
    virtual void getdata()=0; /* pure virtual function, subclass needs to implement it otherwise it's abstract */
    virtual void putdata()=0;
    
};

class Professor : public Person
{
protected:
    int publications;
    int cur_id;
public:
    // constructor saves the professor id and increments the global variable
    Professor(){
        cur_id = prof_cur_id++;
    }
    ~Professor();
    // collect data from the user input
    void getdata(){
        cin >> name >> age >> publications;
    }
    // print data 
    void putdata(){
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
    
};

class Student : public Person
{
protected:
    int marks[6];
    int cur_id;
public:
    // constructor saves the student id and increments the global variable
    Student(){
        cur_id = stud_cur_id++;
    }
    ~Student();
    // collect data from the user input
    void getdata(){
        cin >> name >> age;
        for (int i = 0; i < 6; ++i)
        {
            cin >> marks[i];
        }
    }
    // print data
    void putdata(){
        int sum = 0;
        for (int i = 0; i < 6; ++i)
        {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
    
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}