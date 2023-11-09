/*
A chess
其实可以找规律，我们第一层先按照连续的 $p$ 个分成 $p^{k-1}$ 组
第二层我们每 $p$ 组分成一组，这样的一组内的元素自由搭配，会得到 $p^2$ 组，总的就是 $p^k$ 组
再往上，第三层类似，每 $p$ 组分成一组，这样自由搭配会得到 $p^2$ 组，而其中每一组都有 $p^2$ 种搭配
以此类推，答案 $l=\sum\limits_{i=1}^{k-1}p^{k-i-1+2^i}+p^{k-1}$
0~4 5~9 10~14 15~19 20~24 25~29 30~34 35~39 40~44 45~49 50~54 55~59 60~64 65~69 70~74 75~79 80~84 85~89 90~94 95~99 100~104 105~109 110~114 115~119 120~124 
这是 $5^3$，我们来尝试手模
上面列出的共有 $25$ 组
0~24 25~49 50~74 75~99 100~124
现在我们分成了 $5$ 组，每一组内部可以进行搭配，也即是每组内部有 $25$ 组
总共有 $125$ 组
这里的 $5$ 个大组可以搭配出 $5$ 个元素来
这 $5$ 个元素是 $5$ 个小组组成的，对这 $5$ 个小组进行搭配的时候同样可以进一步变成 $5$ 个更小的组
所以我们写一个分治就可以解决构造

（貌似上面的有些问题，但是代码还是要写对的）

*/
#include<bits/stdc++.h>
using namespace std;
int p,k;
int POW[20];
inline void solve(vector<int>id,int lv,int fl)
{
    if(lv==1)
    {
        for(auto it:id)printf("%d ",it);
        putchar(10);
        return;
    }
    vector<int>tmp;
    for(int i=0;i<p;i++)//偏移
    {
        for(int j=0;j<p;j++)
        {
            tmp.clear();
            for(int t=0;t<p;t++)tmp.push_back(id[t]*p+(i*t+j)%p);//搭配
            solve(tmp,lv-1,fl);
        }
    }
    return;
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%d%d",&p,&k);
    POW[0]=1;
    for(int i=1;i<(k<<1);i++)POW[i]=POW[i-1]*p;
    int ans=0;
    for(int i=1;i<=k;i++)ans+=POW[k-2+i];
    printf("%d\n",ans);
    vector<int>tmp;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<POW[k-i];j++)
        {
            tmp.clear();
            for(int t=0;t<p;t++)tmp.push_back(j*p+t);
            solve(tmp,i,i);
        }
    }
    return 0;
}