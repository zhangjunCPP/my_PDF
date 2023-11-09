#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,mod=998244353,M=2e4+10;
struct node{
	int l,r,op;
}q[N];
int a[N],st[N],pi[N],cnt,vis[N];
int pw[M][20],id[N];
vector<pair<int,int> >p[N];
int c[M][20],C[M];
int in[N],inv[M][20];
void init(int n,int m){
	int s=sqrt(n),num=n/s+(n%s!=0);
	int L=0,R=0;
	for(int i=1;i<=num;i++){
		L=R+1,R=min(n,L+s-1);
		for(int j=L;j<=R;j++)st[j]=i;
	}
	for(int i=2;i<=m;i++){
		if(!vis[i])pi[++cnt]=i,id[i]=cnt;
		for(int j=1;j<=cnt&&(ll)i*pi[j]<=m;j++){
			int num=i*pi[j];
			vis[num]=i;
			if(i%pi[j]==0)break;
		}
	}
	in[1]=1;
	for(int i=2;i<=m;i++)in[i]=in[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=cnt;i++){
		ll x=pi[i];pw[i][0]=1,inv[i][0]=1,inv[i][1]=in[pi[i]];
		for(int j=1;x<=m;j++,x*=pi[i]){
			pw[i][j]=x;if(j!=1)inv[i][j]=inv[i][j-1]*inv[i][1]%mod;
		}
	}
	//1 
	for(int i=2;i<=m;i++){
		int x=i;
		for(int j=1;(ll)pi[j]*pi[j]<=x;j++){
			if(x%pi[j]==0){
				int cc=0;
				while(x%pi[j]==0)cc++,x/=pi[j];
				p[i].push_back({j,cc});
			}
		}
		if(x!=1)p[i].push_back({id[x],1});
	}
}
int cmp(node x,node y){
	if(st[x.l]==st[y.l])return st[x.l]<st[y.l];
	if(st[x.l]&1)return x.r<y.r;
	return x.r>y.r;
}
ll ans[N];
ll sum;int L=1,R;
void add(int &x,int y){
	if(x+y>=mod)x+=y-mod;
	else x+=y;
}
void del(int &x,int y){
	if(x-y<0)x=x+mod-y;else x-=y;
}
int main(){
	//freopen("ddickky.in","r",stdin);
	//freopen("ddickky.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	init(n,200000);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].op=i;
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++){
		int l=q[i].l,r=q[i].r,id=q[i].id;
		if(L>r){
			while(L>l){
				L--;
				int x=a[L];if(x==1)continue;ans=ans*x%mod;
				for(auto X:p[x]){
					int num=X.first,cc=X.second,sc=C[num];
					for(int j=cc;j;j--){
						del(sc,c[num][j]);
						ans=ans*pw[num][j]%mod*c[num][j]%mod;
						add(c[num][j],c[num][j]);
					}
					add(c[num][cc],sc+1);
					add(C[num],C[num]+1);
					ans=ans*pw[num][cc]%mod*(sc+1)%mod;
				}
			}
			while(R>r){
				int x=a[R];if(x==1)continue;
				for(auto X:p[x]){
					int num=X.first,cc=X.second,sc=0;
					C[num]=(C[num]-1)*in[2]%mod;
					for(int j=cc-1;j;j--){
						c[num][j]=c[num][j]*in[2]%mod;
						add(sc,c[num][j]);
						ans=ans*inv[num][j]%mod*c[num][j]%mod;
						add(c[num][j],c[num][j]);
					}
					add(c[num][cc],sc+1);
					add(C[num],C[num]+1);
					ans=ans*pw[num][cc]%mod*(sc+1)%mod;
				}
				R--;
			}
		}else{
			while(R>r){
				int x=a[R];if(x==1)continue;
				
				R--;
			}
			while(R<r){
				R++;
				int x=a[R];if(x==1)continue;
				
				
			}
			while(L>l){
				L--;
				int x=a[L];if(x==1)continue;
				
			}
			while(L<l){
				int x=a[L];if(x==1)continue;
				
				L++;
			}
		}
		ans[id]=sum;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}
