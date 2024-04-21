#include<bits/stdc++.h>
using namespace std;

int main(){
    int p;
    cout<<"Enter the no. of processes: "<<endl;
    cin>>p;
    int r; 
    cout<<"Enter the no. of resources: "<<endl;
    cin>>r; 

    int alloc[p][r], max_need[p][r], avail[r], rem_need[p][r];
    cout<<"Enter Current Allocation: "<<endl;
    for(int i=0; i<p; i++){
        cout<<"P"<<i<<": ";
        for(int j=0; j<r; j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter Max Need: "<<endl;
    for(int i=0; i<p; i++){
        cout<<"P"<<i<<": ";
        for(int j=0; j<r; j++){
            cin>>max_need[i][j];
        }
    }
    cout<<"Enter Available Resources: "<<endl;
    for(int i=0; i<r; i++){
        cin>>avail[i];
    }

    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            rem_need[i][j] = max_need[i][j] - alloc[i][j];
        }
    }

    cout<<"Allocation Matrix: "<<endl;
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<"\t"<<alloc[i][j];
        }
        cout<<endl;
    }

    cout<<"Max_need Matrix: "<<endl;
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<"\t"<<max_need[i][j];
        }
        cout<<endl;
    }

    cout<<"Remaining_need Matrix: "<<endl;
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<"\t"<<rem_need[i][j];
        }
        cout<<endl;
    }

    int f[p], ans[p], ind = 0;
	for(int i=0; i<p; i++){
		f[i] = 0;
	}

    int y = 0;
    for (int k = 0; k < p; k++)
    {
        for (int i = 0; i < p; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                {
                    if (rem_need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;

                    for (y = 0; y < r; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    
    int flag = 1;
    for (int i = 0; i < p; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            cout << "The following system is not safe";
            break;
        }
    }
    
    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence\n";
        for (int i = 0; i < p - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[p - 1];
    }
    return 0;
}

//max need
// 8 4 3
// 6 2 0
// 3 3 3

// current allocation
// 0 0 1
// 5 2 0
// 2 1 1

//available
// 1 2 2

//safe : p1 p2 p0


//max need
// 8 4 3
// 6 2 0
// 3 3 3

// current allocation
// 0 0 3
// 3 2 0
// 2 1 1

//available
// 3 2 0

//unsafe