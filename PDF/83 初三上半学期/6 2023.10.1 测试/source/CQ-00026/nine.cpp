#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,x,y;
signed main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	scanf("%lld%lld%lld",&k,&x,&y);
	if(x<=0&&y<=0){
		x=-x,y=-y;
	}
	if(x>=0&&y>=0){
		if((x+y)%k!=0){
			cout<<-1;return 0;
		}
		else{
			cout<<(x+y)/k<<endl;
			int m=(x+y)/k,a=0,b=0;
			for(int i=1;i<=m;i++){
				if(a<x){
					if(a+k<=x){
						a+=k;
					}
					else{
						b+=k-(x-a);
						a=x;
					}
				}
				else{
					b+=k;
				}
//				cout<<a<<" "<<b<<endl;
				printf("%lld %lld\n",a,b);
			}
		}
	}
	else{
		if(x<0){
			x=-x;
			y=-y;
		}
		if((x-y)%k!=0){
			cout<<-1;return 0;
		}
		else{
			cout<<(x-y)/k<<endl;
			int m=(x-y)/k,a=0,b=0;
			for(int i=1;i<=m;i++){
				if(a<x){
					if(a+k<=x){
						a+=k;
					}
					else{
						b-=k-(x-a);
						a=x;
					}
				}
				else{
					b-=k;
				}
//				cout<<a<<" "<<b<<endl;
				printf("%lld %lld\n",a,b);
			}
		}
	}
	return 0;
}

