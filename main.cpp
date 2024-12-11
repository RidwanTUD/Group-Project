#include "User.h"

int main()
{
    User users[2] =
    {
        User("Ridwan", "123"),
        User("Eanna", "321"),
    };

    bool programRunning = true; 
    
    while (programRunning) 
    {
        bool loggedIn = false;  // Tracks login status
        int currentUser = -1; // this int is used to know which user is logged in
        while (!loggedIn) //loops while not logged in
        {
            string username, password;
            cout << "Welcome to the task management system! (type 'exit' if you would like to close the program)" << endl;
            cout << "Enter username:\n";
            cin >> username;

            if (username == "exit") // breaks loop if user inputs "exit"
            {
                programRunning = false;
                break; 
            }

            cout << "Enter password:\n";
            cin >> password;

            


            for (int i = 0; i < 2; i++) { //check log in details
                if (users[i].Getusername() == username && users[i].Getpassword() == password)
                {
                    loggedIn = true;
                    currentUser = i;
                    cout << "Logged in user: " << users[i].Getusername() << endl;
                    break; // breaks the loop
                }
            }

            if (!loggedIn) {
                cout << "Invalid username or password. Please try again." << endl;
            }
        }
        
        if (!programRunning) break; // if user typed exit, break the loop
        while (loggedIn)
        {
            int choice; // declare choice variable
            cout << "\nWhat would you like to do?" << endl;
            cout << "1. View Tasks" << endl;
            cout << "2. Add Task" << endl;
            cout << "3. Mark Task as Completed" << endl;
            cout << "4. View Incomplete Tasks" << endl;
            cout << "5. Edit Task" << endl;
            cout << "6. Remove Task" << endl;
            cout << "7. Logout" << endl;
            cin >> choice;
            
            switch (choice) //depending on the choice 1-7 from the input, case 1-7 will execute
            { 
                case 1: //View tasks
                users[currentUser].ViewTasks();
                break;

                case 2: //Assigns Task
                {
                    string name, description, deadline;
                    cin.ignore(); // clears input
                    cout << "Enter task name: ";
                    getline(cin, name); // getline allows spaces in input, unlike cin
                    cout << "\nEnter task description: ";
                    getline(cin, description);
                    cout << "\nEnter task deadline: ";
                    getline(cin, deadline);

                    users[currentUser].AssignTask(name, description, deadline);
                    break;
                }

                case 3: //Mark task Completed
                {
                    int taskNumber;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskNumber;

                    users[currentUser].MarkTaskCompleted(taskNumber);
                    break;
                }

                case 4: //View Incomplete Tasks
                users[currentUser].ViewIncompleteTasks();
                break;

                case 5: // Edit Task
                {
                    int taskNumber;
                    string name, description, deadline;
                    cout << "Enter the task number to be edited: ";
                    cin >> taskNumber;
                    cin.ignore(); // clears input
                    cout << "Enter new task name: ";
                    getline(cin, name); // getline allows spaces in input, unlike cin
                    cout << "\nEnter new task description: ";
                    getline(cin, description);
                    cout << "\nEnter new task deadline: ";
                    getline(cin, deadline);

                    users[currentUser].EditTask(taskNumber, name, description, deadline);
                    break;
                } 

                case 6: // Remove Task
                {
                    int taskNumber;
                    cout << "Enter the task number to be removed: ";
                    cin >> taskNumber;
                    users[currentUser].RemoveTask(taskNumber);
                    break;
                }                

                case 7: //Logs out
                cout << users[currentUser].Getusername() << " logged out" << endl;
                loggedIn = false;
                break;
                
                default: // Error message
                cout << "Invalid choice, enter a number 1-7" << endl;

            }
        }
    }

    cout << "Program closed." << endl;
    return 0;
}


