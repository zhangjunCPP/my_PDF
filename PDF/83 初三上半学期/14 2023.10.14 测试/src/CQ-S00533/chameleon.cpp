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
		k=-k;
		putchar('-');
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
/*
���׷��ֱ�ɫ��һ���Ǵ����ߵ��м����γ�ȥ��
��Ȼ��ȥ��˳���Ƕ���,���ǿ��Ǵ��⵽��ά��,��ôһ����ɫ����ײҲֻ�����Ա�������ɫ����ײ
��i����ɫ�������ײ2*min(i,n-i+1)-1��,ֱ��ȥά���ǲ���ʵ�� 
*/
int n,k,l;
int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	n=read();
	k=read();
	l=read();
	for(int i=1;i<=k;i++){
		printf("%.1lf\n",rand()%(n*l)+(rand()&1?0.5:0));
	}
	return 0;
}
