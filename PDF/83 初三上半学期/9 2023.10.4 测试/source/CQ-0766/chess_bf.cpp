#include<bits/stdc++.h>
int p,k,n=1;
std::set<std::pair<int,int>> S;
std::vector<int> v[114514];
void dfs(int q,int k){
	{
		S.clear();
		for(int i=1;i<=k;++i){
			for(auto it1=v[i].begin();it1!=v[i].end();++it1)
				for(auto it2=v[i].begin();it2!=it1;++it2)
					if(S.find({std::min(*it1,*it2),std::max(*it1,*it2)})!=S.end()) return;
					else S.emplace(std::min(*it1,*it2),std::max(*it1,*it2));
		}
	}
	if(q==p){
		if(k>=16){
			std::printf("%d\n",k);
			for(int i=1;i<=k;++i){
				for(int it:v[i]) std::printf("%d ",it);
				std::puts("");
			}
		}
		v[k+1].clear(),v[k+1].reserve(p);
		return dfs(0,k+1);
	}
	for(int i=0;i<n;++i){
		bool f=true;
		for(int it:v[k]){
			if(!f) break;
			if(it==i) f=false;
		}
		if(f){
			v[k].emplace_back(i);
			dfs(q+1,k);
			v[k].pop_back();
		}
	}
}
signed main(){
	std::scanf("%d%d",&p,&k);
	for(int i=1;i<=k;++i) n*=p;
	dfs(0,1);
	return 0; 
}
/*
0 1 2
3 4 5
6 7 8
9 10 11
12 13 14
15 16 17
18 19 20
21 22 23
24 25 26
-> 13 tuples
*/
