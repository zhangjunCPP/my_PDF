#include<bits/stdc++.h>

using namespace std;
int main()
{
	//freopen("1.in","w",stdout);
	int l,r,t;
	l=1,r=100;   //·¶Î§
	t=10;  //Êý×Ö¸öÊý 
	srand(time(NULL));
	for(long long i=1;i<=t;i++)
	{
		
		int x=rand()%(r-l+1)+l;
		cout<<x<<' ';
	}
	return 0;
}

