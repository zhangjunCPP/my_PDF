#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<queue>

#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define ll long long
#define F first
#define S second
#define eps 1e-6
#define For(i,s,t) for(int i=s;i<=t;i++)
#define rFor(i,s,t) for(int i=s;i>=t;i--)
#define ls k*2
#define rs k*2+1

using namespace std;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
}

const int N=1e5+10,M=1e6+10,inf=1e9+10;
int n,q;
int cnt[N],a[N];

signed main(){
	Freopen();
	Genshin_Impact_starts;
	cin.tie(0),cout.tie(0);
	cin>>n;
	For(i,1,n)cin>>a[i];
	cin>>q;
	while(q--){
		for(int i=0;i<=n;i++)cnt[i]=0;
		int k,ans,id;cin>>k;
		int l=1,r=k;
		For(i,l,r)cnt[a[i]]++;
		For(i,0,n)if(cnt[i]==0){
				ans=max(ans,i);
				id=i;
				break;
			}
		l++,r++;
		for(;r<=n;l++,r++){
			cnt[a[l-1]]--,cnt[a[r]]++;
			if(cnt[a[l-1]]==0&&a[l-1]<=id)ans=max(ans,a[l-1]),id=a[l-1];
			if(a[r]==id)For(i,id+1,n)if(cnt[i]==0){
						ans=max(ans,i);
						id=i;
						break;
					}
		}
		cout<<ans<<endl;
	}
}
