#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;

struct node {
    char data;
    struct node *next[26];
    node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
    }
};


void insert(node *root,char *s){
    int len = strlen(s);
    int idx;
    for(int i=0; i<len; i++){
        idx = s[i] - 'a';
        if(root->next[idx]){
            root = root->next[idx];
        }else {
            root->next[idx] = new node;
            root = root->next[idx];
            root->data = s[i];
        }
    }
}

void show(node *root,int idx){
    if(root){
        int cnt = 0;
        int array[26];
        for(int i = 0; i<26; i++){
            if(root->next[i]){
                array[cnt++] = i;
            }
        }

        for(int i=0; i<cnt/2; i++){
            show(root->next[array[i]],idx+5);
        }
        for(int i=0; i<idx; i++){
            printf(" ");
        }
        if(idx==0) printf("root\n");
        else printf("%c\n",root->data);
        for(int i=cnt/2; i<cnt; i++){
            show(root->next[array[i]],idx+5);
        }
    }
}

void bfs(node *root){
    if(root){
        printf("%c",root->data);
        for(int i=0; i<26;i++){
            bfs(root->next[i]);
        }
    }
}

int main(){
    node *root = new node;
    char s[100];
    while(scanf("%s",s)!=EOF){
        if(s[0]=='-') break;
        else insert(root,s);
    }
    show(root,0);
    return 0;
}
