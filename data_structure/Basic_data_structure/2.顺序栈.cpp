//栈:限定在表尾进行插入删除操作的线性表
#include<iostream>
using namespace std;

#define STACK_INIT_SIZE 100 //存储空间的初始分配量
#define STACKINCREMENT 10 //存储空间的分配增量
#define ERROR 0
typedef int SElemType;
#define MaxSize 100 

typedef struct SNode{
    SElemType data[MaxSize];    //栈在构造之前和销毁之后的值为NULL
    int top;     //栈顶指针
}*Stack;

void Push(Stack PtrS,SElemType item)
{
    if(PtrS->top==MaxSize-1)
    {
        printf("堆栈满");return;
    }
    else{
        PtrS->data[++(PtrS->top)]=item;
        return ;
    }
}

SElemType Pop(Stack PtrS)
{
    if(PtrS->top==-1){
        printf("堆栈空");
        return ERROR;
    }else{
        return (PtrS->data[(PtrS->top)--]);
    }
}

