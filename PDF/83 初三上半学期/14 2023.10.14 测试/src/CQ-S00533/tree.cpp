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
inline void work(int k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
����˼·:dp[i][0/1][0/1]��ʾ��i����a[i]�ǰ�/��,b[i]�ǰ�/�ڵķ����� 
��1��������dfs
��4��������ǿ���1ǰ���м�����,�𰸾���n
��5�������������dp,dp[i][0/1/2]��ʾǰi����,��i����Ⱦa/b/��Ⱦ�м��ַ��� 
�����ھ���40pts�� 
2-SAT?�϶�����
����O(n^2)������,��dp[i][0/1/2],����ͬ��
ֱ����ǰ�汩��ɨ�� 
���׷���,һ�ζ�ѡһ����֮��,�϶�����һ�ζ�ѡһ,����O(n^2)Ԥ�����,ѡa/b����һ�ζ�ѡһ��λ�� 
*/ 
const ll mod=998244353;
int n,a[1000005],b[1000005],flag,flag1,co[1000005],vis[1000005],ans;
ll f[1000005][3];
void dfs(int now){
	if(now>=n){
		ans++;
		return ;
	}
	if(co[a[now]]||co[b[now]])
		dfs(now+1);
	else{
		co[a[now]]=1;
		dfs(now+1);
		co[a[now]]=0;
		co[b[now]]=1;
		dfs(now+1);
		co[b[now]]=0;
	} 
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		a[i]=read();
		b[i]=read();
		if(a[i]!=1||b[i]!=i+1)
			flag=1;
		if(a[i]!=i||b[i]!=i+1)
			flag1=1;
	}
	if(!flag){
		work(n);
		return 0;
	}
	if(!flag1){
		f[1][0]=f[1][1]=1;
		for(int i=2;i<n;i++){
			f[i][0]=(f[i-1][0]+f[i-1][2])%mod;
			f[i][1]=(f[i-1][0]+f[i-1][2])%mod;
			f[i][2]=f[i-1][1];
		}
		work((f[n-1][0]+f[n-1][1]+f[n-1][2])%mod);
		return 0;
	}
	dfs(1);
	work(ans);
	return 0;
}
