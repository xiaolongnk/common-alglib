/*
 * xiaolongnk
 * 2013-10-23 13:32:41
 * tags: stack
 *
 */

#include <stdio.h>
#include <stack>

using namespace std;
#define N 20

int main(){

	int n;
	char o1[N];
	char o2[N];
	while(scanf("%d%s%s",&n,o1,o2)!=EOF){
		stack<int> s1;
		bool ans[N];
		bool ok=false;

		int i=0,j=0;
		int cnt=0;
		while(true){
			if(s1.empty()){
				if(i<n){
					s1.push(o1[i++]-'0');
					ans[cnt++]=true;
				}
				else{
					ok=true;// find the solution;
					break;
				}
			}
			else {
				int tmp=s1.top();
				if(tmp==o2[j]-'0'){
					s1.pop();
					j++;
					ans[cnt++]=false;
				}
				else{
					if(i==n){
						break;
					}
					else {
						s1.push(o1[i++]-'0');
						ans[cnt++]=true;
					}
				}
			}
		}
		if(ok) {
			// prt ans;
			printf("Yes.\n");
			for(int i=0; i<cnt; i++){
				if(ans[i]){
					printf("in\n");
				}
				else printf("out\n");
			}
			printf("FINISH\n");
		}
		else {
			printf("No.\nFINISH\n");
		}
	}
}
