/*
 *	Solve the hanio problem!
 */

#include <iostream>

using namespace std;

int nn;

void hanio(char a,char b, char c,int n)
{
    if( n==1 )	cout<<a<<" => "<<c<<endl;
    else{
        hanio(a,c,b,n-1);
        cout<<a<<" => "<<c<<endl;
        hanio(b,a,c,n-1);
    }
}

int main()
{
    cout<<"Please input your n:"<<endl;
    cin>>nn;
    hanio('A','B','C',nn);
    return 0;
}
