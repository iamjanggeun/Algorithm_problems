#include <iostream>
#include <string>
using namespace std;

string board[5];

int main(void)
{
    for (int i = 0; i < 5; i++)
        cin >> board[i];

    for (int i = 0; i < 15; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (i < board[j].length()) 
                cout << board[j][i];
        }
    }

    return 0;
}