#include<bits/stdc++.h>
using namespace std;
const int N=20;
int main()
{
	freopen("cut.in","w",stdout);
	int *p=new int;
	srand(time(0)*(*p+1));
	delete p;
	int n=rand()%N+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)printf("%d ",rand()%21);
	return 0;
}
