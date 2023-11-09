#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int l[1005],r[1005],c[1005];

int q[1005],value[1005][1005];
ll suf[1005],ans=0;
ll calc0(int q[],int f){
	static int vis[1005];
	ll ans=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)if(q[i]){
		int x=q[i],sum=0;
		vis[x]=1;
		for(int j=l[x];j<=min(r[x],f-1);j++)sum+=!vis[j];
		ans+=1ll*sum*c[x];
	}
	return ans;
}
void dfs(int x){
	if(calc0(q,x)+suf[x]<=ans)return;
	if(x==n+1)return ans=max(ans,calc0(q,x)),void();
	for(int i=1;i<=n;i++)if(!q[i]){
		q[i]=x;
		dfs(x+1);
		q[i]=0;
	}
}
void bf(){
	for(int i=1;i<=n;i++){
		for(int j=l[i];j<i;j++)value[j][i]=max(value[j][i],c[i]);
		for(int j=i+1;j<=r[i];j++)value[i][j]=max(value[i][j],c[i]);
	}
	for(int i=n;i;i--){
		for(int j=1;j<=i;j++)suf[i]+=value[j][i];
		suf[i]+=suf[i+1];
	}
	q[1]=1;
	dfs(2);
	printf("%lld\n",ans);
}

int num;
map<string,int> ID[1005];
vector<ll> dp[1005];
	
ll calc1(string q){
	static int vis[100];
	ll ans=0;
	for(int i=1;i<=7;i++)vis[i]=0;
	for(int i=0;i<7;i++){
		int x=(int)q[i],sum=0;
		vis[x]=1;
		for(int j=l[x];j<=min(7,r[x]);j++)sum+=(!vis[j]);
		ans+=1ll*sum*c[x];
	}
	return ans;
}
ll calc2(string a,int x){
	int pos=0;ll res=0;
	for(int i=0;i<(int)a.size();i++)if(a[i]==7){pos=i;break;}
	for(int i=pos+1;i<(int)a.size();i++)if(l[x]<=x-7+a[i])res+=c[x];
	for(int i=0;i<pos;i++)if(x<=r[x-7+a[i]])res+=c[x-7+a[i]];
	return res;
}
string del(string a,int x){//把a中的x去掉，并全部加一 
	string res="";int pos=0;
	for(int i=0;i<(int)a.size();i++)if(a[i]==x){pos=i;break;}
	for(int i=0;i<pos;i++)res+=a[i]+1;
	for(int i=pos+1;i<(int)a.size();i++)res+=a[i]+1;
	return res;
}	
void init(){
	string a="";num=0;
	for(int i=1;i<=7;i++)a+=i;
	do{
		ID[7][a]=num++;
		dp[7].push_back(calc1(a));
	}while(next_permutation(a.begin(),a.end()));
}
void zj(){
	init();
	for(int i=8;i<=n;i++){
		string a;num=0;
		for(int j=1;j<=7;j++)a+=j;
		do{
			ll ans=0;
			for(int j=0;j<=7;j++){
				string x=a;
				x.insert(x.begin()+j,0);
				ans=max(ans,dp[i-1][ID[i-1][del(x,7)]]+calc2(x,i));
			}
			ID[i][a]=num++;
			dp[i].push_back(ans);
		}while(next_permutation(a.begin(),a.end()));
	}
	ll ans=0;
	for(ll x:dp[n])ans=max(ans,x);
	printf("%lld",ans);
}
void Freopen(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&l[i],&r[i],&c[i]);
	if(n==1)return puts("0"),0;
	if(n<=10)return bf(),0;
	else return zj(),0;
}
/*
8
1 3 861
2 4 822
1 3 286
2 4 236
5 6 335
4 8 837
3 6 469
7 8 846
9203
12687435

1 2
2 2
6 4
7 3
4 1
3 0
5 0
8357
*/
