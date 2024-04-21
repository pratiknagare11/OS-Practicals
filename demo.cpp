#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
    int priority; // Add priority for priority scheduling
};

// Function prototypes
void fcfs(process p[], int n);
void sjf(process p[], int n);
void priorityScheduling(process p[], int n);

int main()
{
    int choice, n;
    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter arrival time and burst time for process " << i + 1 << ": ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].completed = 0;
    }

    cout << "\nChoose the scheduling algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF (Shortest Job First)\n";
    cout << "3. Priority Scheduling\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        fcfs(p, n);
        break;
    case 2:
        sjf(p, n);
        break;
    case 3:
        priorityScheduling(p, n);
        break;
    default:
        cout << "Invalid choice\n";
    }

    return 0;
}

void fcfs(process p[], int n)
{
    int ttat = 0, twat = 0;
    float atat = 0, awt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].ct = p[i].at + p[i].bt;
        }
        else
        {
            p[i].ct = max(p[i - 1].ct, p[i].at) + p[i].bt;
        }
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
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

void sjf(process p[], int n)
{
    // Sort processes by arrival time
    sort(p, p + n, [](const process &a, const process &b) {
        return a.at < b.at;
    });

    int ttat = 0, twat = 0;
    float atat = 0, awt = 0;

    int currtime = 0;
    int completed = 0;

    while (completed != n)
    {
        int index = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currtime && p[i].completed == 0)
            {
                if (p[i].bt < min)
                {
                    min = p[i].bt;
                    index = i;
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

void priorityScheduling(process p[], int n)
{
    int ttat = 0, twat = 0;
    float atat = 0, awt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].ct = p[i].at + p[i].bt;
        }
        else
        {
            p[i].ct = max(p[i - 1].ct, p[i].at) + p[i].bt;
        }
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
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
