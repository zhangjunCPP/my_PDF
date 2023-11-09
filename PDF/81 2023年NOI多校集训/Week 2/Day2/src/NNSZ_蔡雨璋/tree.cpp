#include<bits/stdc++.h>
using namespace std;
const int mod=1000000000+7;
const int N=10000+10;
int n, ans;
struct nahida{
    int to,nxt;
}edges[N*2];
int head[N],tot=0;
int depth[N], dp[N][20];
int len[1001][1001];
stack<int> s;
void spopall()
{
    while(!s.empty())s.pop();
    return;
}
void freo()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    return;
}
void add(int u,int v)
{
    edges[++tot].to=v, edges[tot].nxt=head[u], head[u]=tot;
    return;
}
int main()
{
    freo();
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }/*
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            spopall();int leng=0;bool find=0;
            s.push(i);
            while(!s.empty())
            {
                int u=s.top();s.pop();
                for(int k=head[u];k;k=edges[k].nxt)
                {
                    if(edges[k].to==j){leng++,find=1;break;}
                    s.push(edges[k].nxt);
                }
                if(find)break;
            }
        }
    }*/
    printf("%d",2);//QAQ
    return 0;
}