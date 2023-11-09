#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=1e5+5,M=1e6+5;
int n,m;
int a[N],b[N];
bool tag[M];
int ans[N];
int main(){
	freopen("marketplace.in","r",stdin);
	freopen("marketplace.out","w",stdout);
	_(n),_(m);
	for(int i=1;i<=n;i++) _(a[i]),_(b[i]);
	for(int x=1;x<=m;x++){
		memset(tag+1,0,sizeof(bool)*m);
		int w=0;
		while(!w){
			for(int i=1;i<=n;i++){
				bool flag=0;
				if(!tag[a[i]]&&a[i]!=x) tag[a[i]]=1,flag=1;
				else if(!tag[b[i]]&&b[i]!=x) tag[b[i]]=1,flag=1;
				if(!flag){ w=i;	break; }
			}
		}
		ans[w]++;
	}
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}

