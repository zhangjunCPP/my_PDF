#include<iostream>
using namespace std;
int a,b,c;
inline int read(){
	char x=getchar();int t=0;
	while(!isdigit(x))x=getchar();
	while(isdigit(x))t=(t<<3)+(t<<1)+(x^48),x=getchar();
	return t;
}
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	c=read();
	while(c--)
	{
		a=read();b=read();
		if(!b)puts("1");
		else
		{
			if((b<a-1)||b>(a*(a-1)/2))puts("0");
			else
			{
				int to=1,query=0;
				while(b>=query)
				{
					query+=to,to++;
				}
				query-=(--to)--;
				b-=query;
//				cout<<b<<" "<<query<<" "<<to<<endl;
				if(b<to-1&&b!=0)puts("0");
				else puts("1");
			}
		}
	}
	return 0;
}
