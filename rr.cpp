#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int rbt;
    int ct;
    int tat;
    int wt;
    int rt;
    int completed;
    int queue;
};

int tq = 0;
vector<int> Rq;

bool compat(process p1, process p2)
{
    if (p1.at == p2.at)
        return p1.pid < p2.pid;
    return p1.at < p2.at;
}

bool comppid(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main()
{
    int n;
    cout << "Enter no of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> tq;

    process p[n];
    int ttat = 0, twat = 0, trt = 0;
    float atat = 0, awt = 0, art = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter at and bt of p" << i + 1 << " : ";
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
        p[i].rbt = p[i].bt;
        p[i].rt = -1;
        p[i].queue = 0;
        p[i].completed = 0;
    }

    sort(p, p + n, compat);

    int count = 0;
    int time = 0;

    while (count < n)
    {
        for (int i = 0; i < n && count < n; i++)
        {
            if (p[i].completed == 1)
                continue;

            if (Rq.empty())
            {
                if (time < p[i].at)
                    time = p[i].at;
                Rq.push_back(i);
                p[i].queue = 1;
            }

            int idx = Rq.front();
            Rq.erase(Rq.begin());

            for (int j = idx + 1; j < n; j++)
            {
                if (p[j].at <= time + min(p[idx].rbt, tq) && p[j].queue == 0)
                {
                    Rq.push_back(j);
                    p[j].queue = 1;
                }
            }

            if (p[idx].rt == -1)
            {
                p[idx].rt = time - p[idx].at;
            }

            if (p[idx].rbt <= tq)
            {
                time += p[idx].rbt;
                p[idx].rbt = 0;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].completed = 1;
                ttat += p[idx].tat;
                twat += p[idx].wt;
                trt += p[idx].rt;
                count++;
            }
            else
            {
                time += tq;
                p[idx].rbt -= tq;
                Rq.push_back(idx);
            }
        }
    }

    sort(p, p + n, comppid);

    cout << "Pid\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct
             << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << endl;
    }

    cout << "Average TAT: " << float(ttat) / n << endl;
    cout << "Average WT: " << float(twat) / n << endl;
    cout << "Average RT: " << float(trt) / n << endl;
    return 0;
}