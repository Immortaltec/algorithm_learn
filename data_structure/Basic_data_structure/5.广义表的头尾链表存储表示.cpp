#include<iostream>
using namespace std;

typedef char AtomType;
typedef enum{ATOM,LIST}ElemTag;
typedef struct GLNode{
    ElemTag tag;
    union{
        AtomType atom;
        struct{
            struct GLNode *hp, *tp;
        }ptr;
    };
}*GList;
