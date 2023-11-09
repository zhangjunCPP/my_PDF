//the code is from chenjh
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
const int mod=998244353;
using ci=const int;
int n,k;
int a[255];
struct myhash{
	size_t operator ()(const PII&x)const{return size_t((unsigned long long)x.first*x.second);}
};
void dfs(ci pos,const LL&w,const unordered_set<PII,myhash>&s){
	if((int)s.size()>k) return;
//	printf("%d %lld %d\n",pos,w,K);
	if(pos>n){
		int K=s.size();
//		printf("%lld %d\n",w,K);
		if(++a[K]>=mod) a[K]-=mod;
		return;
	}
	unordered_set<PII,myhash> ns=s;
	int t=0;
	for(const PII&p:s)if(s.find(make_pair(p.first<<1,p.second+1))==s.end()) ns.insert(make_pair(p.first<<1,p.second+1)),++t;
	ns.insert(make_pair(w<<1,pos));
	dfs(pos+1,w<<1,ns);
	ns=s;
	t=0;
	for(const PII&p:s)if(s.find(make_pair(p.first<<1|1,p.second+1))==s.end()) ns.insert(make_pair(p.first<<1|1,p.second+1)),++t;
	ns.insert(make_pair(w<<1|1,pos+1));
	dfs(pos+1,w<<1|1,ns);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	unordered_set<PII,myhash> s;s.clear();
	scanf("%d%d",&n,&k);
	dfs(1,0,s);
	for(int i=1;i<=k;i++) printf("%d ",a[i]);
	return 0;
}
