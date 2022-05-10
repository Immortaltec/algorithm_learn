#include<iostream>
using namespace std;

typedef char AtomType;
typedef enum{ATOM,LIST}ElemTag;
typedef struct GLNode{
    ElemTag             tag;
    union{
        AtomType        atom;
        struct GLNode   *hp;
    };
    struct GLNode       *tp;
}*GList;
