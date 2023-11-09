#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int Maxn=2e5+5;
struct adjacency_list{
	int nxt,t,val;
}tr[Maxn<<1];
int h[Maxn],tot;
inline void add(int x,int y,int z){
	tr[++tot]={h[x],y,z};h[x]=tot;
}
int a[Maxn],d[Maxn];
int mat[2005][2005];
int  ans[Maxn];
bool tag[Maxn];
int main(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=k;++i)cin>>a[i],tag[a[i]]=1;
	for(int i=1;i<=n;++i)cin>>d[i];
	for(int i=1;i<=m;++i){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
		mat[x][y]=mat[y][x]=z;
	} 
	ans[1]=-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(!tag[j]){
			int cnt=0;
			for(int k=1;k<=n;++k)if(mat[j][k])cnt+=tag[k];
			if(cnt>d[j]){
//				cout<<j<<' '<<cnt<<'\n';
				priority_queue<int>q;
				for(int k=1;k<=n;++k)if(mat[j][k]&&tag[k]){
					q.emplace(ans[k]+mat[k][j]);
//					cout<<"("<<k<<", "<<ans[k]+mat[k][j]<<") ";
					if(q.size()>d[j]+1)q.pop();
				}
//				cout<<'\n';
				ans[j]=q.top();tag[j]=1;
			}
		}
	cout<<ans[1]<<'\n';
	return 0;
}
