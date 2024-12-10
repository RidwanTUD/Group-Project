#include "User.h"

User::User()
{ //default constructor
    username = "";
    password = "";
    taskCount = 0;
    for(int i=0; i<Max_Tasks; i++)
        tasks[i]="";

}
User::User(string user, string pw)
{ //creates a user with input parameter username and password
    username = user;
    password = pw;
    taskCount = 0;
    for(int i=0; i<Max_Tasks; i++)
        tasks[i]="";

}

User::~User()
{
    //dtor
}