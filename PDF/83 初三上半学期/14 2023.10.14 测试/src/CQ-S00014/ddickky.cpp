#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
struct node{
	int l,r,id,len;
}a[222222];
int o=0;
int c[222222],s[222222],fa[222222];
int v[222222],p[222222],anss[222222];
int jc[222222];
int ans=1,cnt=1;
int cmp(node x,node y){
	if(x.len==y.len){
		return x.l<y.l;
	}
	return x.r<y.r;
}

int gg(int a,int b){
	if(b==0) return 1;
	int ttt=gg(a,b/2);
	if(b%2) return ttt*ttt%mod*a%mod;
	return ttt*ttt%mod;
}
int add(int x){
	
	for(int i=1;i<=o&&p[i]<=sqrt(x);i++){
		if(x%p[i]==0){
			int y=1;
			while(x%p[i]==0){
				y*=p[i];
				ans*=gg(gg(fa[y],jc[s[y]]),mod-2);
				ans%=mod;
				s[y]++;
				if(s[y]==1){
					cnt=cnt*y%mod;
				}
				ans*=gg(fa[y],jc[s[y]]);
				ans%=mod;
				x/=p[i];
			}
		}
	}
	if(x>1){
		ans*=gg(gg(fa[x],jc[s[x]]),mod-2);
		ans%=mod;
		s[x]++;
		if(s[x]==1){
			cnt=cnt*x%mod;
		}
		ans*=gg(fa[x],jc[s[x]]);
		ans%=mod;
	}
	return 0;
}
int sc(int x){
	for(int i=1;i<=o&&p[i]<=sqrt(x);i++){
		if(x%p[i]==0){
			int y=1;
			while(x%p[i]==0){
				y*=p[i];
				ans*=gg(gg(fa[y],jc[s[y]]),mod-2);
				ans%=mod;
				s[y]--;
				if(s[y]==0){
					cnt=cnt*gg(y,mod-2)%mod;
				}
				ans*=gg(fa[y],jc[s[y]]);
				ans%=mod;
				x/=p[i];
			}
		}
	}
	if(x>1){
		ans*=gg(gg(fa[x],jc[s[x]]),mod-2);
		ans%=mod;
		s[x]--;
		if(s[x]==0){
			cnt=cnt*gg(x,mod-2)%mod;
		}
		ans*=gg(fa[x],jc[s[x]]);
		ans%=mod;
	}
	return 0;
}
signed main(){
  freopen("ddickky.in","r",stdin);
  freopen("ddickky.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ma=max(ma,c[i]);
	}
	jc[0]=1;
	for(int i=1;i<=200000;i++){
		jc[i]=jc[i-1]*2;
		if(jc[i]>=mod) jc[i]-=mod;
	}
	for(int i=2;i<=ma;i++){
		if(!v[i]){
			p[++o]=i;	
			v[i]=1;
		}
		for(int j=1;j<=o&&p[j]*i<=ma;j++){
			v[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a[i].l>>a[i].r;
		a[i].len=(a[i].r-a[i].l+1)/(sqrt(n)+1);
		a[i].id=i;
	}
	sort(a+1,a+q+1,cmp);
	int l=1,r=0;
	for(int i=1;i<=o;i++){
		for(int j=p[i];j<=ma;j*=p[i]){
			s[j]=0;
			fa[j]=p[i];
		}
	}
	for(int i=1;i<=q;i++){
		int ll=a[i].l,rr=a[i].r;
		while(r<rr){
			r++;
			add(c[r]);	
		}
		while(l>ll){
			l--;
			add(c[l]);
		}
		while(l<ll){
			sc(c[l]);
			l++;
		}
		while(r>rr){
			sc(c[r]);
			r--;
		}
		anss[a[i].id]=ans*gg(cnt,mod-2)%mod;
	}
	for(int i=1;i<=q;i++){
		cout<<anss[i]<<endl;
	}
	
	return 0;
}
/*
3 1
2 4 3
1 3
*/

