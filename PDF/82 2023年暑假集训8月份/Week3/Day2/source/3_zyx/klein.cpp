#include<bits/stdc++.h>
using namespace std;
int n,q,ans,a1,b1,a2,b2;
int dis(int a,int b,int c,int d){
	return abs(a-c)+abs(b-d);
}
int get(int d,int &x,int &y){
	int a=x,b=y;
	if(d==0){x=0;y=n-b;return n-a+1;}
	if(d==1){x=n;y=n-b;return a+1;}
	if(d==2){x=a;y=n;return b+1;}
	if(d==3){x=a;y=0;return n-b+1;}
}
int main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(b1>b2) swap(a1,a2),swap(b1,b2);
		ans=dis(a1,b1,a2,b2);
		for(int i=0;i<=3;i++){
			int a=a1,b=b1,sum=0;
			sum+=get(i,a,b);
			ans=min(ans,sum+dis(a,b,a2,b2));
			for(int j=0;j<=3;j++){
				int x=a,y=b,now=sum;
				now+=get(j,x,y);
				ans=min(ans,now+dis(x,y,a2,b2));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
