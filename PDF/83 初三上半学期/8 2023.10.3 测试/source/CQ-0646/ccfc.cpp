#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 100010
char s[N];
int n;
namespace f1{
	struct H{
		ll f[N],g[N],p;
		void init(ll _p){
			p=_p;
			g[0]=1;
			For(i,1,n){
				g[i]=g[i-1]*29%p;
				f[i]=(f[i-1]*29+s[i]-'a')%p;
			};
		};
		ll ask(ll l,ll r){
			return (f[r]-f[l-1]*g[r-l+1]%p+p)%p;
		};
	}h[3];
	void f1(){
		h[0].init(998244353);
		h[1].init(1000000007);
		h[2].init(1004535809);
		For(i,1,n){
			ll ans=0;
			for(ll j=i;;++j){
				ll len=j-i+1;
				ll l1=j+1,r1=j+len,l2=n-len+1,r2=n;
				if(r1+1>=l2)break;
				ll fg=1;
				For(k,0,2){
					if(h[k].ask(i,j)!=h[k].ask(l1,r1)||h[k].ask(i,j)!=h[k].ask(l2,r2)){
						fg=0;
						break;
					}
				};
				ans+=fg;
			}
			cout<<ans<<' ';
		};
	}
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	f1::f1();
	return 0;
}
/*
先枚举后缀，再枚举 A 串，用哈希判三个串是否相等。
大概率能过 10^4 吧。70pts。
保底，写了个三模数哈希。
10^4 竟然只跑了 277ms（用户时间，按照笔试是这个标准）。

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
sb。
*/
