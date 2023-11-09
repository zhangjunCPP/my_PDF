#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+11,inf=1e9;
void Freopen(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
}
int n;
int a[N];
int res=0,vis[25];
void add(int x){
	if(vis[x])
		return;
	vis[x]=1;
	while(vis[res])
		res++;
}
void clear(){
	memset(vis,0,sizeof(vis));
	res=0;
}
int ask(){
	return res;	
}
vector<int>anss;
void solve(){
	int last=-1,id=0,ans=0,cnt=0;
	anss.push_back(1);
	for(int i=1;i<=n;i++){
		add(a[i]);
		if(ask()>last){
			last=ask();
			id=i;
		}
		if(i==n){
			cnt++;
			ans+=ask();
			clear();
			last=-1;
			i=id;
			anss.push_back(id+1);
		}
	}
	cout<<ans<<" "<<cnt<<endl;
	for(int i=0;i<cnt;i++)
		cout<<anss[i]<<" ";
}
signed main(){
 	Freopen();
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	return 0;
}

