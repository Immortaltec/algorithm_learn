#include<iostream>
using namespace std;

typedef int ElemType;
/*链表存储结构的定义*/

typedef struct CLinkList{
    ElemType data;
    struct CLinkList *next;
}LNode;
