#include"../status.h"
#include"../queue.h"
#include<stdio.h>
#include<stdlib.h>

Status InitQueue(Queue &Q)
{
     Node *p = (Node*)malloc(sizeof(Node));
     if(p==NULL)  return ERROR;
     p->next=NULL;
     Q.first=Q.rear=p;
     return OK;   //最好写一下return OK；

}
Status queueIsEmpty(Queue Q)
{
    if(Q.first == Q.rear) return TRUE;
    return FALSE;
}

Status deleteQueue(Queue &Q, ElemType &e)
{
    if(queueIsEmpty(Q)==TRUE)  return ERROR;
    Node *p=Q.first->next;
    e=p->data;
    free(Q.first);
    Q.first=p;
    return OK;
}
void clearQueue(Queue &Q)
{
    while(queueIsEmpty(Q)!=TRUE){
        ElemType e;
        deleteQueue(Q,e);
    }
   //Q.first是头节点，(Q.first)->next是第一个结点

}
Status getFront(Queue Q, ElemType &e)
{
    if(queueIsEmpty(Q)==TRUE)  return ERROR;
    Node *p= Q.first->next;
    e= p->data;
    return OK;
}
Status insertQueue(Queue &Q, ElemType e)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear= p;
    return OK;
}
