#include<bits/stdc++.h>
using namespace std;
int n,m;
int b1[1000005],b2[1000005];
inline void solve1(){
	if(n==1){
		int k;
		scanf("%d",&k);
		for(int j=1,p;j<=k;j++){
			scanf("%d",&p);
			b1[p-1]=1;
		}
		for(int i=m-1;i>=0;i--) printf("%d",b1[i]);
		return ;
	}
	int k;
	scanf("%d",&k);
	for(int j=1,p;j<=k;j++){
		scanf("%d",&p);
		b2[p-1]=1;
	}
	
}
bool dp[1005][1<<10];
int a[15];
inline void solve2(){
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,p;j<=k;j++){
			scanf("%d",&p);
			a[i]|=(1<<(p-1));
		}
	}
	for(int i=0;i<(1<<m);i++) dp[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<m);j++){
			for(int k=0;k<(1<<m);k++){
				if((j&k)==k && (j^k)>=a[i]){
					dp[i][j]|=dp[i-1][k];
				}
			}
		}
	}
	for(int i=0;i<(1<<m);i++){
		if(dp[n][i]){
			for(int j=m-1;j>=0;j--){
				printf("%d",(i>>j)&1);
			}
			return ;
		}
	}
	printf("-1");
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	if((n<=10 && m<=10) || (n<=1000 && m<=5)){
		solve2();
		return 0;
	}
	if(n<=2){
		solve1();
		return 0;
	}
	printf("-1");
	return 0;
}
/*
������һ��
���������a����������
�ڶ������ƿ����е�����˵���ˣ�������ÿһλֻ�ܳ�����һ������ 
��һ������Ҫ����ڵ���b
̰�ĵ��������Ƕ��� b �϶���������С��
��С�Ŀ�����
������
ֱ�Ӵ����λgank����
Ҳ���ԣ���С��
���ݷ�ΧҲ��С���������Ρ�
�Ͳ�Ҫȥ��ֱ�����ˣ��ðɡ� 
���ǲ��ַּ��ɡ� 
*/ 
