#include<bits/stdc++.h>
using namespace std;
int main()
{
	int *p=new int;
	srand(time(0)*(*p+1));
	delete p;
	int x=rand()%19+1;
	printf("%d %d",x,rand()%(20-x)+1+(x==1));
	return 0;
}
