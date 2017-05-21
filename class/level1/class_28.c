/*****
 * class for queue
 * execrise for queue
 * 2017-05-19 07:00
 * 
 * push
 * pop
 *      head
 *      tail
 *      head == tail  queue is empty
 *      next(tail) == head  queue is full
 *
 * **/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define M 100

typedef struct user_queue * q_ptr;

typedef struct user_queue {
    int _queue_max;
    int _data[M];
    int _head;
    int _tail;
    int (*push)(q_ptr , const int);
    int (*pop)(q_ptr , int *);
    int (*empty)(const q_ptr);
    int (*full)(const q_ptr);
    int (*print)(const q_ptr);
} user_q;

int empty(const q_ptr m_q) {
    if(m_q->_head == m_q->_tail) return 1;
    return 0;
}

int full(const q_ptr m_q) {
    if((m_q->_tail == m_q->_queue_max) && m_q->_head == 0) return 1;
    if(m_q->_tail == m_q->_head - 1) return 1;
    return 0;
}

/***
 * return : -1 for failed;
 *           0 for success;
 * params :  data to push to the queue;
 */
int q_push(q_ptr m_q , const int element) {
    if(full(m_q)) {
        printf("queue is full!\n");
        return -1;
    }
    m_q->_data[m_q->_tail] = element;
    if(m_q->_tail == m_q->_queue_max) m_q->_tail = 0;
    else ++m_q->_tail;
    return 0;
}

/**
 * return: -1 for failed;
 *          0 for success;
 *  params: elements;  data poped from the queue.
 */
int q_pop(q_ptr m_q , int * element) {
    if(empty(m_q)) {
        printf("queue is empty!\n");
        return -1;
    }
    if(m_q->_head == m_q->_queue_max) {
        *element = m_q->_data[m_q->_head];
        m_q->_head = 0;
    } else {
        *element = m_q->_data[m_q->_head];
        ++m_q->_head;
    }
    return 0;
}

int print_queue(const q_ptr m_q) {
    int cnt = m_q->_head;
    while(1) {
        if(cnt == m_q->_tail) break;
        printf("%d  " , m_q->_data[cnt]);
        if(cnt == m_q->_queue_max) {
            cnt = 0;
        } else {
            ++cnt;
        }
    }
    printf("\n");
    return 0;
}

int init(q_ptr mq){
    mq->push  = q_push;
    mq->pop   = q_pop;
    mq->empty = empty;
    mq->full  = full;
    mq->print = print_queue;
    mq->_tail = 0;
    mq->_head = 0;
    mq->_queue_max = M;
}

int main()
{
    q_ptr mmq = (q_ptr) malloc(sizeof(struct user_queue));
    init(mmq);
    for(int i = 0 ; i < 10 ; i++) {
        mmq->push(mmq , i);
    }
    mmq->print(mmq);
    int ele;
    for(int i = 0 ; i < 10 ; i++) {
        mmq->pop(mmq , &ele);
    }
    mmq->print(mmq);

    for(int i = 0 ; i < 3; i++) {
        mmq->push(mmq , i);
    }
    mmq->print(mmq);
    return 0;
}
