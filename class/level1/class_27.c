/****
 * stack 
 * stack execrise
 * 2017-05-21 21:29
 ***/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define M 100

typedef struct stack * s_ptr;

struct stack {
    int _data[M];
    int _max_size;
    int _top;
    int (*empty)(const s_ptr);
    int (*full)(const s_ptr);
    int (*push)(s_ptr , const int );
    int (*pop)(const s_ptr , int *);
};

int stack_empty(const s_ptr ms) {
    if(ms->_top == 0) return 1;
    return 0;
}

int stack_full(const s_ptr  ms) {
    if(ms->_top == ms->_max_size) return 1;
    return 0;
}

int stack_push(s_ptr ms , int element) {
    if(stack_full(ms) == 1) {
        printf("stack is full!\n");
        return -1;
    }
    ms->_data[ms->_top++] = element;
    return 0;
}

int stack_pop(const s_ptr ms , int * element) {
    if(stack_empty(ms)) {
        printf("stack is empty!\n");
        return -1;
    } else {
        (*element) = ms->_data[--ms->_top];
    }
    return 0;
}

void init(s_ptr ms) {
    ms->empty     = stack_empty;
    ms->full      = stack_full;
    ms->push      = stack_push;
    ms->pop       = stack_pop;
    ms->_max_size = M;
    ms->_top      = 0;
}

int main()
{
    s_ptr ms = (s_ptr) malloc(sizeof(struct stack));
    init(ms);
    for(int i = 0 ; i < 3; ++i) {
        ms->push( ms , i );
    }
    int ele;
    ms->pop(ms , &ele);
    printf("data: %d\n" , ele);
    return 0;
}
