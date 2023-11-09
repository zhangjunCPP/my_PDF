/*
很显然是dp
不然答案根本无法统计
设f[i]表示第i次进入游乐园的最小花费
我们把单程票看作第k+1种时限票，num[k+1]=1,cost[k+1]=one 
已知f[i]
f[i+1~j]=min(f[i+1~j],f[i]+满足要求的票) 

时间复杂度上界O(nkn) 
*/
#include<bits/stdc++.h>
using namespace std;
inline int re(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
const int INF=0x7fffffff;
int n,k,i,one,t[100010],j,l,las;
long long f[100010];
struct B{
	int num,cost;
}a[510];
inline int find(int x,int l,int r){
	int res;
	while(l<=r){
		int mid=(l+r)>>1;
		if(t[mid]>x)r=mid-1;
		else res=mid,l=mid+1;
	}
	return res;
}
inline bool cmp(B x,B y){
	return x.num>y.num;
}
inline long long min(long long x,long long y){
	return x<y?x:y;
}
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	n=re(),k=re();
	t[n+1]=INF;for(i=1;i<=n;++i)t[i]=re();
	for(i=1;i<=k;++i)a[i].num=re(),a[i].cost=re();
	sort(a+1,a+1+k,cmp);
	one=re();
	for(i=1;i<=n;++i)f[i]=INF;
	f[0]=0;
	for(i=0;i<n;++i){//进入游乐园次数 
		if(i){
//			printf("f[%d]=min(f[%d],f[%d]+one)\n",i,i,i-1);
//			printf("%d %d %d+%d\n",f[i],f[i],f[i-1],one);
			f[i]=min(f[i],f[i-1]+one);
		}
		las=n;
		for(j=1;j<=k;++j){//票的种类 
			for(l=find(t[i+1]+a[j].num-1,i,las),las=l;l>i;--l){
//				printf("f[%d]=min(f[%d],f[%d]+cost[%d])\n",l,l,i,j);
//				printf("%d %d %d+%d\n",f[l],f[l],f[i],cost[j]);
				if(f[l]<=f[i]+a[j].cost)break;
				else f[l]=f[i]+a[j].cost;
//				f[l]=min(f[l],f[i]+cost[j]);
			}
		}
	}
	f[n]=min(f[n],f[n-1]+one);
	for(i=1;i<=n;++i)printf("%lld\n",f[i]-f[i-1]);
//	for(i=1;i<=n;++i)printf("%d ",f[i]);
	return 0;
}

