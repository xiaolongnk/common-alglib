/*
 *  swap two variable withoud a temp space;
 *	2013-09-20 23:51:52 
 *	xiaolongnk
 */
#include <iostream>

using namespace std;

void exchange(int &a,int &b) {
	a=a-b;
	b=a+b;
	a=b-a;
}

int main(){
	int a,b;
	while(1){
		cin>>a>>b;
		if(!a&&!b) break;
		exchange(a,b);
		cout<<a<<"  "<<b<<endl;
	}
	return 0;
}
