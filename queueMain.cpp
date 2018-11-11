#include<stdio.h>
#include<stdlib.h>

#include"status.h"
#include"queue.h"
#include"queue.cpp"

int main()
{
   //链表实现队列
    //链表实现栈
    ElemType e;
    Queue Q;
    InitQueue(Q);
    for(int i=0;i<10;i++)
    {
        e=i;
        insertQueue(Q,e);
        printf("%d\t",e);
    }
    printf("\n");
   for(int i=0;i<10;i++)
    {
        deleteQueue(Q,e);
        printf("%d\t",e);
    }
    printf("\n");
    return 0;
}
