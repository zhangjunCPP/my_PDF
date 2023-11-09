#include<iostream>
#include<cstdio>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int N=1e6;
unordered_map<int,int>sum;
int tot,t;
ll ans;
queue<int>q;
signed main(){
//	freopen("D:\\down\\count\\count2.in","r",stdin);
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d",&t);
//	t=5;
	while(t--){
		ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=i*j;
				if(sum[x]==0)q.push(x);
				sum[x]+=2;
			}
			int x=i*i;
			if(sum[x]==0)q.push(x);
			sum[x]+=1;
//			if(i%1000==0){
//				printf("%d\n",i);
//			}
		}
		while(!q.empty()){
			int pos=sum[q.front()];
			q.pop();
			ans+=1ll*pos*pos;
		}
		printf("%lld\n",ans);
		if(t)sum.clear();
	}
}
