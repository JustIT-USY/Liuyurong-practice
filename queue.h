#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


#include "status.h"
struct Node
{
    ElemType data;
    Node *next;
};//结点

typedef struct
{
    Node *first;
    Node *rear;
} Queue;//定义队列

//对队列的一些操作
Status InitQueue(Queue &Q);
Status queueIsEmpty(Queue Q);
Status insertQueue(Queue &Q, ElemType e);
Status deleteQueue(Queue &Q, ElemType &e);
void clearQueue(Queue &Q);
Status getFront(Queue Q, ElemType &e);

#endif // QUEUE_H_INCLUDED
