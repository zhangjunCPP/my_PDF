#include<bits/stdc++.h>
using namespace std;
const int K=45,N=100000+5;
int n,k,l; 
double ti[K];

int bt=0;
struct node{
	int d,b;
}a[N],b[N];
bool vis[N];
bool cmp(node x,node y){
	return x.d<y.d;
}

inline int find(int x){
	int l=1,r=bt,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(b[mid].d<=x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}

int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	scanf("%d%d%d",&n,&k,&l);
	char ch;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].b>>ch;
		if(ch=='D'){
			ti[a[i].b]+=(double)l-a[i].d;
			b[++bt].b=a[i].b,b[bt].d=a[i].d;
		}
		else vis[i]=1;
	}
	sort(b+1,b+1+bt,cmp);
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		int js=find(a[i].d);
		int color=a[i].b;
		double jl=0.0;//此时距离起点的距离 
		for(int j=js;j>=1;j--){
			ti[color]+=((double)(a[i].d-b[j].d))/2.0-jl;
			color=(color+b[j].b)%k,jl=a[i].d-(a[i].d+b[j].d)/2.0;
		}
		ti[color]+=(double)a[i].d-jl;
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ti[i]);
	}
	return 0;
}
