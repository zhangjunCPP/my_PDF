#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,vis[N],dis[N],k,len;
double ans[N];
struct as{
	double d;
	int col,f;
}a[N];
bool ch(){
	for(int i=1;i<=n;i++){
		if(!vis[i])return 1;
	}
	return 0;
}
signed main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&len);
	for(int i=1;i<=n;i++){
		int d,b;scanf("%d%d",&d,&b);
		string ch;cin>>ch;
		if(ch[0]=='L')a[i]=(as){d,b,-1};
		else a[i]=(as){d,b,1};
	}
	for(double t=0;;t+=0.5){
		if(!ch()){
			break;
		}
		for(int i=1;i<=len*2;i++){
			dis[i]=0;
		}
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			a[i].d=a[i].d+0.5*a[i].f;
			ans[a[i].col]+=0.5;
			if((a[i].d==0&&a[i].f==-1)||(a[i].d==len&&a[i].f==1)){
				vis[i]=1;
				continue;
			}
			int u=a[i].d*2;
			if(dis[u]!=0){
				int x=dis[u];
				if(a[x].f<a[i].f){
					a[x].f=1;a[i].f=-1;
					// cout<<"a";
					int la=a[x].col;
					a[x].col=a[i].col;a[i].col=(la+a[i].col)%k;
				}
				else{
					// cout<<"b";
					a[x].f=-1;a[i].f=1;
					int la=a[i].col;
					a[i].col=a[x].col;a[x].col=(la+a[x].col)%k;	
				}
			}
			else{
				dis[u]=i;
			}
		}
		// cout<<t<<endl;
		// for(int i=0;i<k;i++){
		// 	cout<<ans[i]<<" ";
		// }cout<<endl;
		// for(int i=1;i<=n;i++){
		// 	dis[i]=0;
		// 	cout<<a[i].d<<" "<<a[i].col<<" "<<a[i].f<<"   ";
		// }
		// cout<<endl<<endl;
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ans[i]);
	}
	return 0;
}
/*
g++ chameleon.cpp -o chameleon -std=c++14 -O2 -Wall
./chameleon
*/