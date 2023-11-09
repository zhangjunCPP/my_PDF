#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
} 
inline void FRE(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
}
typedef pair<int,int> PII;
const int N=5e5+5;
int n,m,ans;
int a[N];
int vis[N];
int main(){
	FRE();
	n=rd(),m=rd();
	for(int i=1;i<=m;++i)a[i]=rd();
	for(int i=1;i<=n;++i){
		set<PII> q;
		for(int i=1;i<=n;++i)vis[i]=0;
		ans=0;
		for(int j=1;j<=m;++j){
			if(vis[a[j]]){
				q.erase({vis[a[j]],a[j]});
				vis[a[j]]=j;
				q.insert({j,a[j]});
			}
			else{
				if(q.size()<i){
					ans++;q.insert({j,a[j]});vis[a[j]]=j;
				}
				else{
					auto u=*(q.begin());
					q.erase(u);
					vis[u.se]=0;
					ans++;
					vis[a[j]]=j;q.insert({j,a[j]}); 
				}
			}
		}
		printf("%d ",ans);
	}
	return 0;
}
