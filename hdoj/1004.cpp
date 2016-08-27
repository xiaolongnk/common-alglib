/*
 * useage of c++ map;
 * xiaolongnk
 * 2013-09-20 17:20:05
 * simple
 */

#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;


map<string,int> mytable;
int main() {
	char s[15];
	int n;
	int maxvalue;
	while(true) {
		cin>>n;
		if(!n) break;
		mytable.clear();
		maxvalue=-100000;
		for(int i=0;i<n; i++) {
			cin>>s;
			mytable[s]++;
		}
		map<string,int>::iterator it,it1;
		for(it=mytable.begin();it!=mytable.end();it++){
			if(maxvalue < it->second){
				maxvalue=it->second;
				it1=it;
			}
		}
		cout<<it1->first<<endl;
	}
	return 0;
}
