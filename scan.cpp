#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void sstf(vector<int> tracks, int n, int head, string disha)
{
    int disks = 200;
    int count = 0;
    int diff, curr;
    vector<int> seq;
    vector<int> left;
    vector<int> right;

    if (disha == "left")
        left.push_back(0);
    else
        right.push_back(disks - 1);

    for (auto track : tracks)
    {
        if (track < head)
            left.push_back(track);
        else if (track > head)
            right.push_back(track);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if (disha == "left")
    {
        reverse(left.begin(), left.end());
        for (auto track : left)
        {
            curr = track;
            diff = abs(curr - head);
            count += diff;
            seq.push_back(curr);
            head = curr;
        }
        for (auto track : right)
        {
            curr = track;
            diff = abs(curr - head);
            count += diff;
            seq.push_back(curr);
            head = curr;
        }
    }
    else if (disha == "right")
    {
        for (auto track : right)
        {
            curr = track;
            diff = abs(curr - head);
            count += diff;
            seq.push_back(curr);
            head = curr;
        }
        reverse(left.begin(), left.end());
        for (auto track : left)
        {
            curr = track;
            diff = abs(curr - head);
            count += diff;
            seq.push_back(curr);
            head = curr;
        }
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
    string direction;
    cout << "Enter Direction: ";
    cin >> direction;
    sstf(tracks, n, head, direction);
    return 0;
}
//82,170,43,140,24,16,190
//332