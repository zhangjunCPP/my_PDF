#include<bits/stdc++.h>
using namespace std;
namespace my_std{
#define mems(x,y) memset(x,y,sizeof x)
#define Mp make_pair
#define eb emplace_back
#define gc getchar
#define pc putchar
#define fi first
#define se second
	typedef long long ll;
	typedef pair<int,int> pii;
	inline int read(){
		int x=0,f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')
				f=-1;
			c=gc();
		}
		while(isdigit(c)){
			x=x*10+c-48;
			c=gc();
		}
		return x*f;
	}
}
using namespace my_std;
const int N=-1,M=-1,inf=0x3f3f3f3f,mod=0;
int n,m,e[107],d[107],s[107];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		e[i]=i;
	do{
		for(int i=1;i<=n;i++)
			d[e[i]]=i;
		int flag=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(e[i]<d[i]&&!flag)
				flag=1;
			else if(e[i]>d[i]&&!flag)
				flag=-1;
			if(!flag)
				cnt++;
		}
		if(flag==1){
//			for(int i=1;i<=n;i++)
//				printf("%d ",e[i]);
//			printf("%d\n",cnt);
			s[cnt]++;
		}
	}while(next_permutation(e+1,e+n+1));
	for(int i=0;i<=n;i++)
		printf("%d ",s[i]);
}
signed main(){
	int t=1;
	//	scanf("%d",&t);
	while(t--)
		solve();
}


