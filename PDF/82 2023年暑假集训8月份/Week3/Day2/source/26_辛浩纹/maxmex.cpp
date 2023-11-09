#include<cstdio>
#include<bitset>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	x<0?putchar('-'),x=-x:false;
	char stk[50];int top=0;
	do stk[++top]=x%10+48,x/=10;while(x);
	for(;top;top--)putchar(stk[top]);
}
template<typename T,typename ...Args>void read(T &a,Args &...args){read(a);read(args...);}
template<typename T,typename ...Args>void write(T a,Args ...args){write(a);write(args...);}
template<typename T>T min(T a,T b){return a>b?b:a;}
template<typename T,typename ...Args>T min(T a,T b,Args ...args){return min(a,min(b,args...));}
template<typename T>T max(T a,T b){return a>b?a:b;}
template<typename T,typename ...Args>T max(T a,T b,Args ...args){return max(a,max(b,args...));}
template<typename T>void swap(T &a,T &b){a^=b^=a^=b;}
template<typename T>int abs(T a){return a<0?-a:a;}
const int maxn=1e5+4;
int n,a[maxn],ans[maxn],q;
std::bitset<maxn>s;
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	read(n);bool flag=1;
	for(int i=1;i<=n;++i){
		read(a[i]);
		if(a[i]>10)flag=0;
	}
	if(n<=100){
		for(int i=1;i<=n;++i){
			int dick=0;
			for(int j=0;j<=n+1;++j)s[j]=0;
			for(int j=i;j<=n;++j){
				s[a[j]]=1;
				for(int k=dick;k<=n+1;++k)if(s[k]==0){dick=k;break;}
				ans[j-i+1]=max(ans[j-i+1],dick);
			}
		}
		read(q);
		while(q--){
			int x;read(x);
			write(ans[x],'\n');
		}
	}
	else{
		read(q);
		if(flag){
			while(q--){
				int k;read(k);
				int cnt[maxn]={0},ans=0,dick=0;
				for(int i=1;i<=k;++i)cnt[a[i]]++;
				for(int i=0;i<=11;++i)if(cnt[i]==0){dick=i;break;}
				ans=max(ans,dick);
				for(int i=2;i<=n;++i){
					int j=i+k-1;
					if(j>n)break;
					cnt[a[i-1]]--;
					if(cnt[a[i-1]]==0&&a[i-1]<dick)dick=a[i-1];
					cnt[a[j]]++;
					for(int j=dick;j<=11;++j)if(cnt[j]==0){dick=j;break;}
					ans=max(ans,dick);
				}
				write(ans,'\n');
			}
		}
		else if(q<=10){
			while(q--){
				int k;read(k);
				int cnt[maxn]={0},ans=0,dick=0;
				for(int i=1;i<=k;++i)cnt[a[i]]++;
				for(int i=0;i<=n+1;++i)if(cnt[i]==0){dick=i;break;}
				ans=max(ans,dick);
				for(int i=2;i<=n;++i){
					int j=i+k-1;
					if(j>n)break;
					cnt[a[i-1]]--;
					if(cnt[a[i-1]]==0&&a[i-1]<dick)dick=a[i-1];
					cnt[a[j]]++;
					for(int j=dick;j<=n+1;++j)if(cnt[j]==0){dick=j;break;}
					ans=max(ans,dick);
				}
				write(ans,'\n');
			}
		}
		else{
			for(int i=1;i<=n;++i){
				int dick=0;
				for(int j=0;j<=n+1;++j)s[j]=0;
				for(int j=i;j<=n;++j){
					s[a[j]]=1;
					for(int k=dick;k<=n+1;++k)if(s[k]==0){dick=k;break;}
					ans[j-i+1]=max(ans[j-i+1],dick);
				}
			}
			while(q--){
				int x;read(x);
				write(ans[x],'\n');
			}
		}
	}
	return 0;
}