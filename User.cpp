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
        statuses[taskCount] = 0;
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
            cout << i + 1 << ". Task name: " << tasks[i] << ". Description: " << descriptions[i] << ". Deadline: " << deadlines[i] << endl;
            if (statuses[i] == 1)   // if task status = 1, output task completed
            {
                cout << "Status of task: Completed" << endl;    
            }
            else                    // if task status = 0, output task not completed
            {
                cout << "Status of task: Not Completed" << endl;
            }

        }
    }
}

void User::EditTask(int taskNumber,string task, string description, string deadline)
{
    if (taskNumber > 0 && taskNumber <= taskCount)  // Validate task number
    {
        int i = taskNumber - 1;         // taskNumber must be converted to task number in array
        tasks[i] = task;                // Set task name to new task name
        descriptions[i] = description;  // Set task description to new task description
        deadlines[i] = deadline;        // Set task deadline to new task deadline
        statuses[i] = 0;                // Set task completion to incomplete
        cout << "Task number " << taskNumber << " has been edited." << endl;   
    } 
    else    // In case of invalid task number                                    
    {
        cout << "Invalid task number." << endl;
    }    
}


void User::RemoveTask(int taskNumber)   // Remove task
{
    if (taskNumber > 0 && taskNumber <= taskCount)  // Validate task number
    {
        int taskArrayNumber = taskNumber - 1;   // taskNumber must be converted to task number in array
        for (int i = taskArrayNumber; i < taskCount - 1; i++)   // Loop from task number
        {
            tasks[i] = tasks[i + 1];                // Replacing task to be removed by task + 1 initially, then shifting all tasks higher than taskNumber down
            descriptions[i] = descriptions[i + 1];  // Shift description down
            deadlines[i] = deadlines[i + 1];        // Shift deadline down
            statuses[i] = statuses[i + 1];          // Shift status down
        }
        taskCount--;                                // Decrement total number of tasks as a task has been removed
        cout << "Task number " << taskNumber << " has been removed." << endl;
    }
    else    // In case of invalid task number                                    
    {
        cout << "Invalid task number." << endl;
    }
}

void User::MarkTaskCompleted(int taskNumber)
{
    if (taskNumber > 0 && taskNumber <= taskCount)
    {
        statuses[taskNumber - 1] = 1;
        cout << "Task " << taskNumber << " marked as complete." << endl;
    }
    else
    {
        cout << "Invalid task number." << endl;
    }
}

void User::ViewIncompleteTasks()
{   
    bool IncompleteTasksExists = 0;
    for (int i = 0; i < taskCount; i++)
    {
        if (statuses[i] == 0)
        {
            if (IncompleteTasksExists == 0)
            {
                cout << "List of Incomplete Tasks:" << endl;
                IncompleteTasksExists = 1;

            }
                cout << i + 1 << ". Task name: " << tasks[i] << ". Description: " << descriptions[i] << ". Deadline: " << deadlines[i] << endl;
        }
    }
    if (IncompleteTasksExists == 0)
    {
        cout << "No incomplete tasks exist." << endl;
    }
}
