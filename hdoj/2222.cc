#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define N 500000

struct node{
	node *next[26];
	int count;
    char data;
	node *fail;
	node(){
		count = 0;
		for(int i=0; i<26; i++){
			next[i] = NULL;
		}
		fail = NULL;
	}
}*qu[N];

char target[1000001];
char words[51];

void build_tire(node *root, char *s){
	int len = strlen(s);
    node *tmp = root;
    int i=0;
    int tmpi = 0;
    while(i<len){
        tmpi = s[i]-'a';
        if(tmp->next[tmpi]){
            tmp = tmp->next[tmpi];
        }else{
            tmp->next[tmpi] = new node();
            tmp = tmp->next[tmpi];
            tmp->data = s[i];
        }
        i++;
    }
    tmp->count++;
}


void build_fail(node *root){
	int i;
    int head=0,tail=0;
	root->fail = NULL;
	qu[head++] = root;
	while(tail!= head){
		node *temp = qu[tail++];
		node *p = NULL;
		for(i=0; i<26; i++){
			if(temp->next[i]!=NULL){
				if(temp==root) temp->next[i]->fail=root;
				else{
					p=temp->fail;
					while(p!=NULL){
						if(p->next[i]!=NULL){
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if(p==NULL) temp->next[i]->fail = root;
				}
				qu[head++]=temp->next[i];
			}
			
		}
	}
}

int AC_ato(node *root){
    build_fail(root);
    int len,cnt=0,i=0,idx;
    node * p = root;
    len = strlen(target);
    while(target[i]){
        idx = target[i] - 'a';
        while(p->next[idx]==NULL && p!=root) p = p->fail;
        p = p->next[idx];
        if(p==NULL) p = root;
        node *temp = p;
        while(temp!=root && temp->count!=-1){
            cnt+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}

int main(){
	int t,n;
    scanf("%d",&t);
    while(t--){
        node *root = new node();
        scanf("%d",&n);
        while(n--){
            scanf("%s",words);
            build_tire(root,words);
        }
        scanf("%s",target);
        printf("%d\n",AC_ato(root));
    }
}
