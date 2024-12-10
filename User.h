#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using namespace std;

const int Max_Tasks = 10; //initialises a constant integer Max_Tasks

class User // defines class "User"
{
    public:
        User();
        User(string user, string pw);
        virtual ~User();

        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

        void AssignTask(string task); //assigns a task to the user

    protected:

    private:
        string username; //stores username
        string password; // stores password
        string tasks[Max_Tasks]; //creates an array of maximum 10 tasks
        int taskCount; // this int will be used to track how many tasks is assigned to a user
};

#endif // USER_H