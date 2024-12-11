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

        void AssignTask(string task, string description, string deadline); //assigns a task to the user
        void ViewTasks(); // View all Tasks
        void MarkTaskCompleted(int taskNumber);
        void ViewIncompleteTasks();
        void EditTask(int taskNumber,string task, string description, string deadline);
        void RemoveTask(int taskNumber);


    protected:

    private:
        string username; //stores username
        string password; // stores password
        string tasks[Max_Tasks]; //creates an array of maximum 10 tasks
        string descriptions[Max_Tasks]; //creates an array to store task description
        string deadlines[Max_Tasks]; //creates an array to store task deadlines
        bool statuses[Max_Tasks]; //creates an array to store task status. 0 = incomplete, 1 = complete
        int taskCount; // this int will be used to track how many tasks is assigned to a user
        
};

#endif // USER_H