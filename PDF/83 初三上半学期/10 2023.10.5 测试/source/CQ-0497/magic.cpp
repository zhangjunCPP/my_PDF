#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
�п�����dp,���Ҿ���̰��Ҳ�ǿ����İ�...
���ǿ��ǰ����е������ȼӽ�ȥ(������������Ϊsum[i]),Ȼ���һ��i����ȶ�̬�Ĺ��׾���-sum[i]
��С��������̰��?�ⲻ̫��ʵ
���䳤��<=14,���������ʲô��
���ǿ���dp,��dp[l][r]��ʾ����[l,r]�����ֵ 
��ôdp[i][j]=dp[i+1][j]+val1(val1����[i,i+7]������ô����,���Ƕ��ٸ����׸�i,���ٸ�������) 
������dp��û�п���˳���Ӱ��,�Ǵ����
������?�Ȱ����й��׼���,��ô�Ͱѿ��ɼ�ȥȨֵ,��һ�����ݾͰ���Hack����?
������������? 
����С�ڵ���7��ȥdfs 
����������,����i��val[i]����,��ô�ͷ�i�ͻ�õ�val[i]�Ĺ��� 
*/
int n,l[1005],r[1005],vis[1005],col[1005],a[1005],f;
ll dp[1005][1005],c[1005],ans;
void dfs(int now){
	if(now>n){
		ll sum=0;
		for(int i=1;i<=n;i++){
			col[i]=0;
		}
		for(int i=1;i<=n;i++){
			col[a[i]]=1; 
			for(int j=l[a[i]];j<=r[a[i]];j++){
				if(!col[j])
					sum+=c[a[i]];
			}
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[now]=i;
			vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		l[i]=read();
		r[i]=read();
		c[i]=read();
		if(l[i]!=r[i])
			f=1;
	}
	if(!f){
		work(0);
		return 0;
	}
	if(n<=10){
		dfs(1);
		work(ans);
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			int k=j+i-1;
			dp[j][k]=dp[j+1][k];
			for(int p=j+1;p<=k&&p<=j+7;p++){
				if(p>r[j]){
					if(l[p]<=j)
						dp[j][k]+=c[p];
				}
				else{
					if(c[p]>c[j]&&l[p]<=j)
						dp[j][k]+=c[p];
					else
						dp[j][k]+=c[j];
				}
			}
		}
	}
	work(dp[1][n]);
	return 0;
}
