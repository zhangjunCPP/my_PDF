#include<stdio.h>

template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=1e5+5;
int n,q,a[N],l,r,last,mex;
// void erase(int x,int cnt[]){
	// if(!(--cnt[a[x]]))
	// {
		// if(a[x]<last){last=a[x];}
		// for(int i=last;i<=mex;i++) if(!cnt[i]) {mex=i;break;}
	// }
	// return ;
// }
// void add(int x,int cnt[]){
	// if(!(cnt[a[x]]++))
	// {
		// for(int i=last;i<=a[x];i++){ if(cnt[i]) last=i;else break;}
		// for(int i=mex;i<=n;i++) if(!cnt[i]) {mex=i;break;}
	// }
	// return ;
// }
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		int k;scanf("%d",&k);
		l=1;r=0;last=0;mex=0;int ans=0,cnt[N]={};
		while(r<k)
		{
			int x=++r;
			if(!(cnt[a[x]]++))
			{
				for(int i=last;i<=a[x];i++){ if(cnt[i]) last=i;else break;}
				for(int i=mex;i<=n;i++) if(!cnt[i]) {mex=i;break;}
			}
		}
		ans=max(ans,mex);
		while(r<n)
		{
			int x=l++;
			if(!(--cnt[a[x]]))
			{
				if(a[x]<last){last=a[x];}
				for(int i=last;i<=mex;i++) if(!cnt[i]) {mex=i;break;}
			}
			x=++r;
			if(!(cnt[a[x]]++))
			{
				for(int i=last;i<=a[x];i++){ if(cnt[i]) last=i;else break;}
				for(int i=mex;i<=n;i++) if(!cnt[i]) {mex=i;break;}
			}
			ans=max(ans,mex);
		}
		printf("%d\n",ans);
	}
    return 0;
}