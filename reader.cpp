#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
using namespace std;

mutex x, db;
vector<thread> wthread, rthread;
int rc = 0;

void read()
{
    x.lock();
    rc++;
    if (rc == 1)
        db.lock();
    x.unlock();

    cout << rc << " Reader is inside " << endl;
    this_thread::sleep_for(chrono::milliseconds(300));

    x.lock();
    rc--;
    if (rc == 0)
        db.unlock();
    x.unlock();

    cout << rc + 1 << " Reader is leaving" << endl;
}

void write()
{
    cout << "Writer is trying to enter " << endl;
    db.lock();
    cout << "Writer entered " << endl;
    db.unlock();
    cout << "Writer is leaving" << endl;
}

int main()
{
    int n;
    cout << "Enter no of readers: ";
    cin >> n;

    wthread.reserve(n);
    rthread.reserve(n);

    for (int i = 0; i < n; i++)
    {
        rthread.emplace_back(read);
        wthread.emplace_back(write);
    }

    for (int i = 0; i < n; i++)
    {
        rthread[i].join();
        wthread[i].join();
    }

    return 0;
}