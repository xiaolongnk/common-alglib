#include <iostream>
#include <cstdlib>
#include <time.h>

#define M 100

#define leftchild(i) (i<<1)+1

using namespace std;

int main(){
	int n=0;
	int ans;
	srand((unsigned)time(NULL));
	while(1){
		cin>>ans;
		cout<< leftchild(ans) <<endl;
	}
	return 0;
}
