//only passed the example
/*
it's a sb problem.

i spent 2hours and 50min trying to solve this problem.

but i can't,it's so difficult!

who made this problem ?

i will get the lowest points again.
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll p,s;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&p,&s);
	if(p&1)return puts("Impossible"),0;
	if((1+s)*2<p)return puts("Impossible"),0;
	for(ll i=sqrt(s);i;i--){
		ll j=s/i;
		ll nw=2*(i+j)+2*(i*j!=s),mr=s-i*j;
		if(nw==p){
//			cerr<<i<<" "<<j<<endl; 
			for(int w=1;w<=i;w++)putchar('2');
			if(i*j!=s){
				putchar('2');putchar('3');
				for(int w=1;w<s-i*j;w++)putchar('2');
				putchar('3');
				putchar('1');
			}else putchar('3');
			for(int w=s-i*j+1;w<j;w++)putchar('2');
			putchar('3');
			for(int w=1;w<i;w++)putchar('2');
			putchar('3');
			for(int w=1;w<j;w++)putchar('2');
			return 0;
		}if(nw<p){
//			cerr<<i<<' '<<j<<endl;
			ll can=i*j-i-j+1,nd=(p-nw)/2;
			if(can>=(p-nw)/2){
				ll d=j,od=i;
				while(nw<p){
					if(nw+i-1+(d<=mr)>=p){
						od=i+(d<=mr)-(p-nw); 
						break;
					}else nw+=i-1+(d<=mr);d--;
				}
//				cerr<<d<<' '<<od<<endl;
				for(int w=1;w<=i+nd+(i*j!=s);w++)putchar('2');
				putchar('3');
				putchar('3');
				for(int w=i+nd-1;w>i+(mr>1);w--)putchar('2');
				mr=min(mr,d-1);
//				cerr<<mr<<endl;
				putchar('1'); 
				for(int w=2;w<mr;w++)putchar('2');
				if(mr==d-1){
					putchar('3');
					for(int w=i;w>od;w--)putchar('2');
					putchar('1');
					if(od!=1){
						putchar('3');
						for(int w=od-1;w>1;w--)putchar('2');
						if(d!=j){
							putchar('1');
							for(int w=d+1;w<j;w++)putchar('2');
							putchar('3');
						}else putchar('2');
					}else{
						for(int w=d;w<j;w++)putchar('2');
						putchar('3');
					}
				}else{
					if(mr>2){
						putchar('3'),putchar('1');
						for(int w=mr+1;w<d;w++)putchar('2');
						putchar('3');
					}else{
						for(int w=3;w<d;w++)putchar('2');
						putchar('3');
					}
//					cerr<<od<<endl;
					for(int w=i-1;w>od;w--)putchar('2');
					putchar('1');
					if(od!=1){
						putchar('3');
						for(int w=od-1;w>1;w--)putchar('2');
						if(d!=j){
//							cerr<<"sss"<<d<<endl;;
							putchar('1');
							for(int w=d+1;w<j;w++)putchar('2');
							putchar('3');
						}else putchar('2');
					}else{
						for(int w=d;w<j;w++)putchar('2');
						putchar('3');
					}
				}
				putchar('3');
				for(int w=j;w>1;w--)putchar('2');
				return 0;
			} 
		}
	}puts("Impossible");
	return 0;
}
