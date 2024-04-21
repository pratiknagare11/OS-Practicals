#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

void sstf(vector<int> tracks, int n, int head)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int count = 0;
    vector<int> seq;
    //int curr, diff;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        p.first = abs(tracks[i] - head);
        p.second = tracks[i];
        pq.push(p);
    }

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        count += top.first;
        seq.push_back(top.second);

        head = top.second;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> npq;

        while (!pq.empty())
        {
            auto ctop = pq.top();
            pq.pop();

            int d = abs(ctop.second - head);
            npq.push({d, ctop.second});
        }
        pq = npq;
    }

    cout << "Total number of seek operations = " << count << endl;
    cout << "Seek sequence is:" << endl;
    for (int track : seq)
    {
        cout << track << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of tracks: ";
    cin >> n;
    vector<int> tracks(n);
    cout << "Enter tracks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tracks[i];
    }
    int head;
    cout << "Enter Head: ";
    cin >> head;
    sstf(tracks, n, head);
    return 0;
}

//82,170,43,140,24,16,190
//208