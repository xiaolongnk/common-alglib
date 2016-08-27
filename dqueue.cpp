/*
 *	Try to implement the dqueue class!
 *	2013-5-8
 */

#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;
typedef int eletype;
#define MAX 1000

class dqueue
{
    eletype *dt;
    int front;
    int tail;
    int size;
    public:
    dqueue()
    {
        dt = NULL;
        front=0,tail=0;
    }
    // create a list with length n;
    void Create(int n)
    {
        dt = new eletype[n];
        size =n;
        front=0;
        tail = size-1;
    }
    void inc(int &t)
    {
        if( t== size-1 ) t=0;
        else  t++;
    }
    void dec( int &t)
    {
        if(t==0) t=size-1;
        else --t;
    }
    void print()
    {
        if( IsEmpty())	cout<<endl;
        else
        {
            int temp=front;
            dec(temp);
            cout<<dt[temp];
            dec(temp);
            for( temp; temp!=tail;dec(temp)) cout<<" "<<dt[temp];
            cout<<endl;
        }
    }
    bool IsFull()
    {
        return tail==front+1;
    }
    bool IsEmpty()
    {
        int temp=tail;
        inc(temp);
        return front==temp;
    }
    void AddLeft(eletype data)
    {
        if( !IsFull())
        {
            dt[front]=data;
            inc(front);
            print();
        }
        else cout<<"FULL"<<endl;

    };
    void AddRight(eletype data)
    {
        if( !IsFull())
        {
            dt[tail]=data;
            dec(tail);
            print();
        }
        else cout<<"FULL"<<endl;

    };
    void DeleteRight()
    {
        if( !IsEmpty())
        {
            inc(tail);
            print();
        }
        else cout<<"EMPTY"<<endl;
    };
    void DeleteLeft()
    {
		if( !IsEmpty())
		{
			dec(front);
			print();
		}
		else cout<<"EMPTY"<<endl;
	};
	void Left()
	{
		if( IsEmpty()) cout<<"EMPTY"<<endl;
		else
		{
			int temp=front;
			dec(temp);
			cout<<dt[temp]<<endl;
		}
	};
	void Right()
	{
		if( IsEmpty()) cout<<"EMPTY"<<endl;
		else
		{
			int temp=tail;
			inc(temp);
			cout<<dt[temp]<<endl;
		}
	};

};

void deal(dqueue &t)
{
	char buffer[100]="";	
	while(true)
	{
		cin.getline(buffer,100);
		char com[20];
		int icom=0;
		int para[20]={0};
		int cont=0;
		int i=0;
		// get the first command!
		while(buffer[i]==' ') i++; //sikp whitespace
		while(buffer[i]<='Z'&&buffer[i]>='A'||buffer[i]>='a'&&buffer[i]<='z')
		{
			com[icom++]=buffer[i++];
		}
		com[icom]='\0';
		//put parameters int array para[];
		//They must be intgers!
		for( i; i<100; i++)
		{
			bool  sign=false;
			while(buffer[i]<='9' && buffer[i]>='0')
			{
				para[cont]=para[cont]*10+buffer[i++]-'0';
				sign=true;
			}
			if(sign)  cont++;
		}
		// now deal with command! just map commands with functions!
		if(!strcmp(com,"AddRight"))
		{
			for( i=0; i<cont; i++)
		 	t.AddRight(para[i]);
		}
		else if(!strcmp(com,"AddLeft"))
		{
			for(i=0; i<cont;i++)
			t.AddLeft(para[i]);
		}
		else if(!strcmp(com,"DeleteLeft"))
		{
			t.DeleteLeft();
		}
		else if(!strcmp(com,"DeleteRight"))
		{
			t.DeleteRight();
		}
		else if(!strcmp(com,"IsFull"))
		{
			if(t.IsFull())	cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else if(!strcmp(com,"IsEmpty"))
		{
			if(t.IsEmpty()) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else if(!strcmp(com,"Left"))
		{
			t.Left();
		}
		else if(!strcmp(com,"Right"))
		{
			t.Right();
		}
		else if(!strcmp(com,"End"))
		{
			break;
		}
		else if(!strcmp(com,"Print"))
		{
			t.print();
		}
		else cout<<"WRONG"<<endl;
	}
}
int main()
{
	dqueue lisme;
	lisme.Create(8);
	deal(lisme);
	return 0;
}

