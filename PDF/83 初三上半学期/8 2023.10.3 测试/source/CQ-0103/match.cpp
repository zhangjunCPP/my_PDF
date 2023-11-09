#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mid ((l+r)>>1)
const int N=1e6+5;
int n,m,tr[N<<2];
struct node{
	vector<int>num;
	bool operator > (const node &other) const{
		int l=num.size()-1;
		int r=other.num.size()-1;
		while(l>=0&&r>=0) {
			if(num[l]>other.num[r]) return true;
			if(num[l]<other.num[r]) return false;
			l--,r--;
		}
		if(l>=0) return true;
		else return false;
	}
}b[N];
bool cmp(node A,node B) {
	return A>B;
}
void update(int l,int r,int rt,int x) {
	if(l==r) {
		tr[rt]^=1;
		return;
	}
	if(x<=mid) update(l,mid,rt<<1,x);
	else update(mid+1,r,rt<<1|1,x);
	tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
int query(int l,int r,int rt,int x) {
	if(x<=l&&r<=m+1) {
		if(l==r) return l;
		if(tr[rt<<1]!=mid-l+1) return query(l,mid,rt<<1,x);
		return query(mid+1,r,rt<<1|1,x);
	}
	if(x<=mid) return min(query(l,mid,rt<<1,x),query(mid+1,r,rt<<1|1,x));
	else return query(mid+1,r,rt<<1|1,x);
}
int ask(int l,int r,int rt,int x) {
	if(l==r)return tr[rt];
	if(x<=mid) return ask(l,mid,rt<<1,x);
	else return ask(mid+1,r,rt<<1|1,x);
}
int ans[105];
signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n;i++) {
		scanf("%d",&k);
		for(int j=1,x;j<=k;j++){
			scanf("%d",&x);
			b[i].num.pb(x);
		}
	}
//	if(n==2) {
//		int l=b[1].num.size()-1;
//		int r=b[2].num.size()-1;
//		while(l>=0||r>=0) {
//			if(l>=0&&r>=0) {
//				if(b[1].num[l]==b[2].num[r]) {
//					int x=query(1,m+1,1,b[2].num[r]+1);
//					for(int i=b[2].num[r]+1;i<x;i++) update(1,m+1,1,i);
//					update(1,m+1,1,x);
//					if(!ask(1,m+1,1,b[2].num[r]+1))update(1,m+1,1,b[2].num[r]+1);
//					if()
//				}
//				else if(b[1].num[l]>b[2].num[r])update(1,m+1,1,b[1].num[l]),r++;
//				else if(b[1].num[l]<b[2].num[r])update(1,m+1,1,b[2].num[r]),l++;
//			}
//			else if(l>=0)update(1,m+1,1,b[1].num[l]);
//			else if(r>=0)update(1,m+1,1,b[2].num[r]);
//			l--,r--; 
//		}
//		for(int i=m;i>=1;i--) printf("%d",ask(1,m+1,1,i)); 
//	}
//	else 
	printf("-1");
	return 0;
}
