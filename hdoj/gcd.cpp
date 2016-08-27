#include <stdio.h>


int gcd(int x, int y)
{
	if(x==0) return x;
	if(y==0) return y;
	for(int t; t=x%y;x=y,y=t);
	return y;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF) 
		printf("%d\n",gcd(a,b));
	return 0;
}
