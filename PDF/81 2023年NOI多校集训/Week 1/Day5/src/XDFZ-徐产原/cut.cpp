//dp值具有单调递增的性质
//转移的时候枚举mex（j+1，i）O（20）
//算满足mex值为j对于右端点为i，那么左端点最右是多少
//假设这个j我们从小到大枚举
//那么这个最右的左端点一定越来越靠左
//看成一个扩张的过程，那么一格一格扩张太慢了
//对于每种颜色j直接预处理对于i前面最后一个j在哪里
//就做出来了！！！
//8:30 开始写代码(刚刚好捏)
//8:40 写完代码
//8:53 调试完毕
//这道题应该过了
#include<bits/stdc++.h>
using namespace std;
int n;
int c[500005];
int dp[500005],last[500005],rig[500005][25];
int tot,out[500005];
void Freopen(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<=20;j++)rig[i][j]=rig[i-1][j];
		rig[i][c[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=0x3f3f3f3f;
		for(int k=1;k<=21;k++){//21!
			j=min(j,rig[i][k-1]);
			if(!j)break;
			if(rig[i][k]<j&&dp[i]<dp[j-1]+k){
				dp[i]=dp[j-1]+k;
				last[i]=j-1;
			}
		}
	}
	for(int i=n;1;i=last[i]){
		out[++tot]=i;
		if(!i)break;
	}
	printf("%d %d\n",dp[n],tot-1);
	for(int i=tot;i>=2;i--)
		printf("%d ",out[i]+1);
	/*
	int ans=0;
	bool mark[20];
	for(int i=tot;i>=2;i--){
		memset(mark,0,sizeof(mark));
		for(int j=out[i]+1;j<=out[i-1];j++)mark[c[j]]=1;
		int x=0;
		while(mark[x])++x;
		ans+=x;
	}
	cout<<ans;
	*/
}