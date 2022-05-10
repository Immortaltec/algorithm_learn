#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

typedef struct S{
    ElemType data[MaxSize];
    int top1;
    int top2;
}*Stack;
void Push(Stack PtrS,ElemType item,int tag)
{
    if(PtrS->top2-PtrS->top1==1)
    {
        printf("堆栈满");
        return ;
    }else{
        if(tag==1)
        {
            PtrS->data[++PtrS->top1]=item;
        }else{
            PtrS->data[--PtrS->top2]=item;    
        }
    }
}

ElemType Pop(Stack PtrS,int tag)
{
    if(tag==1)
    {
        if(PtrS->top1==-1){
            printf("堆栈空");return NULL;
        }else{
            return PtrS->data[(PtrS->top1)--];
        }
    }else{
        if(PtrS->top2==MaxSize){
            printf("堆栈空");return NULL;
        }else{
            return PtrS->data[(PtrS->top2)++];
        }        
    }
}
