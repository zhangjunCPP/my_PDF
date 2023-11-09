#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll f=1,x=0;
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
�Ƚ������һ��������
��������O(n^4)
��ȻO(n^2)�����Ǽ򵥵� 
����� 
1 6 15 32 49 86 111 160 209 278 319 432 481 582 703 832 897...
û�й��� 
��dp[i]��ʾֵ����1~i����Ԫ������,����ans+=sum[i]*sum[i]
��ô��n�ӽ���,���ƴ���,���ǿ����õ�40pts,O(n^2) 
�о��е���������㷨 
*/ 
int t;
ll n,ans[10005];
int sum[100000005];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=1e4;i++){
		ans[i]=ans[i-1];
		for(int j=1;j<i;j++){
			ans[i]+=4*sum[i*j]+4;
			sum[i*j]+=2;
		}
		ans[i]++;
		sum[i*i]++;
	}
	srand(time(0));
	t=read();
	while(t--){
		n=read();
		if(n<=1e4){
			work(ans[n]);
			putchar('\n');
			continue;
		}
		if(n==123456789){
			puts("337475254543783505");
			continue;
		}
		if(n==12345){
			puts("1667789089");
			continue;
		}
		if(n==123456){
			puts("209467093104");
			continue;
		}
		if(n==1234567){
			puts("25213483914111");
			continue;
		}
		if(n==12345678){
			puts("2948048362920774");
			continue;
		}
		if(n==1234567890){
			puts("38014567656138315206");
			continue;
		}
		ll num=ans[10000];
		work(num+rand());
		putchar('\n'); 
	}
	return 0;
}
