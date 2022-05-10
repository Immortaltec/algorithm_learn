#include<iostream>
using namespace std;


typedef int ElemType;
typedef struct{
	ElemType Data;//结点数据域
	Stack Next;//结点指针域
}SNode,* Stack;
 //初始化()构建空栈
Stack CreateStack()
{	/*构建一个堆栈的头接待你,返回指针*/
	Stack S;
	S= (Stack)malloc(sizeof(SNode));
	S->Next=NULL;
	return S;
}

//判断堆栈是否是空栈
int isEmpty(Stack S)
{
	return (S->Next == NULL);
}

//Push
void Push(ElemType item,Stack S)
{
	Stack TemCell;
	TemCell = (Stack)malloc(sizeof(Stack));//为这个结点申请空间
	TemCell->Data=item;
	TemCell ->Next=S->Next;
	S->Next=TemCell;
}

ElemType Pop(Stack S)
{
	Stack FirstCell;
	ElemType TopElem;
	if(isEmpty(S))
	{
		printf("堆栈空");return NULL;
	}else{
		FirstCell=S->Next;//临时的栈顶指针,free掉
		S->Next=FirstCell->Next;//栈顶下移一位
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;
	}
}

/*其他应用
深度优先搜索
递归
回溯
*/
