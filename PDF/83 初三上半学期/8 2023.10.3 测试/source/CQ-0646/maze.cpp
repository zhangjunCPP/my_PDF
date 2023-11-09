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
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
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
/*
乐了。只会 d=0 的最短路，其他啥都不会。
15pts。寄寄寄。
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






*/
