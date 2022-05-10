#include<iostream>
using namespace std;

#define ERROR 0

typedef int ElemType;

//结点结构
typedef struct Node{
    ElemType Data;
    struct Node *Next;
};
//队列结构
struct QNode{
    struct Node *front;     //指向队头结点
    struct Node *rear;      //指向队尾结点
};
typedef QNode *Queue;

//不带头结点的链式队列出队操作的一个示例
ElemType DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    ElemType FrontElem;

    if(PtrQ->front==NULL){
        printf("队列空");return ERROR;
    }else{
        FrontCell=PtrQ->front;//让它指向队首的元素
        if(PtrQ->front==PtrQ->rear){
            PtrQ->front=PtrQ->rear=NULL;
        }else{
            PtrQ->front=PtrQ->front->Next;
        }
        FrontElem=FrontCell->Data;
        free(FrontCell);
    }
    return FrontElem;
}

void AddQ(Queue PtrQ,ElemType item)
{  
    //定义结点的时候总是要对其进行分配空间
    struct Node * n = (Node*)malloc(sizeof(Node));
    if(n==NULL)
    {
        return ;
    }else{
        n->Data=item;
        n->Next=NULL;
        if(PtrQ->rear=NULL)
        {
            PtrQ->front=PtrQ->rear=n;
        }else{
            PtrQ->rear->Next=n;//让n成为当前的尾部节点下一节点
            PtrQ->rear=n;//尾部指针指向n
        }
    }
}
