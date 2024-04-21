#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main()
{
    int pipe1[2], pipe2[2];
    int status1, status2;
    int mlen = 20;
    char readmsg[mlen];
    char wp1msg[mlen];
    char wp2msg[mlen];
    int n;
    int pid = 0;

    cout << "enter no of msgs: " << endl;
    cin >> n;
    cin.ignore();

    status1 = pipe(pipe1);
    status2 = pipe(pipe2);
    if (status1 == -1 || status2 == -1)
    {
        cout << "Error in pipe creation: " << endl;
    }

    pid = fork();

    if (pid != 0)
    {
        close(pipe1[0]);
        close(pipe2[1]);
        for (int i = 0; i < n; i++)
        {
            cout << "Enter msg in parent" << i + 1 << ": ";
            cin.getline(wp1msg, mlen);

            cout << "In parent: writing msg on pipe1: " << wp1msg << endl;
            write(pipe1[1], wp1msg, strlen(wp1msg) + 1);

            read(pipe2[0], readmsg, sizeof(readmsg));
            cout << "In parent: reading msg on pipe2: " << readmsg << endl;
        }
    }
    else
    {
        close(pipe1[1]);
        close(pipe2[0]);
        for (int i = 0; i < n; i++)
        {
            read(pipe1[0], readmsg, sizeof(readmsg));
            cout << "In child: reading msg on pipe1: " << readmsg << endl;

            cout << "Enter msg in child " << i + 1 << ": ";
            cin.getline(wp2msg, mlen);

            cout << "In child: writing msg on pipe2: " << wp2msg << endl;
            write(pipe2[1], wp2msg, strlen(wp2msg) + 1);
        }
    }
}
