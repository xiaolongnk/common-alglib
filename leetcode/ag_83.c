#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode * head)
{
    while(head){
        printf("%d ",(head)->val);
        (head) = (head)->next;
    }
    printf("\n");

}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * tmp = head;
    while(tmp){
        if(tmp->next){
            if(tmp->val != tmp->next->val){
                tmp = tmp->next;
            }else {
                tmp->next = tmp->next->next;
            }
        }else {
            break;
        }
    }
    return head;
}

int main()
{
    struct ListNode * t1[4];
    for(int i = 0; i< 4; i++){
        t1[i] = malloc(sizeof(struct ListNode));
    }
    t1[0]->val = 1;
    t1[1]->val = 2;
    t1[2]->val = 2;
    t1[3]->val = 5;
    t1[0]->next = t1[1];
    t1[1]->next = t1[2];
    t1[2]->next = t1[3];
    t1[3]->next = NULL;
    struct ListNode * hhh = deleteDuplicates(t1[0]);
    printList(hhh);

}




