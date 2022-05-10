#include<iostream>
using namespace std;

#define LIST_INIT_SIZE 100 //存储空间的初始分配量
#define LISTINCREMENT 10 //存储空间的分配增量
typedef int ElemType;
#define MaxSize 100

typedef struct LNode{
    ElemType Data[MaxSize]; //首基址相当于ElemType elem[MaxSize]
    int last;   //指示最后元素个数,以及最后一个元素的位置
}*List;    

List MakeEmpty()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->last=-1;
    return Ptrl;
}

int Find(ElemType X,List Ptrl)
{
    int i=0;
    while(i<=Ptrl->last&&Ptrl->Data[i]!=X)
        i++;
    if(i>Ptrl->last)return -1;/*没找到*/
    else return i;/*找到*/
}

void Insert(ElemType X,int i,List Ptrl)
{
    int j;
    if(Ptrl->last==MaxSize){
        printf("表满");
        return ;
    }
    if(i<1||i>Ptrl->last+2){
        printf("位置不合法");
        return;
    }
    for(j=Ptrl->last;j>=i-1;j--)
        Ptrl->Data[j+1]=Ptrl->Data[j];
    Ptrl->Data[i-1]=X;
    Ptrl->last++;
    return ;
}

void Delete(int i,List Ptrl)
{
    int j;
    if(i<1||i>Ptrl->last)
    {
        printf("不存在第%d个元素",i);
        return;
    }
    for(j=i;j<=Ptrl->last;j++)
    {
        Ptrl->Data[j-1]=Ptrl->Data[j];
    }
    Ptrl->last--;
    return ;
}

