/*
 * http://www.clanfei.com/2012/04/373.html
 * this is a good solution;
 * simple caculation
 * 2013-09-20 17:35:51
 * xiaolongnk;
 *
 */

#include <iostream>

using namespace std;

int main() {
	int a,b,n;
	int one=1,two=1,three;
	while(true) {
		cin>>a>>b>>n;
		if(!a&&!b&&!n) break;
		one=1;two=1;
		int temp;
		for(int i=0; i<n-2;i++){
			three=(a*two+b*one)%7;
			one=two;
			two=three;
		}
		cout<<three<<endl;
	}
	return 0;
}
