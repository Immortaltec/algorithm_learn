#include<bits/stdc++.h>
using namespace std;

int K,N,R;
struct Road{
    int d,L,t;
};
vector<vector<Road>> G(110);//邻接表
int minL[110][10010];//minL[i][j]从起点1走到了城市i花了j块钱
int minLen;
int totalLen;
int totalCost;

int visited[110];

void dfs(int s)
{
    if(s==N){
        totalLen=min(totalLen,minLen);
        return ;
    }
    for(int i=0;i<G[s].size();i++)
    {
        Road r=G[s][i];
        if(totalCost+r.t >K)
            continue;
        if(!visited[r.d]){
            if(totalLen+r.L>=minLen)//最优性剪枝
                continue;
            if(totalLen+r.L >= minL[r.d][totalCost+r.t])
                continue;
            minL[r.d][totalCost+r.t]=totalLen+r.L;//更新一下
            totalLen+=r.L;
            totalCost+=r.t;
            visited[r.d]=1;
            dfs(r.d);
            visited[r.d]=0;
            totalLen-=r.L;
            totalCost-=r.t;            
        }
    }
}
int main()
{
    cin>>K>>N>>R;
    for(int i=0;i<=R;++R)
    {
        int s;
        Road r;
        cin>>s>>r.d>>r.L>>r.t;
        if(s!=r.d){
            G[s].push_back(r);
        }
    }

    memset(visited,0,sizeof(visited));
    totalLen=0;
    minLen=1<<30;//设置成一个很大的数
    totalCost=0;
    visited[1]=1;
    for(int i=0;i<110;++i)
        for(int j=0;j<10010;++j)
            minL[i][j]=(1<<30);
    dfs(1);
    if(minLen<(1<<30))
        cout<<minLen<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
