#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
const int maxn=1e5+5;
int n,q;
int a[maxn];
int sum[maxn];
inline int solve(int k){
	int l=1,r=1;
	set<int> ed;
	set<int>::iterator it;
	for(int i=0;i<=n;++i)sum[i]=0,ed.insert(i);
	int ANS=0;
	while(r<=n){                 
		sum[a[r]]++;
		if(sum[a[r]]==1){
			ed.erase(a[r]);
		}
		if(r-l+1==k){
			ANS=max(*ed.begin(),ANS);
			sum[a[l]]--;
			if(sum[a[l]]==0){
				ed.insert(a[l]);
			}
			l++;
		}
		r++; 
	}
	return ANS;
}
inline void FRE(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
}
int main(){
	FRE();
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	q=read();
	while(q--){
		int k=read();
		printf("%d\n",solve(k));
	}
	return 0;
}

