#include<iostream>
#include<stdarg.h>
using namespace std;

#define MAX_ARRRAY_DIM 8    //设置数组维数的最大值
typedef int ElemType;       
typedef struct {
    ElemType *base;     //数组元素基址,由InitArray分配
    int     dim;        //数组维数
    int     *bounds;    //数组维届基址,由InitArray分配
    int     *constants;     //数组函数映像常量基址,由InitArray分配
}Array;
