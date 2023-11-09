#include<bits/stdc++.h>
using namespace std;
const int N=1000,K=50;
inline int Rand(){return rand()<<15|rand();}
int main()
{
	freopen("happy.in","w",stdout);
	int *p=new int;
	srand(time(0)*(*p+1));
	delete p;
	int n=Rand()%N+1,k=Rand()%(K+1);
	printf("%d %d\n",n,k);
	int st=Rand()%10000+1;
	for(int i=1;i<=n;i++)printf("%d ",st),st+=(Rand()%10000+1);
	putchar(10);
	for(int i=1;i<=k;i++)printf("%d %d\n",Rand()%(int)(1e9)+1,Rand()%(int)(1e9)+1);
	printf("%d",Rand()%(int)(1e9)+1);
	return 0;
}
