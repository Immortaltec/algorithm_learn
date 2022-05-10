#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct{
    ElemType data;  //结点数据域
    List next; //结点指针域next是个地址啊
}LNode,*List;

// LNode L;
// List Ptrl;

int  Length(List Ptrl)
{
    List p=Ptrl;/*p指向第一个结点*/
    int j=0;
    while(p)
    {
        p=p->next;/*当前p指向第j个结点*/
        j++;
    }
    return j;
}

List FindKth(int K,List Ptrl)
{
    List p=Ptrl;
    int j=0;
    while(p!=NULL&&j<K)
    {
        p=p->next;
        j++;
    }
    if(j==K)return p;
    else return NULL;
}

List Find(ElemType X,List ptrl)
{
    List p=ptrl;
    while(p!=NULL&&p->data!=X)
    {
        p=p->next;
    }
    return p;
}

List Insert(ElemType X,int i ,List Ptrl)
{
    List p,s;
    if(i==1){
        s=(List)malloc(sizeof(LNode));
        s->data=X;
        s->next=Ptrl;
        return s;
    }
    p=FindKth(i-1,Ptrl);
    if(p!=NULL)
    {
        s=(List)malloc(sizeof(LNode));
        s->data=X;
        s->next=p->next;
        p->next=s;
        return Ptrl;
    }else{
        printf("参数i错误");
        return NULL;
    }
}

List Delete(int i,List Ptrl)
{
    List s,p;
    if(i==1)
    {
        s=Ptrl;
        if(Ptrl!=NULL)Ptrl=Ptrl->next;
        else return NULL;
        free(s);
        return Ptrl;
    }
    p=FindKth(i-1,Ptrl);
    if(p==NULL)
    {
        printf("第%d个结点不存在",i-1);return NULL;
    }else if(p->next==NULL){
        printf("第%d个结点不存在",i);return NULL;
    }else{
        s=p->next;
        p->next=s->next;
        free(s);
        return Ptrl;
    }
}
