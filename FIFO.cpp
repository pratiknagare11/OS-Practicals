#include <bits/stdc++.h>
using namespace std;

void fifo(vector<int> string, int n, int frames)
{
    unordered_set<int> s;
    queue<int> q;
    int fault = 0;
    int miss = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(string[i]) == s.end())
            {
                s.insert(string[i]);
                q.push(string[i]);
                fault++;
            }
            else
            {
                miss++;
            }
        }
        else
        {
            if (s.find(string[i]) == s.end())
            {
                int val = q.front();
                q.pop();

                s.erase(val);
                s.insert(string[i]);
                q.push(string[i]);
                fault++;
            }
            else
            {
                miss++;
            }
        }
    }

    cout << "Faults: " << fault << endl;
    cout << "Hits: " << miss;
}

int main()
{
    cout << "Enter no of frames: ";
    int frames;
    cin >> frames;

    cout << "Enter size of string: ";
    int n;
    cin >> n;

    cout << "Enter string: ";
    vector<int> string(n);
    for (int i = 0; i < n; i++)
    {
        cin >> string[i];
    }

    fifo(string, n, frames);
}
// 7 0 1 2 0 3 0 4 2 3 0 3 1 2 0
// fault :12
//frame : 3