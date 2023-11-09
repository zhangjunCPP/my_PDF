#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn=1e5+5; 

struct node {
	ll x;
	ll c;
	ll v;
}D[maxn];

bool cmp(node x,node y) {
	return x.x<y.x;
} 

ll val[40], ans[40];

int main() {
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n,k,L; cin>>n>>k>>L;
	for(ll i=1;i<=n;i++) {
		cin>>D[i].x>>D[i].c;
		char ch; cin>>ch;
		D[i].v=(ch=='L');
	}
	sort(D+1,D+n+1,cmp);
	ll sum=0, lst=0, pos=0;
	for(ll i=1;i<=n;i++) {
		if(D[i].v==0) {
			if(!pos) pos=i;
			else val[sum]+=D[i].x-lst;
			sum=(sum+D[i].c)%k;
			lst=D[i].x;
			ans[D[i].c]+= 2*(L-D[i].x);
		}else {
			ans[D[i].c]+=D[i].x-lst;
			for(ll j=0;j<k;j++) {
				int p=(D[i].c+sum-j+k)%k;
				if(p==0) ans[j]+=(D[i].x+D[pos].x);
				ans[j]+=val[p];
			}
		}
	}
	for(ll i=0;i<k;i++) cout<<fixed<<setprecision(1)<<(double) ans[i]*0.5<<'\n';
	return 0;
}
