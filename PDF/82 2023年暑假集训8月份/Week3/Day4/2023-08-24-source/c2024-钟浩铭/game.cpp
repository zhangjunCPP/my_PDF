#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+10;
template <typename T>
inline void read(T &x){
	bool f=0; x=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
} 
template <typename T,typename ...Args>
inline void read(T &x,Args &...args){read(x); read(args...);}
int n;
int v[MAXN];
bool flag1=true;
inline void solve1(){ //v[i]=i
	int ans=0;
	for(int i=1;i<=n-1;i++) ans+=v[i];
	printf("%lld\n",ans);
	for(int i=n;i>=1;i--) printf("%lld ",i);
	printf("\n");
	exit(0);
}
bool flag2=true;
inline void solve2(){ //v[i]=n+1-i
	int ans=v[1]*(n-1);
	printf("%lld\n",ans);
	for(int i=2;i<=n;i++) printf("%lld ",i);
	putchar('1');
	exit(0);
}
int num[MAXN];
inline int work(){
	int sum=0;
	stack<int> st;
	st.push(num[1]);
	for(int i=2;i<=n;i++){
		if(num[i]>st.top() || st.empty())
			st.push(num[i]);
		else{
			while(num[i]<st.top()){
				sum+=v[num[i]];
				st.pop();
				if(st.empty()) break;
			}
			st.push(num[i]);
		}
	} 
	return sum;
}
int ans=0; bool vis[MAXN]; int id[MAXN];
void dfs(int k){
	if(k==n+1){
		if(work()>ans){
			ans=work();
			for(int i=1;i<=n;i++) 
				id[i]=num[i];
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1; num[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
} 
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(v[i]); 
		if(v[i]!=i) flag1=false;
		if(v[i]!=n+1-i) flag2=false;
	}
	if(flag1) solve1();
	if(flag2) solve2();
	dfs(1); printf("%lld\n",ans);
	for(int i=1;i<=n;i++) printf("%lld ",id[i]);
	return 0;
}

