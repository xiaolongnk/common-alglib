#include<iostream>

using namespace std;
const int MAXORDER=10;
struct Node
{
	int count;//记录实际关键字个数
	int data[MAXORDER-1];//保存关键字
	Node* branch[MAXORDER];//保存分支
	Node();//构造函数
};
Node::Node()//结点初始化
{
	count=0;
	for(int i=0;i<MAXORDER;i++)
		branch[i]=NULL;
}
enum Error_code {not_present,success,overflow,duplicate_error};

class BTree
{
	Node* root;//根结点
	int order;//阶数
public:
	BTree();//构造函数
	Error_code SearchNode(Node* current,int key,int &position);//在current上查找指定关键字
	Error_code Insert(int key);//插入关键字
	Error_code recursive_Insert(Node* current,int key,int &median,Node*& right_branch);//递归插入关键字
	void push_into(Node* current,int extra_entry,Node* extra_branch,int position);//在current上直接加入关键字和右子树
	void NodeSplit(Node* current,int extra_entry,Node* extra_branch,int position,int &median,Node*& right_branch);//结点分裂
	Error_code Remove(int key);//删除关键字
	Error_code recursive_Remove(Node* current,int key);//递归删除关键字
	void copy_in_predecessor(Node* current,int position);//找到前驱结点并将current关键字替换为前驱结点关键字
	void remove_data(Node* current,int position);//在current（叶结点）上直接删去关键字
	void move_left(Node* current,int position);//从current->branch[position]的最左到current->data[position-1]到current->branch[position-1]的最右
	void move_right(Node* current,int position);//从current->branch[position]的最右到current->data[position]到current->branch[position+1]的最左
	void restore(Node* current,int position);//若current->branch[position]->count不够时，调用restore函数进行左右移或合并
	void combine(Node* current,int position);//将current->branch[position-1],current->data[position-1],current->branch[position]的所有结点合并
	void TreeOutput(Node* current,int totalspaces);//图形化递归输出B树
	void TreeOperationControl();//实现人机交互控制B树
};
BTree::BTree()
{
	root=NULL;
}
// search the key in node current;
// return search status!
Error_code BTree::SearchNode(Node* current,int key,int &position)
{
	position=0;
	while(position<current->count&&key>current->data[position])
		position++;
	if(position<current->count&&key==current->data[position])
		return success;
	else
		return not_present;
}
// expand the node current with given value and pointer!
void BTree::push_into(Node* current,int extra_entry,Node* extra_branch,int position)
{
	for(int i=current->count;i>position;i--)
	{
		current->data[i]=current->data[i-1];
		current->branch[i+1]=current->branch[i];
	}
	current->data[position]=extra_entry;
	current->branch[position+1]=extra_branch;
	current->count++;
}

void BTree::NodeSplit(Node* current,int extra_entry,Node* extra_branch,int position,int &median,Node*& right_branch)
{
	right_branch=new Node;
	int mid=order/2;
	if(position<=mid)//如果插入的关键字位于当前结点左侧
	{
		for(int i=mid;i<order-1;i++)//将current结点的右侧分裂到right_branch结点
		{
			right_branch->data[i-mid]=current->data[i];//关键字拷贝
			right_branch->branch[i+1-mid]=current->branch[i+1];//右子树拷贝
		}
		current->count=mid;
		right_branch->count=order-1-mid;
		push_into(current,extra_entry,extra_branch,position);
	}
	else//如果插入的关键字位于当前结点右侧
	{
		mid++;
		for(int i=mid;i<order-1;i++)//将current结点的右侧分裂到right_branch结点
		{
			right_branch->data[i-mid]=current->data[i];//关键字拷贝
			right_branch->branch[i+1-mid]=current->branch[i+1];//右子树拷贝
		}
		current->count=mid;
		right_branch->count=order-1-mid;
		push_into(right_branch,extra_entry,extra_branch,position-mid);
	}
	median=current->data[current->count-1];
	right_branch->branch[0]=current->branch[current->count];
	current->count--;
}
Error_code BTree::recursive_Insert(Node* current,int key,int &median,Node *&right_branch)
//递归函数实现BTree的插入
//median:需插入上层结点的关键字
//right_branch:需插入上层结点的median的右子树
{
	if(current==NULL)//已到达叶结点以下
	{
		median=key;
		right_branch=NULL;
		return overflow;
	}
	Error_code result;
	int position;
	result=SearchNode(current,key,position);
	if(result==success)//一旦发现已有原关键字，返回重复信号
		return duplicate_error;
	int extra_entry;//需插入当前结点的关键字
	Node* extra_branch;//需插入当前结点的extra_entry的右子树
	result=recursive_Insert(current->branch[position],key,extra_entry,extra_branch);//递归调用
	if(result==overflow)
	{
		if(current->count<order-1)//如果空间够直接插入
		{
			push_into(current,extra_entry,extra_branch,position);
			result=success;
		}
		else//如果不够，则结点分裂
			NodeSplit(current,extra_entry,extra_branch,position,median,right_branch);
	}
	return result;
}
Error_code BTree::Insert(int key)
{
	Error_code result;
	int median;
	Node* right_branch;
	result=recursive_Insert(root,key,median,right_branch);
	if(result==overflow)//如果根结点也在插入时分裂，则树高+1，设置新的根结点
	{
		Node* new_root=new Node;
		new_root->count=1;
		new_root->data[0]=median;
		new_root->branch[0]=root;
		new_root->branch[1]=right_branch;
		root=new_root;
		result=success;
	}
	return result;
}
void BTree::copy_in_predecessor(Node* current,int position)
{
	Node* temp=current->branch[position];
	while(temp->branch[temp->count]!=NULL)
		temp=temp->branch[temp->count];
	current->data[position]=temp->data[temp->count-1];
}
void BTree::remove_data(Node* current,int position)
{
	for(int i=position;i<current->count-1;i++)
		current->data[i]=current->data[i+1];
	current->count--;
}
void BTree::move_left(Node* current,int position)
//从current->branch[position]的最左到current->data[position-1]到current->branch[position-1]的最右
{
	Node* left_branch=current->branch[position-1];
	Node* right_branch=current->branch[position];
	//中到左
	left_branch->data[left_branch->count]=current->data[position-1];
	left_branch->branch[++left_branch->count]=right_branch->branch[0];
	//右到中
	current->data[position-1]=right_branch->data[0];
	//右调整
	for(int i=0;i<right_branch->count-1;i++)
	{
		right_branch->data[i]=right_branch->data[i+1];
		right_branch->branch[i]=right_branch->branch[i+1];
	}
	right_branch->branch[right_branch->count-1]=right_branch->branch[right_branch->count];
	right_branch->count--;
}
void BTree::move_right(Node* current,int position)
//从current->branch[position]的最右到current->data[position]到current->branch[position+1]的最左
{
	Node* left_branch=current->branch[position];
	Node* right_branch=current->branch[position+1];
	//右调整
	right_branch->branch[right_branch->count+1]=right_branch->branch[right_branch->count];
	for(int i=right_branch->count;i>0;i--)
	{
		right_branch->data[i]=right_branch->data[i-1];
		right_branch->branch[i]=right_branch->branch[i-1];
	}
	right_branch->count++;
	//中到右
	right_branch->data[0]=current->data[position];
	right_branch->branch[0]=left_branch->branch[left_branch->count];
	//左到中
	current->data[position]=left_branch->data[left_branch->count-1];
	left_branch->count--;
}
void BTree::combine(Node* current,int position)
//将current->branch[position-1],current->data[position-1],current->branch[position]的所有结点合并
{
	//由对称性，合并到左子树
	Node* left_branch=current->branch[position-1];
	Node* right_branch=current->branch[position];
	left_branch->data[left_branch->count]=current->data[position-1];
	left_branch->branch[++left_branch->count]=right_branch->branch[0];
	for(int i=0;i<right_branch->count;i++)
	{
		left_branch->data[left_branch->count]=right_branch->data[i];
		left_branch->branch[++left_branch->count]=right_branch->branch[i+1];
	}
	delete right_branch;
	for(int i=position-1;i<current->count-1;i++)
	{
		current->data[i]=current->data[i+1];
		current->branch[i+1]=current->branch[i+2];
	}
	current->count--;
}
void BTree::restore(Node* current,int position)
{
	if(position==current->count)
		if(current->branch[position-1]->count>(order-1)/2)
			move_right(current,position-1);
		else
			combine(current,position);
	else if(position==0)
		if(current->branch[1]->count>(order-1)/2)
			move_left(current,position+1);
		else
			combine(current,position+1);
	else if(current->branch[position-1]->count>(order-1)/2)
		move_right(current,position-1);
	else if(current->branch[position+1]->count>(order-1)/2)
		move_left(current,position+1);
	else
		combine(current,position);
}
Error_code BTree::recursive_Remove(Node* current,int key)
{
	Error_code result;
	int position;
	if(current==NULL)//如果最后找到底，说明BTree中不存在关键字，返回not_present
		result=not_present;
	else
	{
		if(SearchNode(current,key,position)==success)//如果找到关键字
		{
			result=success;
			if(current->branch[position]!=NULL)//如果是二度结点
			{
				copy_in_predecessor(current,position);
				recursive_Remove(current->branch[position],current->data[position]);
			}
			else//如果是叶结点
				remove_data(current,position);
		}
		else//如果未找到关键字
			result=recursive_Remove(current->branch[position],key);
		if(current->branch[position]!=NULL)//从n-1层开始
			if(current->branch[position]->count<(order-1)/2)
				restore(current,position);
	}
	return result;
}
Error_code BTree::Remove(int key)
{
	Error_code result;
	result=recursive_Remove(root,key);
	if(root!=NULL&&root->count==0)//根结点因为合并内容为空
		root=root->branch[0];
	return result;
}
void BTree::TreeOutput(Node* current,int totalspaces)
{
	if(current==NULL)//若当前结点指空，返回
		return;
	for(int i=current->count;i>0;i--)
	{
		TreeOutput(current->branch[i],totalspaces+5);//用当前关键字的右子树和totalpaces+5，递归调用TreeOutput
		for(int j=1;j<=totalspaces;j++)//计数输出空格
			cout<<" ";
		cout<<current->data[i-1]<<endl;//输出当前关键字
	}
	TreeOutput(current->branch[0],totalspaces+5);//用最左的分支和totalspaces,递归调用TreeOutput		
}
void BTree::TreeOperationControl()
{
	cout<<"**********建立B树**********\n";
	cout<<"请输入B树阶数：";
	cin>>order;
	cout<<"请输入关键字个数：";
	int num;	
	cin>>num;
	int *p=new int[num];
	cout<<"请为"<<num<<"个关键字赋值:";
	Error_code result;
	for(int i=0;i<num;i++)
	{
		cin>>p[i];
		result=Insert(p[i]);
		if(result==duplicate_error)
			cout<<"有重复关键字"<<p[i]<<endl;
	}
	cout<<"**********建立结束**********\n";
	cout<<"**********已进入命令行模式**********\n";
	char command;
	int dat;
L:	cin>>command;
	if(command=='I'||command=='i')//如果为插入命令
	{
		cout<<"**********插入命令**********\n";
		do
		{
			cin>>dat;
			result=Insert(dat);
			if(result==duplicate_error)
				cout<<"有重复关键字"<<dat<<endl;
			cin>>command;
		}while(command!='#');
		cout<<"**********插入结束**********"<<endl;
	}
	if(command=='D'||command=='d')
	{
		cout<<"**********删除命令**********\n";
		do
		{
			cin>>dat;
			result=Remove(dat);
			if(result==not_present)
				cout<<"没有关键字"<<dat<<"不能删除"<<endl;
			cin>>command;
		}while(command!='#');
		cout<<"**********删除结束**********"<<endl;
	}
	if(command=='P'||command=='p')
	{
		cout<<"**********打印命令**********\n";
		TreeOutput(root,0);
		cout<<"**********打印结束**********\n";
	}
	if(command=='Q'||command=='q')
	{
		cout<<"**********退出命令**********\n";
		cout<<"**********已退出命令行模式**********\n";
		return;
	}
	goto L;
}
int main()
{
	BTree BT;
	BT.TreeOperationControl();
	return 0;
}
