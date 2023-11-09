#include<bits/stdc++.h>
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
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
ò�ƿ���ֱ��dp 
������ת��Ϊ�ϲ�Ԫ��
���ִ�����,�������е���Сֵȥ�Һϲ�����
���Ǻ����ߵ����ϲ�,�к�Ч��
���ֵҪô���ϲ�,Ҫô����Сֵ�ϲ�,��������
����Сֵ�ϲ�Ҳ���Կ���,���ֵ���ϲ�
��ô���ǵ�Ŀ���������Сֵ���,�ƺ�����dp��
dp[i][0/1]��ʾǰi��Ԫ�ص�i��Ԫ����i-1�Ƿ�ϲ�����Сֵ 
���ǿ��������µ����ֵ... 
*/
int n,a[200005],b[200005],ans=2e9+1;
void dfs(int k,int mx,int mn){
	if(mx-mn>=ans)
		return ;
	if(k>n){
		ans=min(ans,mx-mn);
		return ;
	}
	dfs(k+1,max(mx,a[k]),min(mn,a[k]));
	if(k<n)
		dfs(k+2,max(mx,a[k]+a[k+1]),min(mn,a[k]+a[k+1]));
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n<=18)
		dfs(1,0,2e9);
	else{
		int mx=0,mn=1e9;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		work(mx-mn);
	}
	work(ans);
	return 0;
}
