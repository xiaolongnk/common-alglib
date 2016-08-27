/*
 * Tags: Recursive!
 * Sovle the eight queen problem!
 * if the current position is -1, then it reprents the position is empty
 * and can place one queue!
 */

#include <iostream>

using namespace std;

int pos[9];
int n;
int row=0;
bool isok(int r,int c)
{
    if(pos[r]!=-1) return false;
    for( int i=0; i<=r; i++) 
        if( pos[i]==c) return false;
    for( int i=0; i<=r; i++)
        if( c-pos[i] == r-i||c-pos[i]==i-r) return false;
    return true;
}
void print()
{
    for( int i=0;i<n;i++)
    {
        for( int j=0;j<n;j++)
        {
            if(j==pos[i]) cout<<"Q ";
            else cout<<"* ";
        }
        cout<<endl;
    }
}
int nn=0;
void solve(int row)
{
    if( row==n)
    {
        cout<<"Solver :"<<++nn<<endl;
        print();
    }
    else
    {
        for(int i=0; i<n;i++)
        {
            if( isok(row,i))
            {
                pos[row]=i;
                solve(row+1);	// try the next row!
                pos[row]=-1;	// clear the current position!
            }
        }
    }
}

int main()
{
    cout<<"Please input your N:"<<endl;
    cin>>n;
    for( int i=0; i<n; i++) pos[i]=-1;
    solve(0);
    return 0;
}
