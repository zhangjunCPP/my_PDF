#include<stdio.h>
#include<algorithm>

template<typename dy> dy max(dy x,dy y){return x>y?x:y;}
template<typename dy> dy min(dy x,dy y){return x<y?x:y;}
const int N=5e5+5;
int n,a[N],cnt[105],now;
int ci;
struct dy{
	int S,T,ans;
}q[N];
void add(int i){if(!cnt[a[i]]) now++;cnt[a[i]]++;}
void erase(int i){cnt[a[i]]--;if(!cnt[a[i]]) now--;}
int sum[N<<2];
void build(int rt,int l,int r){
	if(l==r) {sum[rt]=a[l];return;}
	int mid=l+r>>1;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	sum[rt]=max(sum[rt*2],sum[rt*2+1]);
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R) return sum[rt];
	int mid=l+r>>1,t=0,tt=0;
	if(L<=mid) t=query(rt*2,l,mid,L,R);
	if(R>mid) tt=query(rt*2+1,mid+1,r,L,R);
	return max(t,tt);
}
bool cmp(dy x,dy y){return x.S==y.S?x.T>y.T:x.S<y.S;}
bool check(int l,int r){
	int f=1;
	for(int i=0;i<=r-l-1;i++) if(!cnt[i]) {f=0;break;}
	return f;
}
int main(){
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	bool fl=1;
	for(int i=1;i<=n;i++) {scanf("%d",&a[i]);if(a[i]>1) fl=0;}
	if(0)
	{
		int ans=0;bool vis[N]={};a[0]=a[n+1]=-1;
		for(int i=1;i<=n;i++) 
		{
			if(!vis[i]&&a[i]==1)
			{
				if(!a[i-1]) {ans+=2;vis[i-1]=1;}
				else if(!a[i+1]) {ans+=2;vis[i]=1;}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) {s++;i++;continue; }
			if(!a[i]) ans++;
		}
		printf("%d %d\n",ans,n-s);
		for(int i=1;i<=n;i++) if(!vis[i-1]) printf("%d ",i);
	}
	else
	{
		int r=1,l=1;
		while(r<n+1)
		{
			add(r++);int t=0;
			if(now==r-l) t=check(l,r);
			if(now==r-l&&t)
			{
				if(q[ci].S!=l) ci++;
				q[ci].S=l,q[ci].T=r;
				q[ci].ans=max(q[ci].ans,r-l);
				// printf(":%d %d\n",l,r);
			}
			// printf(":%d %d\n",l,r);
			// if(r>=8) printf("%d %d ",t.first,now<r-l);
			while(l<r-1&&now<r-l) erase(l++);
			// printf("::%d %d\n",l,r);
		}
		while(l<r-1)
		{
			erase(l++);int t=0;
			if(now==r-l) t=check(l,r);
			if(now==r-l&&t)
			{
				q[++ci].S=l,q[ci].T=r;
				q[ci].ans=max(q[ci].ans,r-l);
				break;
			}
		}
		std::sort(q+1,q+ci+1,cmp);
		// for(int i=1;i<=ci;i++) printf(":%d %d\n",q[i].S,q[i].T);
		int s=0,t=n;
		for(int i=1;i<=ci;i++) s+=q[i].ans,t-=q[i].T-q[i].S;
		printf("%d %d\n",s,t+ci);
		for(int i=1;i<=ci;i++)
		{
			if(q[i].S>q[i-1].T) for(int j=q[i-1].T;j<q[i].S;j++) if(j>0)printf("%d ",j); 
			printf("%d ",q[i].S);
			if(i==ci&&q[i].T-1<n) for(int j=q[i].T;j<=n;j++) printf("%d ",j);
		}
	}

    return 0;
}