/*
 * binary search
 * xiaolongnk
 * 2013-09-21 18:50:32
 *	
 */

#include <iostream>

using namespace std;

// search key in a[l,r);
// retur -1 on failure;
// r is the size of the array;
int b_s(int a[], int l,int r,int key) {
	int m;
	while( l<r ) {
		m = ( l + r )>>1;
		if( a[m] == key ) return m;
		if( a[m] < key ) l = m + 1;
		else r = m;
	}
	return -1;
}

int main() {
	int a[100];
	for( int i=0; i<100; i++) {
		a[i] = i+1;
	}
	int key;
	while( true ) {
		cin>> key;
		if( key==-1 ) break;
		if(b_s(a,0,100,key)!=-1) cout<<a[b_s(a,0,100,key)]<<endl;
		else cout<<"Not Found!"<<endl;
	}
	return 0;
}
