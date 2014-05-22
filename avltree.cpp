/*
 * I try to implement a AVL tree in this cpp!
 * 2013-5-4
 * To be continued!
 * ouxiaolong!
 */

#include <iostream>
#include <stdio.h>
using namespace std;

typedef short eletype;

struct node
{
	eletype data;
	node *left;
	node *right;
	int height;
	node()
	{
		data=0;
		height=0;
		left=right=NULL;
	}
};
// The insert process is a beautiful recursive process!

void llrotate(node *&k3);
void rrrotate(node *&k3);
void lrrotate(node *&k3);
void rlrotate(node *&k3);
int height(node *t);
int Max(int a, int b);

int height( node *t)
{
	return (t==NULL)?-1:t->height;
}
int Max(int a, int b)
{
	return (a>b)?a:b;
}
void insert(node *&oper,eletype dt)
{
	if(oper==NULL)
	{
		oper = new node;
		oper->data = dt;
		oper->height=0;
		return;
	}
	if( dt> oper->data)
	{
		insert(oper->right,dt);
		if( height(oper->right)-height(oper->left)==2)
		{
			if( dt>oper->right->data) rrrotate(oper);
			else rlrotate(oper);
		}
	}
	else
	{
		insert(oper->left,dt);
		if( height(oper->left)-height(oper->right)==2)
		{
			if( dt<oper->left->data) llrotate(oper);
			else lrrotate(oper);
		}
	}
	oper->height=Max(height(oper->left),height(oper->right))+1;
}
// Just implement these 4 rotate functions!
void llrotate(node *&k3)
{
	node *k2;
	k2= k3->left;
	k3->left = k2->right;
	k2->right=k3;
	k3->height = Max(height(k3->left),height(k3->right))+1;
	k2->height = Max(height(k2->left),height(k2->right))+1;
	k3=k2;
}
void rrrotate(node *&k3)
{
	node *k2;
	k2 = k3->right;
	k3->right = k2->left;
	k2->left = k3;
	k3->height = Max(height(k3->left),height(k3->right))+1;
	k2->height = Max(height(k2->left),height(k2->right))+1;
	k3=k2;
}


void lrrotate(node *&k3)
{
	rrrotate(k3->left);
	llrotate(k3);
}
void rlrotate(node *&k3)
{
	llrotate(k3->right);
	rrrotate(k3);
}
// print the tree with a tree form!
void print(node *ele,int len)
{
	if( ele==NULL ) return;
	print(ele->left,len+3);
	for(int i=0; i<len; i++) cout<<" ";
	cout<<ele->data<<endl;
	print(ele->right,len+3);
}
// print the tree in in_order!
void printin(node *ele)
{
	if( ele==NULL ) return;
	printin(ele->left);
	cout<<ele->data<<" ";
	printin( ele->right);
}

int main()
{
	node *root=NULL;
	int num[7]={7,8,4 ,2,3,100};
	insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	print(root,0);
	return 0;
}
