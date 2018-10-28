#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include"static.h"

struct stack{
    ElemType *base;
    unsigned top;
    unsigned stackSize;

};

typedef stack Stack;

status InitStack(&S);
status ClearStack(&S);
status StackEmpty(S);
status StackLength(S);
status GetTop(S,&e);
status Push(&S,e);
status Pop(&S,&e);


#endif // STATUS_H_INCLUDED
