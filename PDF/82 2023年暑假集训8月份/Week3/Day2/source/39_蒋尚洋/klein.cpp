#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout); 
	cin>>n>>q;
	auto mind=[](int d){return min(d,n+1-d);};
	for(int xa,ya,xb,yb;q--;){
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		if(xa>xb)swap(xa,xb),swap(ya,yb);
		printf("%d\n",min(mind(abs(ya-yb))+xb-xa,xa+1+mind(abs(n-ya-yb))+n-xb));
	}
	return 0;
}
