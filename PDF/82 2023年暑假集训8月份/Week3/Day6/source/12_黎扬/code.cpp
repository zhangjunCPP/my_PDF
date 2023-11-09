#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll a,b;
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	a=read();
	b=read();
	if(a*b-1<=2e5){
		for(int i=1;i<=a*b-1;i++){
			work(0);
		}
		return 0;
	}
	if(a*b<=3e5){
		if(!(b&1))
			swap(a,b);
		if(!(a&1)){
			work(0);
			ll val=a*b/2-1;
			for(ll i=1;i<=val;i++){
				work(1);
			}
			return 0;
		}
	}
	vector<pair<ll,ll> > q;
	ll val=a*b+2,now=val;
	for(ll i=2;i*i<=now;i++){
		int sum=0;
		while(val%i==0){
			val/=i;
			sum++;
		}
		if(sum)
			q.emplace_back(make_pair(i,sum));
	}
	if(val>1)
		q.emplace_back(make_pair(val,1));
	ll sum=1;
	if(q.size()==1){
		//±¨·Ï 
		
	}
	for(auto i:q){
		while(i.second){
			if(sum*i.first*sum*i.first<=now)
				sum*=i.first;
			else
				break;
			i.second--;
		}
	}
	now/=sum;
	for(int i=1;i<=now-2;i++){
		work(0);
	}
	work(1);
	for(int i=1;i<=sum-2;i++){
		work(0);
	}
	return 0;
}
