#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll p,a; 
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout); 
	cin>>p>>a;
	if(p&1){
		cout<<"Impossible";
		return 0;
	}
	ll p1=p/2ll;
	ll y=((p1-1ll)/2ll+1ll),x=p1/2ll;
	ll MIN=(p-2)/2,MAX=x*y;
	if(a<MIN || a>MAX){
		cout<<"Impossible";
		return 0;
	}
	ll c=MAX-a;
	ll h,w;
	if(!c) //小小的判断一下 y=1 
		h=w=0ll;
	else
		h=c/(y-1),w=c%(y-1);
	for(int i=1;i<x-h;i++) putchar('2');
	
	if(!w){
		putchar('2');
	} 
	else{
		putchar('3');
		for(int i=1;i<w;i++) putchar('2');
		putchar('1');
	}
	putchar('3');
	for(int i=1;i<y-w-1;i++) putchar('2');
	if(h){
		putchar('1');
		for(int i=1;i<h;i++){
			putchar('2'); 
		}
		putchar('3');
	}
	else{
		putchar('2');
	}
	putchar('3');
	for(int i=1;i<x;i++) putchar('2');
	putchar('3');
	for(int i=1;i<y;i++) putchar('2');
	return 0;
}

