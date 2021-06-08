#include<stdlib.h>
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;
void win()
{
    cout<< "\nYou Won :)" <<endl;
}
void lose()
{
     cout<< "\nYou lost :(" <<endl;
}
void tie()
{
    cout<< "\nIts a tie :|" <<endl;
}
int main()
{
    srand(time(0));
    cout<< "1 = Rock" << endl;
    cout<< "2 = Paper" << endl;
    cout<< "3 = Scissor" << endl;
    cout<< "Pick a move: ";
    int userchoice;
    cin>> userchoice;
    int systemchoice = (rand()%3)+1;
    if (userchoice == 1)
    {
        cout<< "You picked rock" << endl;
    }
    else if (userchoice == 2)
    {
        cout<< "You picked paper" << endl;
    }
    else if (userchoice == 3)
    {
        cout<< "You picked scissor" << endl;    }
    else
    {
        cout<< "Choice is not valid" << endl;
        return 1;
    }
    if (systemchoice == 1)
    {
        cout<< "system picked rock" << endl;
    }
    else if (systemchoice == 2)
    {
        cout<< "system picked paper" << endl;
    }
    else if (systemchoice == 3)
    {
        cout<< "system picked scissor" << endl;
    }
    else
    {
        cout<< "Choice is not valid" << endl;
    }

    if(userchoice == systemchoice)
    {
        tie();
    }
    if(userchoice == 1)
    {
        if(systemchoice == 2)
        {
            win();
        }
        else if(systemchoice == 3)
        {
            lose();
        }
    }
    else if(userchoice == 2)
    {
        if(systemchoice == 1)
        {
            win();
        }
        else if(systemchoice == 3)
        {
           lose();
        }
    }
    else if(userchoice == 3)
    {
        if(systemchoice == 1)
        {
            lose();
        }
        else if(systemchoice == 2)
        {
            win();
        }
    }
}
