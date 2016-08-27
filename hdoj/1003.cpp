/*
 * 1003 Max Sum Dp
 * 2013-09-20 12:11:11
 * xiaolongnk
 *
 */

#include <iostream>

using namespace std;


int main() {

	int t, n;
	int first=0;	// current max value of the list;
	int mmax=0;	// max value of the sum
	int head,tail,thead;
	int cur;
	cin>>t;		
	for(int i=0; i<t; i++) {
		cin>>n;
		cin>>first;
		mmax=first;
		head=1,tail=1;thead=1;	//start and end position of the list;
		for(int j=0; j<n-1; j++){
			cin>>cur;
			if(first+cur>=cur){
				first=first+cur;
				if(first>mmax){
					mmax=first;
					head=thead;
					tail=j+2;
				}
			}
			else if(first+cur<cur){
				first=cur;
				thead=j+2;
				if(first>mmax) {
					mmax=first;
					head=thead;
					tail=j+2;
				}
			}
		}

		cout<<"Case "<<i+1<<":"<<endl;
		cout<<mmax<<" "<<head<<" "<<tail<<endl;
		if(i<t-1) cout<<endl;
	}
	return 0;
}
