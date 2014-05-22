#include <stdio.h>

using namespace std;


long long comb(int n,int m){
	long long s=1;
	for( int i=0,j=1; i<m;i++){
		s*=n-i;
		for( ; j<=m&&s%j==0;j++) s/=j;
	}
	return s;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("%lld\n",comb(n,m));
	}
	return 0;
}
