#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
ll n,a[N],mn,mx,pos;
namespace f1{
	bitset<N>f;
	int chk1(ll dn,ll up){
		f.reset();f[0]=1;
		For(i,1,n){
			if(a[i]>=dn&&a[i]<=up)f[i]=f[i]|f[i-1];
			if(i>1&&a[i]+a[i-1]>=dn&&a[i]+a[i-1]<=up)f[i]=f[i]|f[i-2];
		};
//		if(f[n])cout<<up<<' ';
		return f[n];
	};
	int chk(ll x){
//		cout<<"x "<<x<<' ';
		For(up,1,mx+mx){
			ll dn=max(up-x,1ll);
			if(chk1(dn,up))return 1;
		};
//		cout<<'\n';
		return 0;
	};
	void f1(){
		ll l=0,r=mx*2,res=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(chk(mid)){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		cout<<res<<'\n';
	}
}
namespace f2{
	ll ans;
	void dfs(ll x,ll l,ll r,ll y){
		if(x==n+1){
			if(!y)ans=min(ans,r-l);
			return;
		}
		if(y==1){
			dfs(x+1,min(l,a[x]+a[x-1]),max(r,a[x]+a[x-1]),0);
		}else{
			dfs(x+1,min(l,a[x]),max(r,a[x]),0);
			dfs(x+1,l,r,1);
		}
	};
	void f2(){
		ans=2e9;
		dfs(1,2e9,0,0);
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;mn=2e9;
	For(i,1,n){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	};
	if(n<=18){
		f2::f2();
		return 0;
	}
	//if(mx<=10)
	f1::f1();
	return 0;
}
/*
二分答案，转化成极差小于等于 mid。
然后不会了。
直接 dp 需要知道当前权值最大与最小值，肯定炸。
中间 20 分直接枚举权值最大值的上界然后可行性 dp 就行了。
所以这个最大值有没有单调性？
竟然没有，只是几个区间！！！
20 pts，寄寄寄。
敲了个暴力。40 pts，寄寄寄。




#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 200010
int n,m,k,tag[N],d[N];
vector<pair<int,ll>>e[N];
namespace f1{
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,less<pair<ll,int>>>q;
	ll dis[N];
	void f1(){
		memset(dis,0x3f,sizeof(dis));
		For(i,1,n)if(tag[i]){
			dis[i]=0;
			q.push({0,i});
		};
		while(q.size()){
			auto p=q.top();q.pop();
			int x=p.second;
			for(auto pp:e[x]){
				int y=pp.first;ll w=pp.second;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push({dis[y],y});
				}
			}
		}
		if(dis[1]!=0x3f3f3f3f3f3f3f3f)cout<<dis[1]<<'\n';
		else cout<<-1;
	}
}
int main(){
	#ifndef local
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	For(i,1,k){
		int x;cin>>x;
		tag[x]=1;
	}
	int fg=1;
	For(i,1,n){
		cin>>d[i];
		if(d[i])fg=0;
	};
	For(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	};
	f1::f1();
	return 0;
}

sbsbsbsbsbsbsb。



*/
