/*图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。城堡被分割成m*n(m≤50，n≤50)个方块，每个方块可以有0~4面墙。

输入 
程序从标准输入设备读入数据。第一行是两个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，方块(1,1)的南墙同时也是方块(2,1)的北墙。输入的数据保证城堡至少有两个房间。

输出 
城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。

样例输入 
4 
7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13

样例输出 
5 
9

例：11的二进制为1011，每一位二进制分别表示“南墙”“东墙”“北墙”“西墙”，为1表示有墙，为0表示没墙。
按位与运算符&的使用：如：11&4 <=> 1011 & 0100 = 0000 = 0。相同为1，不同为0。
竖式：1011
        &0100
           -----
           0000
解题思路：
对每个方块，深度优先搜索（DFS），从而给这个方块能够达到的所有位置染色。最后统计出一共有多少种颜色，以及每种颜色的数量。
比如：
1 1 2 2 3 3 3
1 1 1 2 3 4 3
1 1 1 5 3 5 3
1 5 5 5 5 5 3
从而一共有5个房间，最大的房间（1）占据9个格子。
*/
#include<bits/stdc++.h>
using namespace std;

int room[60][60];
int color[60][60];//方块是否染过色的标记
int R,C;//行列数
int maxroomArea=0,roomNumber=0;
int roomArea;
void Dfs(int i,int k)
{
    if(!color[i][k])
        return ;
    ++roomArea;
    color[i][k]=roomNumber;
    if((room[i][k]&1)==0)Dfs(i,k-1);    //向西走
    if((room[i][k]&2)==0)Dfs(i-1,k);    //向北走
    if((room[i][k]&4)==0)Dfs(i,k+1);    //向东走
    if((room[i][k]&8)==0)Dfs(i+1,k);    //向南走
    
}

int main()
{
    cin>>R>>C;
    for(int i=1;i<=R;++i)
    {
        for(int k=1;k<=C;k++)
        {
            cin>>room[i][k];
        }
    }
    memset(color,0,sizeof(color));//全部标记为新点
    for(int i=1;i<=R;++i)
    {
        for(int k=1;k<=C;++k)
        {
            if(!color[i][k])//找到一个新房间
            {
                ++roomNumber;
                roomArea=0;
                Dfs(i,k);//对这个点进行深度优先搜索
                maxroomArea=max(maxroomArea,roomArea);
            }
        }
    }
    cout<<roomNumber<<endl;
    cout<<maxroomArea<<endl;
    return 0;
}
