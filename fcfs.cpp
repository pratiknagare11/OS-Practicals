#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void fcfs(vector<int> tracks, int n, int head){
	int ans = 0;
	int diff;
	for(int i=0; i<n; i++){
		diff = abs(head - tracks[i]);
		ans += diff;
		head = tracks[i];
	}
	cout<<"count is : "<<ans;
}
int main(){
	int n;
	cout<<"Enter the no. of tracks : "<<endl;
	cin>>n;
	vector<int> tracks(n);
	cout<<"Enter the tracks : "<<endl;
	for(int i=0; i<n; i++){
		cin>>tracks[i];
	}
	int head; 
	cout<<"Enter head : "<<endl;
	cin>>head;
	
	fcfs(tracks, n, head);
	return 0;
}

//82,170,43,140,24,16,190
//642