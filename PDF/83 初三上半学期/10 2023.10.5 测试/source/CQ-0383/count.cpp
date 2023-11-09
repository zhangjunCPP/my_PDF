#include<bits/stdc++.h> 
using namespace std;
int t,n;
void Freopen(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&t);
	while(t--){
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)if(1ll*i*j%k==0&&1<=1ll*i*j/k&&1ll*i*j/k<=n)ans+=1;
		printf("%d\n",ans);
	}
}
