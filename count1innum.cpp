/*
 * count 1 in a binary number;
 * xiaolongnk
 * 2013-09-21 20:03:23
 *
 */

#include <iostream>
#include <queue>

using namespace std;
int func(int x) 
{ 
	int countx =0; 
	while(x) 
	{ 
		countx ++; 
		x = x&(x-1); 
	} 
	return countx; 
}
int main()
{
	int a;
	while( true ){
		cin>>a;
		if(a==-1) break;
		cout<<func(a)<<endl;

	}
	return 0;
}
