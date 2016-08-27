/*
 * Elevator  
 * 模拟 
 * xiaolongnk
 * 2013-09-20 10:54:29
 *
 */
#include <iostream>

using namespace std;

#define N 100
int list[N];

int solve(int n) {
	int cur=0;
	int ans=0;
	for(int i=0; i<n; i++) {
		if(list[i]>cur) {
			ans+=(list[i]-cur)*6;
			cur=list[i];
		}
		else if(list[i]<cur) {
			ans+=(cur-list[i])*4;
			cur=list[i];
		}
	}
	ans+=n*5;
	return ans;
}
int main() {

	int task_n;
	while(cin>>task_n) {
		if(!task_n) break;
		for(int i=0; i<task_n; i++) {
			cin>>list[i];
		}
		cout<<solve(task_n)<<endl;
	}
	return 0;
}
