/*
t3
前30分可以暴力拿到
后30分，考虑折半搜索 
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=35,INF=0x7fffffff;
int s1,s2,s3,s,ans,n,anss[N],vis[N],a[N];
inline void print(){
//	int num[4]={0,0,0,0};
//	for(int i=1;i<=n;++i)num[anss[i]]+=a[i];
//	printf("%d %d %d\n",num[1],num[2],num[3]);
	for(int i=1;i<=n;++i)printf("%d ",anss[i]);
//	putchar(10);
}
inline void check(){
	int s=max({s1,s2,s3})-min({s1,s2,s3});
	if(s<ans){
		ans=s;
		for(int i=1;i<=n;++i)anss[i]=vis[i];
	}
	if(s==0){
		print();
		exit(0);
	}
}
void dfs(int now){
	if(now>n){
		check();
		return;
	}
	s1+=a[now];vis[now]=1;
	dfs(now+1);
	s1-=a[now];
	s2+=a[now];vis[now]=2;
	dfs(now+1);
	s2-=a[now];
	s3+=a[now];vis[now]=3;
	dfs(now+1);
	s3-=a[now];
}
inline void subtask1(){
	ans=INF;
	dfs(1);
	print();
}
int sum,m;
map<pair<pair<int,int>,int>,ll>mp;
void dfs1(int now,ll f){
	if(now>m){
		mp[{{s1,s2},s3}]=f;
//		printf("mp[{%d,%d,%d}]=%lld\n",s1,s2,s3,f);
		return;
	}
	s1+=a[now];dfs1(now+1,f*3);s1-=a[now];
	s2+=a[now];dfs1(now+1,f*3+1);s2-=a[now];
	s3+=a[now];dfs1(now+1,f*3+2);s3-=a[now];
}
void dfs2(int now,ll f){
	if(now>n){
//		printf("dfs2:(%d,%d,%d) f=%lld\n",s1,s2,s3,f);
		if(mp.count({{sum-s1,sum-s2},sum-s3})){
			ll las=mp[{{sum-s1,sum-s2},sum-s3}];
			for(int i=m;i;--i)anss[i]=las%3+1,las/=3;
			for(int i=n;i>m;--i)anss[i]=f%3+1,f/=3;
			print();
			exit(0);
		}
		return;
	}
	s1+=a[now];dfs2(now+1,f*3);s1-=a[now];
	s2+=a[now];dfs2(now+1,f*3+1);s2-=a[now];
	s3+=a[now];dfs2(now+1,f*3+2);s3-=a[now];
}
inline void subtask2(){
	m=n>>1;
	dfs1(1,0);
	s1=s2=s3=0;
	dfs2(m+1,0);
}
bool flag1;
int i;
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d",&n);
	if(n>15)flag1=1;
	for(i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
	if(sum%3||n<5)subtask1();
	else sum/=3,subtask2();
	return 0;
}
/*
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/
/*
15
1 1 1 1 1 1 1 1 1 1 1 1 1 1 100000
*/
