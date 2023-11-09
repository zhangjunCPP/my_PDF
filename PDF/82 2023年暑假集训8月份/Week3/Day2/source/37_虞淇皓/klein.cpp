#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,f[1010][1010];
int h(int i,int j){
	return i*n+j;
}
void sol1(){
//	memset(f,127,sizeof(f));
	for(int i=0;i<=h(n,n);i++){
		for(int j=0;j<=h(n,n);j++){
			f[i][j]=1e9;
		}
	}
	for(int i=0;i<=h(n,n);i++)f[i][i]=0;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[h(i,j)][h(i,j-1)]=f[h(i,j-1)][h(i,j)]=1;
		}
		f[h(i,0)][h(i,n)]=f[h(i,n)][h(i,0)]=1;
	}
	for(int j=0;j<=n;j++){
		for(int i=1;i<=n;i++){
			f[h(i,j)][h(i-1,j)]=f[h(i-1,j)][h(i,j)]=1;
		}
		f[h(0,j)][h(n,n-j)]=f[h(n,n-j)][h(0,j)]=1;
	}
	for(int k=0;k<=h(n,n);k++){
		for(int i=0;i<=h(n,n);i++){
			for(int j=0;j<=h(n,n);j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[j][i]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		printf("%lld\n",f[h(x1,y1)][h(x2,y2)]);
	}
}
struct as{
	int x,y,s;
};
map<pair<int,int>,bool>mp; 
void sol2(){
	int x1,x2,y1,y2;
	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
	queue<as>q;
	q.push((as){x1,y1,0});
	mp[make_pair(x1,y1)]=true;
	int ans=0;
	while(!q.empty()){
		as u=q.front(); q.pop();
		int x=u.x,y=u.y,s=u.s;
		if(x==x2&&y==y2){
			ans=s;
			break;
		}
		if(x==0){
			if(!mp.count({n,n-y})){
				mp[{n,n-y}]=true;
				q.push((as){n,n-y,s+1});
			}
		}
		if(x==n){
			if(!mp.count({0,n-y})){
				mp[{0,n-y}]=true;
				q.push((as){0,n-y,s+1});
			}
		}
		if(x!=n){
			if(!mp.count({x+1,y})){
				mp[{x+1,y}]=true;
				q.push((as){x+1,y,s+1});
			}
		}
		int xx=x,yy=(y+1)%(n+1);
		if(!mp.count({xx,yy})){
			mp[{xx,yy}]=true;
			q.push((as){xx,yy,s+1});
		}
		xx=x,yy=(y-1+n+1)%(n+1);
		if(!mp.count({xx,yy})){
			mp[{xx,yy}]=true;
			q.push((as){xx,yy,s+1});
		}
	}
	printf("%lld",ans);
}
void sol3(){
	for(int i=1;i<=q;i++){
		int x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		int ans=abs(x1-x2)+abs(y1-y2);
		ans=min(ans,abs(x1-x2)+min(y1+n-y2,n-y1+y2)+1);
		ans=min(ans,x1+1+abs(n-x2)+min(abs(y2-(n-y1)),min((n-y1)+n-y2,y1+y2)+1));
		ans=min(ans,x2+1+abs(n-x1)+min(abs(y1-(n-y2)),min((n-y2)+n-y1,y2+y1)+1));
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	scanf("%lld%lld",&n,&q);
//	if(n<=10)sol1();
//	else if(q==1)sol2();
//	else 
	sol3();
	return 0;
}


