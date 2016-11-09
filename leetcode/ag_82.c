#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define DEBUG 1

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * tmp = head, *pre = NULL;
    while(tmp){
        if(tmp->next){
            if(tmp->val != tmp->next->val){
                if(pre == NULL) {
                    head = tmp;
                }
                pre = tmp;
                if(DEBUG) {
                    printf("pre updated with :%d \n",tmp->val);
                }
            }else {
                while(tmp->next && tmp->val == tmp->next->val){
                    if (DEBUG) {
                        printf("remove element  %d \n",tmp->next->val);
                    }
                    tmp->next = tmp->next->next;
                }
                if( pre ){
                    pre->next = tmp->next;
                    if (DEBUG) {
                        printf("delete element  %d \n",tmp->val);
                    }
                } else {
                    if (DEBUG) {
                        printf("delete element  %d \n",tmp->val);
                    }
                    head = pre;
                }
            }
            tmp = tmp->next;
        } else {
            if(pre == NULL) {
                head =  tmp;
            }
            break;
        }
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
    t1[1]->val = 2;
    t1[2]->val = 3;
    t1[3]->val = 3;
    t1[4]->val = 4;
    t1[5]->val = 4;
    t1[6]->val = 5;
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
