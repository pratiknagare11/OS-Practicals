#include <bits/stdc++.h>
using namespace std;

void fifo(vector<int> string, int n, int frames)
{
    unordered_set<int> s;
    unordered_map<int, int> mp;
    int fault = 0;
    int miss = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(string[i]) == s.end())
            {
                s.insert(string[i]);
                fault++;
            }
            else
            {
                miss++;
            }
            mp[string[i]] = i;
        }
        else
        {
            if (s.find(string[i]) == s.end())
            {
                int lru = INT_MAX;
                int val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (mp[*it] < lru)
                    {
                        lru = mp[*it];
                        val = *it;
                    }
                }

                s.erase(val);
                s.insert(string[i]);
                fault++;
            }
            else
            {
                miss++;
            }

            mp[string[i]] = i;
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