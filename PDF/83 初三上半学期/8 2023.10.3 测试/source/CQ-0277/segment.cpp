//the only problem is that where the mininum and maxinum is?
//把所有数对和和数sort一下?
//sort了后的情形:
//数对和... mx+a ... mx ... mi
//首先最大值肯定是最大的单个数或数对和,最小值肯定是单个数或最小的数对和 
//假如我先枚举最大值,那么就会ban掉一些搭配.此时对最小值来说,只要把最小的几个随便怎么配对即可.
//换个方向枚举max就会每次加入一些搭配.出现什么会无解?:emp-small-small------small-small-emp,且链长&1==1 
//所以若我一点一点把small-small的边连上我就能知道左右搭配都被ban时min<x?
//...,min不一定<=最小的数对和
//所以还要ban掉一些小的数对... ban了后若两边有无解就说明真的无解...
#include<bits/stdc++.h>
using namespace std;
int n,a[200010],cut[200010];
vector<int>pos[400010],val;
map<int,int>odt,pr;
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),val.push_back(a[i]);
	for(int i=1;i<n;i++)val.push_back(a[i]+a[i+1]);
	sort(begin(val),end(val));
	auto rk=[](int x){return lower_bound(begin(val),end(val),x)-begin(val);};
	for(int i=1;i<=n;i++)pos[rk(a[i])].push_back(i);
	for(int i=1;i<n;i++)pos[rk(a[i]+a[i+1])].push_back(i);
	for(int i=1;i<n;i++)pr[-(a[i]+a[i+1])]=1e9;
	int mx=0,now=2e9,ans=1e9;
	for(int i=1;i<=n;i++)mx=max(mx,a[i]);
	cut[0]=cut[n]=1;auto upd=[&](int l,int r,int v){
		if(r-l+1&1)if(cut[l-1]&&cut[r])now=min(now,v);
		else{
			int&x=pr[!cut[l-1]&&!cut[r]?-min(a[l-1]+a[l],a[r]+a[r+1]):-(cut[l-1]?a[r]+a[r+1]:a[l-1]+a[l])];//如果左右都ban了,那么最小值就<=a[p]
			x=min(x,v);
		}
	};
	for(int i=0;i<val.size();i++){
		for(int p:pos[i])if(a[p]==val[i]){
			auto it=odt.emplace(p,p).first;
			if(it!=begin(odt)){
				auto pit=prev(it);
				if(pit->second==p-1)pit->second=p,odt.erase(it),it=pit;
			}auto nit=next(it);
			if(nit!=end(odt)&&nit->first==p+1)it->second=nit->second,odt.erase(nit);
			upd(it->first,it->second,val[i]);
		}else{
			auto it=prev(odt.upper_bound(p));
			odt.emplace(p+1,it->second),it->second=p;
			cut[p]=1;
			upd(it->first,it->second,val[i]),it++,upd(it->first,it->second,val[i]);
		}
	}
	if(!pr.count(-mx))pr[-mx]=1e9;
	for(auto x:pr){
		now=min(now,x.second);
		if(-x.first<=1e9&&-x.first>=mx&&now>0)
		ans=min(ans,-x.first-now);
	}cout<<ans;
	return 0;
}
