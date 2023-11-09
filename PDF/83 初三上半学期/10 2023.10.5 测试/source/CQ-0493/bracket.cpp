#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
char a[N];
int st[N];
int ck(int n){
	int top=0;
	for(int i=1;i<=n;i++)if(a[i]=='(')st[++top]=i;
	else{
		if(!top)return 0;
		top--;
	}
	return 1;
}
set<pair<int,int> >b[N];
int sz[N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%s",a+1);
	int n=strlen(a+1);
	if(!ck(n)){
		printf("-1\n");return 0;
	}
	int ans=0,top=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='(')st[++top]=i;
		else{
			int x=st[top--],dep=top;
			sz[x]=1;
			if(b[dep+1].size()){
				auto it=--b[dep+1].end();
				int id=(*it).second;
				sz[x]+=sz[id];
				for(auto x:b[dep+1])ans+=x.first;
				ans-=sz[id];
				b[dep+1].clear();
			}
			b[dep].insert({sz[x],x});
		}
	}
	if(b[0].size()){
		auto it=--b[0].end();
		int id=(*it).second;
		for(auto x:b[0])ans+=x.first;
		ans-=sz[id];
	}
	printf("%d",ans*2);
	return 0;
}
