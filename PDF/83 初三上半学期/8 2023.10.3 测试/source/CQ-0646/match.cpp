#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 1000010
int n,m;
vector<int>a[N];
namespace f1{
	int f[1010][1<<10|1];
	int cmp(vector<int>a,vector<int>b){
		int x=a.size(),y=b.size();
		for(int i=0,j=0;i<x&&j<y;++i,++j){
			if(a[i]>b[j])return 1;
			if(a[i]<b[j])return -1;
		}
		if(x>y)return 1;
		if(x<y)return -1;
		return 0;
	};
	void f1(){
		f[0][0]=1;
		For(i,1,n){
			For(j,0,(1<<m)-1)if(f[i-1][j]){
				vector<int>v;
				int x=0;
				for(int k=m;k>0;--k){
					v.push_back(k);
					x^=1<<(k-1);
					if(cmp(v,a[i])<0)continue;
					if(!(j&x)){
						f[i][j|x]=1;
					}
					v.pop_back();
					x^=1<<(k-1);
				}
				if(!a[i].size())f[i][j]=1;
			};
		};
		For(i,0,(1<<m)-1)if(f[n][i]){
			for(int j=m;j>0;--j){
				cout<<((i>>(j-1))&1);
			};
			return;
		}
		cout<<-1;
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	For(i,1,n){
		int k;
		cin>>k;
		For(j,1,k){
			int x;
			cin>>x;
			a[i].push_back(x);
		};
		reverse(a[i].begin(),a[i].end());
	};
	if(n<=10&&m<=10)f1::f1();
	else if(n<=1000&&m<=5)f1::f1();
	else cout<<-1;
	return 0;
}
/*
枚举每个数在哪一位被 1 截断，O(m^n)，一分没有 /jk
将当前各个位所用的状态压下来，O(nm^2*2^m)，25pts。
寄寄寄。

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
