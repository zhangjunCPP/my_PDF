//只有在两个相邻的a... ... a中间有>=k个元素才会insert.直接算就好了.良心场!!!!  
#include<bits/stdc++.h>
using namespace std;
int n,m,s[500010],las[500010];
long long ans[500010];
auto add=[](int p,int v){for(p=m-p+1;p<=m;p+=p&-p)s[p]+=v;};
auto ask=[](int p){int res=0;for(p=m-p+1;p;p-=p&-p)res+=s[p];return res;};
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		if(las[x])ans[ask(las[x])-1]++,add(las[x],-1);
		else ans[n]++;
		las[x]=i,add(i,1);
	}for(int i=n;i;i--)ans[i]+=ans[i+1];
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}
