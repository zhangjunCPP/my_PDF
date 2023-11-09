#include<bits/stdc++.h>
using namespace std;
//设有平行等价类A(a个),B(b个),C(c个)....
//则交点数:a*b+a*c+....+b*c+b*+....+c*.......
//然后规定每次放的size单调增
//然后发现上一个size越小越好 
//《计算量8e8》
//转换柿子就是(n^2-sigma(ai^2))/2 
//欸?打表可知对于50tot<m<=n*(n-1)/2都有1 
//这就是2500的来源(?) 
int dp[510][50*510];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
//	printf("%d\n",(int)clock());
	fill_n((int*)dp,510*50*510,1e9);
	dp[0][0]=1;
	for(int tot=0;tot<=500;tot++)
	for(int cnt=0,lim=tot*50;cnt<=lim;cnt++)
	for(int sz=dp[tot][cnt];tot+sz<=500&&cnt+sz*tot<=(tot+sz)*50;sz++)
	dp[tot+sz][cnt+sz*tot]=min(dp[tot+sz][cnt+sz*tot],sz);
//	freopen("找规律.out","w",stdout);
//	for(int tot=0;tot<=500;printf("\n刚才是%d\n",tot),tot++){
//		int cnt=tot*(tot-1)/2;
//		while(cnt&&dp[tot][cnt-1]<1e8)cnt--;
//		cout<<cnt;assert(cnt<=tot*50);
//	}
//	printf("%d\n",(int)clock());
	int q,n,m;for(cin>>q;q--;){
		scanf("%d%d",&n,&m);
		if(m>n*(n-1)/2)printf("0\n");
		else if(m>n*50)printf("1\n");
		else printf("%d\n",dp[n][m]<1e8?1:0);
	}
	return 0;
}
