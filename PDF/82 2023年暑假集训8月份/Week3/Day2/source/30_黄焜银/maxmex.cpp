/*
因为mex没有可加性
所以用数据结构来卡时间是困难的
 
如果我们硬算 
时间复杂度O(n*q*log|a|)
应该是有50pts 

注意到subtask3的|a|很小
我们尝试对于每一个答案,二分最小的k 
时间复杂度O(12*log_n*n*log(12)) 

有点小卡,注意常数 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int re(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int n,i,a[N],q,k,ans,vis[N],kk[20]/*ans==i时,最小的k*/;
bool flag3;
set<int>st;
void subtask3(){
	memset(kk,127,sizeof kk);
	for(int z=0;z<=11;++z){
		int l=0,r=n;
		while(l<=r){
			int k=(l+r)>>1;
			for(i=0;i<=11;++i)st.insert(i),vis[i]=0;
			ans=-1;
			for(i=1;i<=n;++i){
				if(!vis[a[i]]++)st.erase(a[i]);
				if(i>=k){
					ans=max(ans,*st.begin());
					if(!--vis[a[i-k+1]])st.insert(a[i-k+1]);
				}
			}
			if(ans>z)r=k-1;
			else if(ans<z)l=k+1;
			else kk[z]=k,r=k-1;
		}
	}
//	for(i=0;i<=11;++i)printf("kk[%d]=%d\n",i,kk[i]);
	q=re();
	while(q--){
		k=re();
		ans=-1;
		for(i=0;i<=11;++i)if(k>=kk[i])ans=i;
		printf("%d\n",ans);
	}
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
//	puts("start");//sb火绒 
	n=re();
	for(i=1;i<=n;++i){
		a[i]=re();
		if(a[i]>10)flag3=1;
	}
	if(!flag3)return subtask3(),0;
	q=re();
	while(q--){
		for(i=0;i<=n+1;++i)st.insert(i),vis[i]=0;
		scanf("%d",&k);//看看重名没
		ans=-1;
		for(i=1;i<=n;++i){
			if(!vis[a[i]]++)st.erase(a[i]);
			if(i>=k){
				ans=max(ans,*st.begin());
				if(!--vis[a[i-k+1]])st.insert(a[i-k+1]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


