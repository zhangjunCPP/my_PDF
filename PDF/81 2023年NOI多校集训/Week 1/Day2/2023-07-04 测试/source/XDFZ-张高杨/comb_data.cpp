#include<bits/stdc++.h>
using namespace std;
const int N=25;
inline int Rand(){return rand()<<15|rand();}
int main()
{
	freopen("comb.in","w",stdout);
	int *p=new int;
	srand(time(0)*(*p+1));
	delete p;
	int n=Rand()%N+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)printf("%d ",Rand()%n+1);
	return 0;
}
