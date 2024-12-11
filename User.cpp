#include "User.h"

User::User()
{ //default constructor
    username = "";
    password = "";
    taskCount = 0;
}
User::User(string user, string pw)
{ //creates a user with input parameter username and password
    username = user;
    password = pw;
    taskCount = 0;
}

User::~User()
{
    //destrcuctor
}

void User::AssignTask(string task, string description, string deadline) //assigns task, description and deadline
{
    if (taskCount < Max_Tasks)
    {
        tasks[taskCount] = task;
        descriptions[taskCount] = description;
        deadlines[taskCount] = deadline;
        taskCount++; // Increment task count
        cout << "Task has been assigned" << endl;
    } 
    else cout << "Task limit already reached" << endl;
} 

void User::ViewTasks() // outputs all tasks assigned to user with description and deadline
{
    if (taskCount == 0)
    {
       cout << "No tasks assigned" << endl;
    }
    else 
    {
        for(int i=0; i<taskCount; i++)
        {
            cout << i+1 << ". " << tasks[i] << " - " << descriptions[i] << ". Deadline: " << deadlines[i] << endl;

        }
    }
}