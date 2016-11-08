#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define DEBUG 1

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * tmp = head, *pre = NULL;
    int del_flag = 0;

    while(tmp){
        if(tmp->next){
            if(tmp->val != tmp->next->val){
                if(del_flag == 1){
                    pre->next = tmp->next;
                    pre = pre->next;
                    del_flag = 0;
                }else {
                    pre = tmp;
                    if(DEBUG) {
                        printf("pre updated with :%d \n",tmp->val);
                    }
                }
                tmp = tmp->next;
            }else {
                if(pre == NULL) pre = tmp;
                if (DEBUG) {
                    printf("remove element  %d \n",tmp->next->val);
                }
                tmp->next = tmp->next->next;
                del_flag = 1;
            }
        }else {
            break;
        }
    }
    if(del_flag) {
        if(pre == head) head = NULL;
        else pre->next = NULL;
    }
    return head;
}


void printList(struct ListNode * head)
{
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");

}

int main()
{
    struct ListNode * t1[7];
    for(int i = 0; i< 7; i++){
        t1[i] = malloc(sizeof(struct ListNode));
    }
    t1[0]->val = 1;
    t1[1]->val = 1;
    t1[2]->val = 2;
    t1[3]->val = 2;
    t1[4]->val = 3;
    t1[5]->val = 3;
    t1[6]->val = 3;
    t1[0]->next = t1[1];
    t1[1]->next = t1[2];
    t1[2]->next = t1[3];
    t1[3]->next = t1[4];
    t1[4]->next = t1[5];
    t1[5]->next = t1[6];
    t1[6]->next = NULL;
    printList(t1[0]);
    struct ListNode * hhh = deleteDuplicates(t1[0]);
    printList(hhh);
    
}
