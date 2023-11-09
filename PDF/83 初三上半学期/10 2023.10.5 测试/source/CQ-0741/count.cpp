#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w;
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0'); 
}
inline void FRE(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
const int N=1e6;
int T,n;
int ans;
int sum[N];
signed main(){
	FRE();
	T=rd();
	while(T--){
		n=rd(); 
		if(sum[n]){
			printf("%lld\n",sum[n]);
			return 0;
		}
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				int ss=sqrt(i*j);
				if(ss*ss>i*j)ss--;
				for(int z=1;z<=ss;++z){
					int s=i*j/z;
					if(s>n)continue;
					if(s*z==i*j){
						if(i==j){
							if(z!=s)ans+=2;	
							else ans++;
						}
						else{
							if(z!=s)ans+=4;
							else ans+=2;
						}
					}
				} 
			}
		}
		sum[n]=ans;
		wr(ans);
		putchar('\n');
	}
	return 0;
} 
