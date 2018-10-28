#include"static.h"
void InitLinkStack(LinkStack &S){
       //将链式栈S初始化为空
       S=NULL;
}

Status Push(LinkStack &S, SElemType e){
       //对于链式栈S，将元素e入栈
       LinkStack p;
       p=(LinkStack)malloc(sizeof(struct stackNode));  
       if(!p) return OVERFLOW;  
       p->data=e;
       p->next=S; S=p;     //在单链表的首端插入p结点
       return OK;
}

Status Pop(LinkStack &S, SElemType &e) {
     //将链式栈S的栈顶元素出栈并由参数e返回其值
     LinkStack p;
     if(!S) return ERROR;    //栈空，操作出错
     p=S;                   //p指向栈顶元素结点
     S=S->next;        //修改栈顶指针S，指向新栈顶元素
     e=p->data;  
     free(p);
     return OK; 
}

Status getTop(LinkStack S, SElemType &e){
     //取链式栈S的栈顶元素的值
     if(!S) return ERROR;          //栈为空，操作出错
     e=S->data;
     return OK; 
}
