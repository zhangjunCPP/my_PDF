/*
A chess
��ʵ�����ҹ��ɣ����ǵ�һ���Ȱ��������� $p$ ���ֳ� $p^{k-1}$ ��
�ڶ�������ÿ $p$ ��ֳ�һ�飬������һ���ڵ�Ԫ�����ɴ��䣬��õ� $p^2$ �飬�ܵľ��� $p^k$ ��
�����ϣ����������ƣ�ÿ $p$ ��ֳ�һ�飬�������ɴ����õ� $p^2$ �飬������ÿһ�鶼�� $p^2$ �ִ���
�Դ����ƣ��� $l=\sum\limits_{i=1}^{k-1}p^{k-i-1+2^i}+p^{k-1}$
0~4 5~9 10~14 15~19 20~24 25~29 30~34 35~39 40~44 45~49 50~54 55~59 60~64 65~69 70~74 75~79 80~84 85~89 90~94 95~99 100~104 105~109 110~114 115~119 120~124 
���� $5^3$��������������ģ
�����г��Ĺ��� $25$ ��
0~24 25~49 50~74 75~99 100~124
�������Ƿֳ��� $5$ �飬ÿһ���ڲ����Խ��д��䣬Ҳ����ÿ���ڲ��� $25$ ��
�ܹ��� $125$ ��
����� $5$ ��������Դ���� $5$ ��Ԫ����
�� $5$ ��Ԫ���� $5$ ��С����ɵģ����� $5$ ��С����д����ʱ��ͬ�����Խ�һ����� $5$ ����С����
��������дһ�����ξͿ��Խ������

��ò���������Щ���⣬���Ǵ��뻹��Ҫд�Եģ�

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
    for(int i=0;i<p;i++)//ƫ��
    {
        for(int j=0;j<p;j++)
        {
            tmp.clear();
            for(int t=0;t<p;t++)tmp.push_back(id[t]*p+(i*t+j)%p);//����
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