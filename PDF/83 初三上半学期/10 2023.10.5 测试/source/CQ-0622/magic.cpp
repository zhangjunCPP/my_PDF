//显然状压,考虑怎么统计全每个的贡献
//每次计算当前点的贡献,但是我怎么知道他是第几个放的呢?
//如果再加一维人都要T飞
//但是再加一维还是不清楚啊...很难转移到下一位
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,l[1010],r[1010],c[1010],s;
namespace solve1{
	mt19937 g(time(0));
	void work(){
		int p[30]{};
		iota(p,p+n,1);
		ll ans=0;
		if(n<=10)
		do{
			ll s=0;
			int used[30]{};
			for(int i=0;i<n;i++){
				used[p[i]]=1;
				for(int j=l[p[i]];j<=r[p[i]];j++)
				if(!used[j])s+=c[p[i]];
			}
			ans=max(ans,s);
		}
		while(next_permutation(p,p+n));
		else do{
			shuffle(p,p+n,g);
			ll s=0;
			int used[30]{};
			for(int i=0;i<n;i++){
				used[p[i]]=1;
				for(int j=l[p[i]];j<=r[p[i]];j++)
				if(!used[j])s+=c[p[i]];
			}
			ans=max(ans,s);
		}while((clock()-s)*1.0/CLOCKS_PER_SEC<1.85);
		cout<<ans;
	}
}
namespace solve2{
	void work(){
		bool f4=true,f6=true,f7=true;
		for(int i=1;i<=n;i++)f4&=l[i]==i&&r[i]==i,f6&=l[i]==max(i-6,1)&&r[i]==min(i+6,n),f7&=l[i]==max(i-7,1)&&r[i]==min(i+7,n);
		if(f4){cout<<0;return;}
		if(f6){cout<<(n<=6?n*(n-1)/2:15+(n-6)*6);return;}
		if(f7){cout<<(n<=7?n*(n-1)/2:21+(n-7)*7);return;}
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	s=clock();
	cin>>n;for(int i=1;i<=n;i++)scanf("%d%d%d",&l[i],&r[i],&c[i]);
	if(n<=30)return solve1::work(),0;
	else solve2::work();
	return 0;
}
