#include<bits/stdc++.h>
using namespace std;
int n,m;
int dis(int a,int b,int c,int d){
	return min(abs(b-d),n+1-abs(b-d))+abs(a-c);
}
void Freopen(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b,c,d,ans=0x7fffffff;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=min(ans,dis(a,b,c,d));
		ans=min(ans,dis(n,n-b,c,d)+a+1);
		ans=min(ans,dis(0,n-b,c,d)+n-a+1);
		printf("%d\n",ans);
	}
	return 0;
}

