/*
���û�´���
���������� 

����
���Ǻܸ�����...
���������ڿ��˰ɣ� 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,x,y,i,ans;
char s[N];
void work(){
	scanf("%d%d%d%s",&n,&m,&k,s);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y);
	ans=m-n+1;
	ans%=k;
	printf("%c\n",s[ans]=='P'?'G':'P');
}
int T;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--)work();
	return 0;
}

