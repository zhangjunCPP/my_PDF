//ֻ����һ�����ϲŻ��Ȳ����ѿ���һ���߲���ͨ.��ˮ����.û��թ�� 
#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char bl[100010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(cin>>T;T--;){
		scanf("%d%d%d%s",&n,&m,&k,bl);
		int t=m-n+1;
		for(;m--;)scanf("%*d%*d");
		putchar("PG"[bl[t%k]=='P']),
		putchar('\n');
	}
	return 0;
}
