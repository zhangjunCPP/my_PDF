#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
const int maxn=1e5+5;
struct node{
	int num,cost;
}a[maxn],b[maxn];
int n,k,cnt; 
int T[maxn];
inline bool cmp(node X,node Y){
	if(X.cost==Y.cost)return X.num>Y.num;
	return X.cost<Y.cost;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i)T[i]=read();
	for(int i=1;i<=k;++i)b[i].num=read(),b[i].cost=read();
	a[0].cost=read();
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n;++j){
			int l=j,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(T[mid]-T[j]>=b[i].cost)r=mid-1;
				else l=mid;
			}
			if((r-j+1)*a[0].cost>b[i].cost){
				a[++cnt].num=b[i].num,a[cnt].cost=b[i].cost;
				break;
			} 
		}
	}
	if(cnt>1)sort(a+1,a+cnt+1,cmp);
	if(k==0||cnt==0){
		printf("%d ",a[0].cost);
		for(int i=2;i<=n;++i)printf("0 ");
		exit(0);
	}
}
