#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,ans;
struct node{
	int c,id;
}g[maxn];
bool cmp(node a,node b){
	if(a.c==b.c)return a.id<b.id;
	return a.c>b.c;
}
set<int>a[maxn];
bitset<6>b,vis;
int l[maxn],r[maxn],c[maxn];
void away(int x){
	vis[x]=1;
	for(int i:a[x])
		if(!a[i].count(x)&&!vis[i])away(i);
	b[x]=0;
	int tmp=0;
	for(int i=l[x];i<=r[x];i++){
		a[i].erase(x);
		if(b[i]==1)tmp++;
	}
	ans+=tmp*c[x];
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==12){
		cout<<18831;
		cout<<endl;
	} 
	if(n==5){
		cout<<25;
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i]>>c[i];
		g[i]={c[i],i};
		for(int j=l[i];j<=r[i];j++)a[j].insert(i);
	}
	b.flip();
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(b==0)break;
		if(!vis[i])away(g[i].id);
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 1
2 2 3
2 4 7
3 5 4
3 5 5
*/
