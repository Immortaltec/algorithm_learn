#include<iostream>
using namespace std;

#define MAXQSIZE 101    //实际是100
#define ERROR 0

typedef int ElemType;

typedef struct {
    ElemType *Data;    //初始化动态分配存储空间
    //或者写成数组,其实一样的QElemType Data[MAXSIZE]
    int front;      //头指针若队列不可,指向队列头元素
    int rear;       //尾指针若队列不空,指向队列尾元素的下一个位置
}QNode,*Queue;

/*起初front和rear都是-1,当插入操作时rear+1,当删除操作时front+1*/

void AddQ(Queue PtrQ,ElemType item)
{
    if((PtrQ->rear+1)%MAXQSIZE==PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MAXQSIZE;
    PtrQ->Data[PtrQ->rear]=item;
}

ElemType Delete(Queue PtrQ)
{
    if(PtrQ->front==PtrQ->rear){
        printf("队列空");
        return ERROR;
    }else{
        PtrQ->front=(PtrQ->front+1)%MAXQSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}
