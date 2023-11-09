#include<bits/stdc++.h>
#define PUT putchar('\n')
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
struct node{
	int fi,se;
	bool operator < (const node A){
		return fi<A.fi;
	}
};
const int N=1e5+5;
int n,k,L;
int cnt1,cnt2;
node rig[N],lef[N];
double ans[N];
inline void FRE(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
}
int main(){
	FRE();
	n=rd();k=rd(),L=rd();
	for(int i=1;i<=n;++i){
		int dis=rd(),col=rd();char ch;cin>>ch;
		if(ch=='D'){
			rig[++cnt1]={dis,col};
			ans[col]+=double(L-dis);
		}
		else{
			lef[++cnt2]={dis,col};
		}	
	}
	sort(rig+1,rig+cnt1+1);
	sort(lef+1,lef+cnt2+1);
	for(int i=1;i<=cnt2;++i){
		int col=lef[i].se;
		double sum=0,r=lef[i].fi;
		for(int j=cnt1;j;--j){
			if(rig[j].fi<=r){
				int p=rig[j].se;
				double l=rig[j].fi;
				ans[col]+=double(r-l-2*sum)/2.0;
				sum+=double(r-l-2*sum)/2.0;
				col=(col+p)%k;				
			}
		}
		ans[col]+=double(r-sum);
	}
	for(int i=0;i<k;++i)printf("%.1lf",ans[i]),PUT;
	return 0;
}
