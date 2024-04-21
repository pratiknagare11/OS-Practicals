#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int priority;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};

int main()
{
    int n;
    cout << "Enter no of processes: ";
    cin >> n;

    process p[n];
    int ttat = 0, twat = 0;
    float atat = 0, awt = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter priority, at and bt of p" << i + 1 << " : ";
        p[i].pid = i + 1;
        cin >> p[i].priority >> p[i].at >> p[i].bt;
        p[i].completed = 0;
    }

    int currtime = 0;
    int completed = 0;

    while (completed != n)
    {
        int index = -1;
        int min = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currtime && p[i].completed == 0)
            {
                if (p[i].priority > min)
                {
                    min = p[i].priority;
                    index = i;
                }

                if (p[i].priority == min)
                {
                    if (p[i].at < p[index].at)
                    {
                        min = p[i].priority;
                        index = i;
                    }
                }
            }
        }

        if (index != -1)
        {
            p[index].ct = currtime + p[index].bt;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].completed = 1;
            completed++;
            currtime = p[index].ct;
        }
        else
        {
            currtime++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ttat += p[i].tat;
        twat += p[i].wt;
    }

    cout << "pid\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << " \t" << p[i].at << " \t" << p[i].bt << "\t " << p[i].ct << " \t" << p[i].tat << " \t" << p[i].wt << endl;
    }

    atat = float(ttat) / n;
    awt = float(twat) / n;

    cout << "Average turnaround time : \t" << atat << endl;
    cout << "Average waiting time : \t" << awt << endl;
}

// Priority : 4 5 7 2 1 6
// AT: 0 1 2 3 4 5 
// BT : 4 5 1 2 3 6
// TAT = 10
// WT = 6.5