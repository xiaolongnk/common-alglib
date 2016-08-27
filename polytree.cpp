/*
 *	Implement the polytree!
 *	By ouxiaolong!
 *	2013-5-9
 */

#include <iostream>
#include <stack>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

typedef char eletype;
struct node
{
	node *left;
	node *right;
	eletype data;
	node()
	{
		left=right=NULL;
		data=0;
	}
};

bool ischar(char ch)
{
	return (ch>='a'&&ch<='z' || ch>='A'&&ch<='Z');
}
bool isop(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')') 
		return true;
	return false;
}
bool check(char *str)
{
	for(int i=0; i<strlen(str);i++)
	{
		if(!isop(str[i]) && !ischar(str[i])) return false;
	}
	return true;
}


map< char , int>higher;

bool comp(char ch1, char ch2)
{
	return higher[ch1]<higher[ch2];
}
bool equal( char ch1, char ch2)
{
	return higher[ch1]==higher[ch2];
}

void midtopost(char *mid, char *post)
{
	int imid=0,ipost=0;
	stack <char> mstack;
	for( int i=0; i<strlen(mid);i++)
	{
		if(ischar(mid[i])) post[ipost++]=mid[i];
		else
		{
			if(mstack.empty()) mstack.push(mid[i]);
			else
			{
				if(mstack.top()=='(') mstack.push(mid[i]);
				else if(mid[i]=='(') mstack.push(mid[i]);
				else if( mid[i]==')') 
				{
					while(mstack.top()!='(')
					{
						char ch=mstack.top();
						post[ipost++]=ch;
						mstack.pop();
					}
					mstack.pop();
				}
				else if(comp(mstack.top(),mid[i]))
				{
					mstack.push(mid[i]);
				}
				else if(equal(mstack.top(),mid[i]))
				{
					while(true)
					{
						if(mstack.empty()) break;
						if(!comp(mstack.top(),mid[i]))
						{
							char ch=mstack.top();
							mstack.pop();
							post[ipost++]=ch;
						}
					}
					mstack.push(mid[i]);
				}
				else
				{
					while( !mstack.empty()&&comp(mid[i],mstack.top()) )
					{
						char ch=mstack.top();
						post[ipost++]=ch;
						mstack.pop();
					}
					mstack.push(mid[i]);
				}
			}
		}
	}
	while(!mstack.empty())
	{
		char ch=mstack.top();
		post[ipost++]=ch;
		mstack.pop();
	}
	post[ipost]='\0';
}


void buildtree(char *post,node *&root)
{
	stack<node *> nos;
	root = new node;
	for(int i=0; i<strlen(post); i++)
	{
		if(ischar(post[i]))
		{
			node *temp=new node;
			temp->data=post[i];
			nos.push(temp);
		}
		else if( isop(post[i]))
		{
			node *right=nos.top();
			nos.pop();
			node *left=nos.top();
			nos.pop();
			node *temp=new node;
			temp->data=post[i];
			temp->left = left;
			temp->right=right;
			nos.push(temp);
		}
	}
	root=nos.top();
}

void print(node *ele,int len)
{
	if( ele==NULL ) return;
	print(ele->right,len+3);
	for(int i=0; i<len; i++) cout<<" ";
	cout<<ele->data<<endl;
	print(ele->left,len+3);
}

int countleaf(node *t)
{
	if(t->left==NULL && t->right==NULL) return 1;
	else return countleaf(t->left)+countleaf(t->right);
}

void rotatenode(node *t)
{
	node *temp=t->left;
	t->left = t->right;
	t->right=temp;
}

void rotatetree(node *root)
{
	if(root->left==NULL&&root->right==NULL) return;
	else
	{
		rotatetree(root->left);
		rotatetree(root->right);
		rotatenode(root);
	}
}

//用对列对二叉树进行层序遍历
void travel(node *root)
{
	queue< node *> myqueue;
	myqueue.push(root);
	while(!myqueue.empty())
	{
		node *temp=myqueue.front();
		myqueue.pop();
		cout<<temp->data;
		if(temp->left!=NULL) myqueue.push(temp->left);
		if(temp->right!=NULL) myqueue.push(temp->right);
	}
	cout<<endl;
}


int width(node* bt)//求二叉树bt的最大宽度
{
	if (bt==NULL) return 0; //空二叉树宽度为0
	else 
	{
		node* Q[1000]; //Q是队列，元素为二叉树结点指针，容量足够大
		int front=1,rear=1,last=1;//front队头指针,rear队尾指针,last同层最右结点在队列中的位置
		int temp=0, maxw=0; //temp记局部宽度, maxw记最大宽度
		Q[rear]=bt; //根结点入队列
		while(front<=last) 
		{
			node *p=Q[front++];
			temp++; //同层元素数加1
			if (p->left!=NULL) Q[++rear]=p->left; //左子女入队
			if (p->right!=NULL) Q[++rear]=p->right; //右子女入队
			if (front>last)
			{
				last=rear; if(temp>maxw) maxw=temp; //last指向下层最右元素, 更新当前最大宽度
				temp=0; 
			}
		}
		return maxw; 
	}
}
int main()
{
	char str[100];
	char post[100];
	cin.getline(str,100);
	node *root=NULL;
	higher['+']=0;
	higher['-']=0; 
	higher['*']=1;
	higher['/']=1;
	if(check(str))
	{
		midtopost(str,post);
		buildtree(post,root);
		cout<<post<<endl;
		print(root,0);
		cout<<"Leaf number is:"<<countleaf(root)<<endl;
		cout<<"travel the tree!"<<endl;
		travel(root);
		cout<<"width of the tree:"<<width(root)<<endl;
		rotatetree(root);
		print(root,0);
	}
	else cout<<"Illegal String!"<<endl;

}
