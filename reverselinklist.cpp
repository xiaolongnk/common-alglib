/*
 * this program is to revrese a link list;
 * xiaolongnk
 * 2013-09-21 13:37:04
 * be patient with pointer;
 *
 *
 */
#include <iostream>

using namespace std;

struct node {
	char ch;
	node *next;
}*head,*tail;

void createlist(char *str){
	node *temp;	
	head = new node;
	tail = head;
	temp = head;
	while((*str)!='\0'){
		temp->ch = *str++;
		tail = temp;
		temp->next = new node;
		temp = temp->next;
	}
	tail->next=NULL;
};

void prt(node *p) {
	node *t=p;
	while(t!=NULL) {
		cout<<t->ch<<" ";
		t=t->next;
	}
	cout<<endl;
}

node * getlastelem(){
	node *temp=head;
	node * ans;
	if(temp->next==NULL) return temp;
	while(temp->next->next!=NULL) temp=temp->next;
	ans = temp->next;
	temp->next = NULL;
	return ans;
}

void insert(node *p) {
	node *temp;
	if(p==tail){
		p->next=head;
	}
	else {
		temp=tail;
		while(true) {
			if(temp->next==head) {
				temp->next = p;
				p->next=head;
				break;
			}
			temp = temp->next;
		}
	}
}
void reverse() {
	node *last;
	while(true){
		last = getlastelem();
		if(last==head) break;
		else insert(last);
	}
}

int main() {
	char str[10];
	cin>>str;
	createlist(str);
	prt(head);
	reverse();
	prt(tail);
	return 0;
}









