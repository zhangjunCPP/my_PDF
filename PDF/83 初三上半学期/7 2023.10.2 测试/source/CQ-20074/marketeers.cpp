#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
set<int> s;

int n;
int lsh[500005],tot;
vector<int> S[500005];
pair<int,int> a[500005];
struct BIT{
	int tr[500005];
	int st[500005],top;
	int askmn(int x){int ans=0;for(;x;x-=(x&-x))ans=(tr[x]+ans)%p;return ans;}
	int askmx(int x){return (askmn(tot+1)-askmn(x)+p)%p;}
	void add(int x,int y){st[++top]=x;for(;x<=tot+1;x+=(x&-x))tr[x]=(tr[x]+y)%p;}
	void clear(){while(top){int x=st[top--];for(;x<=tot+1;x+=(x&-x))tr[x]=0;}}
}bit[2];
void Freopen(){
	freopen("marketeers.in","r",stdin);
	freopen("marketeers.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1,len,x;i<=n;i++){
		scanf("%d",&len);
		while(len--)scanf("%d",&x),S[i].push_back(x),lsh[++tot]=x;
	}
	sort(lsh+1,lsh+1+tot);
	tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	for(int i=1;i<=n;i++)for(int &x:S[i])x=lower_bound(lsh+1,lsh+1+tot,x)-lsh;
	s.insert(0x7fffffff);
	for(int i=1;i<=n;i++){
		int mn=0x7fffffff,mx;
		a[i]={-0x7fffffff,i};
		for(int x:S[i])mn=min(mn,x);
		mx=*(s.lower_bound(mn));
		for(int x:S[i])if(x<=mx)a[i].first=max(a[i].first,x);
		s.insert(a[i].first);
	}
	sort(a+1,a+1+n,[](const pair<int,int> &a,const pair<int,int> &b){return a.first>b.first;});
	bit[0].add(tot+1,1);
	for(int i=1;i<=n;i++){
		int q=a[i].second;
		for(int x:S[q])
			bit[i&1].add(x,bit[i-1&1].askmx(x));//printf("%d %d\n",x,bit[i-1&1].askmx(x));
		bit[i-1&1].clear();
	}
	printf("%d\n",bit[n&1].askmx(0));
}
/*
4 2 1 3

4
5 
7 11 3 10 1
3 
8 6 4
1 
15
3 
1 5 99
*/
