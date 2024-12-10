#include "User.h"

int main()
{
    User users[2] =
    {
        User("Ridwan", "123"),
        User("Eanna", "321"),
    };

    bool loggedIn = false;  // Tracks login status

    while (!loggedIn) //loops while not logged in
    {
        string username, password;
        cout << "Enter username:\n";
        cin >> username;
        cout << "Enter password:\n";
        cin >> password;


        for (int i = 0; i < 2; i++) { //check log in details
            if (users[i].Getusername() == username && users[i].Getpassword() == password)
            {
                loggedIn = true;
                cout << "Logged in user: " << users[i].Getusername() << endl;
                break; // breaks the loop
            }
        }

        if (!loggedIn) {
            cout << "Invalid username or password. Please try again." << endl;
        }
    }
    return 0;
}


