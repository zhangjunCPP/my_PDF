#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
const int N=2e3+10;
void File(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
}
struct G{
	ll l,r,v,tag=0;
}a[N];
int n;
//第i个用j，且j周围使用情况为s 
int get(int x){
	int cnt=0;
	while(x){
		if(!(x&1)) cnt++;
		x>>=1;
	}
	return cnt;
}
ll add[N],del[N],du[N],vis[N];
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	File();
	cin>>n; 
	for(int i=1;i<=n;i++){
		int A,b,c;
		cin>>A>>b>>c;
		a[i]={A,b,c,0};
		for(int j=A;j<=b;j++){
			if(j==i) continue;
			du[i]++;
			add[i]+=c;
			del[j]-=c;
		}
	}
	int ans=0;
	for(int t=1;t<=n;t++){
		int maxn=-100000,id;
		for(int i=1;i<=n;i++){
			if(add[i]+del[i]>maxn&&vis[i]==0){
				maxn=add[i]+del[i];
				id=i;
			}
		}
		vis[id]=1;
		ans+=add[id];
		for(int i=a[id].l;i<=a[id].r;i++){
			if(i==id) continue;
			del[i]+=a[id].v;
			
		}
		for(int i=1;i<=n;i++){
			if(i==id) continue;
			if(a[i].l<=id&&a[i].r>=id){
				add[i]-=a[i].v;
			}
		}
	}
	cout<<ans;
}
