#include<stdio.h>
#include<map>
#include<set>
#include<utility>

template <typename dy> dy max(dy x,dy y){return x>y?x:y;}
template <typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=2e3+5;
void write(int x){
	if(x<0) {putchar('-');x=-x;}
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
int ksm(int x,int y){
	int s=1;
	while(y)
	{
		if(y&1) s*=x;
		x*=x;y>>=1;
	}
	return s;
}
int p,k,n;
std::map<std::set<int>,int> ma;
int s[N],ci,ans;
bool f[N];
std::set<std::set<int> > ss;

void dfs(int u){
	if(u==p){
		std::set<int> se;
		for(int i=0;i<ci;i++) se.insert(s[i]);
		ss.insert(se);
		return ;
	}
	for(int i=0;i<n;i++){
		if(!f[i]){
			s[ci++]=i;f[i]=1;
			dfs(u+1);
			ci--;
			f[i]=0;
		}
//			for(int j=0;j<ci;j++) ma[{i,s[j]}]=ma[{s[j],i}]=1;
//			for(int j=0;j<ci;j++) ma[{i,s[j]}]=ma[{s[j],i}]=0;
	}
}
auto u=ss.begin();
int sans;
std::set<std::set<int> > pp;
void dfs1(int s){
	if(u==ss.end()){
		if(s=ans)
		for(auto i=pp.begin();i!=pp.end();i++)
			{
				std::set<int> ts=*i;
				for(auto j=ts.begin();j!=ts.end();j++) printf("%d ",*j);
				printf("%d\n");
			}
		return ;
	}
	std::set<int> se=*u;bool f=1;
	for(auto i=se.begin();i!=se.end();i++){
		auto j=i;j++;
		for(;j!=se.end();j++){
			std::set<int> ts;
			ts.insert(*i);
			ts.insert(*j);
			if(ma[ts]){
				f=0;
				break;
			}
		}
	}
	if(f){
		for(auto i=se.begin();i!=se.end();i++){
			auto j=i;j++;
			for(;j!=se.end();j++){
				std::set<int> ts;
				ts.insert(*i);
				ts.insert(*j);
				ma[ts]++;
			}
		}
		pp.insert(se);
		u++;dfs1(s+1);u--;
		pp.erase(se);
		for(auto i=se.begin();i!=se.end();i++){
			auto j=i;j++;
			for(;j!=se.end();j++){
				std::set<int> ts;
				ts.insert(*i);
				ts.insert(*j);
				ma[ts]--;
			}
		}
	}
	u++;dfs1(s);u--;
	return;
}
void sol(){
	n=ksm(p,k);
	if(p==2){
		printf("%d\n",n*(n-1)/2);
//		return ;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				write(i);putchar(' ');
				write(j);putchar('\n');
			}
		}
	}
	else if(k==1){
		printf("1\n");
		for(int i=0;i<p;i++) printf("%d ",i);
	}
	else
	{
		int sum=0;
		for(int i=0;i<k;i++) sum=sum*p+1;
		ans=sum*ksm(p,k-1);
		printf("%d\n",ans);
//		dfs(0);
//		dfs1(0);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&p,&k);sol();
	
	
	return 0;
}

