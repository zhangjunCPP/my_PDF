#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define N 200010
#define ll long long
int n,m,q;
char s[N],t[N];
namespace f1{
	struct H{
		unsigned ll f[N],g[N];
		void init(int n,char*s){
			g[0]=1;
			For(i,1,n){
				g[i]=g[i-1]*31;
				f[i]=f[i-1]*31+s[i]-'a';
			};
		};
		unsigned ll val(int l,int r){
			return f[r]-f[l-1]*g[r-l+1];
		};
	}hs,ht;
	void f1(){
		hs.init(n,s);
		while(q--){
			cin>>(t+1);
			int len=strlen(t+1),ans=0;
			ht.init(len,t);
			if(len>n){
				cout<<"0\n";
				continue;
			}
			For(i,1,n-len+1){
				int l=1,r=len,lcp=0;
				while(l<=r){
					int mid=(l+r)>>1;
					if(hs.val(i,i+mid-1)==ht.val(1,mid)){
						lcp=mid;
						l=mid+1;
					}else r=mid-1;
				}
				int lcs=0;
				l=1,r=len;
				while(l<=r){
					int mid=(l+r)>>1;
					if(hs.val(i+len-mid,i+len-1)==ht.val(len-mid+1,len)){
						lcs=mid;
						l=mid+1;
					}else r=mid-1;
				}
				if(lcs==len||lcp==len){
					++ans;
					continue;
				}
				ans+=(lcs+lcp>len-m-1);
//				cout<<i<<' '<<lcp<<' '<<lcs<<'\n';
			};
			cout<<ans<<'\n';
		}
	}
}
namespace f2{
	bitset<N>bt[26],pre[2000],suf[2000],tem,now;
	int B;
	using f1::H;
	H hs,ht;
	void f2(){
		For(i,1,n){
			bt[s[i]-'a'][i]=1;
		};
		pre[0].set();
		suf[0].set();
		B=sqrt(n)/0.9;
		hs.init(n,s);
		while(q--){
			cin>>(t+1);
			int len=strlen(t+1);
			if(len>=B){
				int ans=0;
				ht.init(len,t);
				if(len>n){
					cout<<"0\n";
					continue;
				}
				For(i,1,n-len+1){
					int l=1,r=len,lcp=0;
					while(l<=r){
						int mid=(l+r)>>1;
						if(hs.val(i,i+mid-1)==ht.val(1,mid)){
							lcp=mid;
							l=mid+1;
						}else r=mid-1;
					}
					int lcs=0;
					l=1,r=len;
					while(l<=r){
						int mid=(l+r)>>1;
						if(hs.val(i+len-mid,i+len-1)==ht.val(len-mid+1,len)){
							lcs=mid;
							l=mid+1;
						}else r=mid-1;
					}
					if(lcs==len||lcp==len){
						++ans;
						continue;
					}
					ans+=(lcs+lcp>len-m-1);
	//				cout<<i<<' '<<lcp<<' '<<lcs<<'\n';
				};
				cout<<ans<<'\n';
				continue;
			}
			if(len<=m){
				cout<<n-len+1<<'\n';
				continue;
			}
			now.reset();
			For(i,1,n-len+1)now[i]=1;
			For(i,1,len+1){
				pre[i].set();
				suf[i].set();
			}
			For(i,1,len){
				pre[i]=(bt[t[i]-'a']>>(i-1))&pre[i-1];
//				For(j,1,n)cout<<(int)pre[i][j];
//				cout<<'\n';
			};
			for(int i=len;i;--i){
				suf[i]=(bt[t[i]-'a']>>(i-1))&suf[i+1];
//				For(j,1,n)cout<<(int)suf[i][j];
//				cout<<'\n';
			};
			tem.reset();
			int l=0,r=m+1;
			while(r<=len+1){
//				cout<<l<<' '<<r<<endl;
				tem=(tem|(suf[r]&pre[l]));
				++l;++r;
			}
			cout<<(tem&now).count()<<'\n';
		}
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>m>>(s+1)>>q;
	n=strlen(s+1);
	if(n<=2000&&q<=2000)f1::f1();
	else f2::f2();
	return 0;
}
