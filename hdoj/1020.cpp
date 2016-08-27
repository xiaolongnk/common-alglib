/*
 * xiaolongnk
 * 2013-10-23 12:34:02
 * tags: basic
 *
 */

#include <stdio.h>
#include <string.h>

using namespace std;

#define N 10001

char str[N];


/* 
 * from the start point;
 * end if find the different char;
 * return number of the same chars;
 */

int check(int start) {
	int cnt=0;
	for(int i=start; str[i]!='\0'; i++){
		if(str[i]==str[start]) cnt++;
		else break;
	}
	return cnt;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s",str);
		
		// begin the process;
		for(int j=0; j<strlen(str);){
			int tmp=check(j);
			if(tmp>1){
				printf("%d",tmp);
			}
			printf("%c",str[j]);
			j+=tmp;
		}
		printf("\n");
	}
	return 0;
}
