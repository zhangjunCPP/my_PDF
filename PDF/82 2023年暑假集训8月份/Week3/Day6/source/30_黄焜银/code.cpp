/*
t1
�����ȹ���һ��ȫ0���������ĳ���Ϊn
���ѷ��ִ�ʱ��n�ַ���
���ų����ں������1
�־���ķ���
ÿ���һ��1���������ͻ�����n+1
������1֮��ĳ���һ����len
��ô����������(len-n+1)*(n+1)-1
�պö�Ӧ��Ŀ������ab-1����ʽ
�����������ʱ����
n=b-1
len=a+n-1=a+b-2
�����ܳ��ȸպò��ᳬ��2e5-2
��ֱ������� 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,a,b,n,len;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	n=b-1;
	len=a+b-2;
	for(i=1;i<=n;++i)putchar('0');
	for(i=1;i<=len-n;++i)putchar('1');
	return 0;
}

