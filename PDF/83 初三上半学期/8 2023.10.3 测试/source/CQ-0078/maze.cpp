/*
ͼ��dp��
��ͨdp����д��д���仯��
�� f[i]��ʾ�ĵ�i���㵽�뿪������ٻ���
����һ���㣬�������ӵ�ÿһ���㣬ʱ����ǵ�d[u]+1��
��Ϊwû�зǸ�������һ��vis����ͳ����û�߹�
������f[1]
ʱ��n+m���� 

���ˣ���ô��ôˮ�� 
���ԣ�����ᱬlonglong 
*/

#include<bits/stdc++.h>
#define int long long
void read(int &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}

#define inf 0x3f3f3f3f3f3f
const int maxn=2e5+4;
int n,m,k,s[maxn],d[maxn];
long long dp[maxn];
std::vector<std::pair<int,int> >E[maxn];
bool vis[maxn];
int dfs(int x){
	if(dp[x]<inf)return dp[x];
	if(vis[x])return inf;//������� 
	vis[x]=1;
	std::priority_queue<int>que;
	for(auto v:E[x]){
		int lp=dfs(v.first);
		if(lp!=inf)que.push(-lp-v.second);
	}
	vis[x]=0;
	dp[x]=inf;
	for(int i=1;i<=d[x]&&que.size();++i)que.pop();
	if(que.size())dp[x]=-que.top();
	return dp[x];
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=k;++i)read(s[i]);
	for(int i=1;i<=n;++i)read(d[i]);
	for(int i=1;i<=m;++i){
		int x,y,val;read(x);read(y);read(val);
		E[x].emplace_back(std::make_pair(y,val));
		E[y].emplace_back(std::make_pair(x,val));
	}
	for(int i=1;i<=n;++i)dp[i]=inf;
	for(int i=1;i<=k;++i)dp[s[i]]=0;
	write(dfs(1));
	return 0;
}
