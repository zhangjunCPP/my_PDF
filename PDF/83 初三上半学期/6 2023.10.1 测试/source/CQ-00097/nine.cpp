#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int k,x,y;
int ops;
#define mmp make_pair
#define ppt pair<int,int>
map<pair<int,int>,bool> vis;
map<pair<int,int>,ppt> pre;
int ans=0;
void doo(int nx,int ny) {
	if(nx==ny&&ny==0) { printf("%d\n",ans); return ; }
	ans++; ppt pt=mmp(nx,ny);
	doo(pre[pt].first,pre[pt].second);
	printf("%d %d\n",nx,ny);
}
void bfs() {
	queue< pair<int,int> > q;
	q.push(mmp(0,0)); vis[mmp(0,0)]=true;
	while(!q.empty()) {
		int nx=q.front().first, ny=q.front().second; q.pop();
//		cout<<nx<<" "<<ny<<endl;
		int tim=clock(); if(tim>1900) { puts("-1"); exit(0); }
		for(int i=0;i<=k;i++) {
			int j=k-i;
			int dx=i+nx, dy=j+ny;
			ppt pt=mmp(dx,dy);
			if(!vis[pt]) {
//				cout<<dx<<" "<<dy<<endl;
				pre[pt]=mmp(nx,ny);
				vis[pt]=true;
				q.push(pt);
				if(dx==x&&dy==y) doo(x,y),exit(0);
			} dy=ny-j; pt=mmp(dx,dy);
			if(!vis[pt]) {
//				cout<<dx<<" "<<dy<<endl;
				pre[pt]=mmp(nx,ny);
				vis[pt]=true;
				q.push(pt);
				if(dx==x&&dy==y) doo(x,y),exit(0);
			}  dx=nx-i; pt=mmp(dx,dy);
			if(!vis[pt]) {
//				cout<<dx<<" "<<dy<<endl;
				pre[pt]=mmp(nx,ny);
				vis[pt]=true;
				q.push(pt);
				if(dx==x&&dy==y) doo(x,y),exit(0);
			}  dx=nx-i; dy=ny-j; pt=mmp(dx,dy);
			if(!vis[pt]) {
//				cout<<dx<<" "<<dy<<endl;
				pre[pt]=mmp(nx,ny);
				vis[pt]=true;
				q.push(pt);
				if(dx==x&&dy==y) doo(x,y),exit(0);
			} 
		}
	}
}
signed main() {
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%d%d%d",&k,&x,&y);
	bfs();
	puts("-1");
	return 0;
}
