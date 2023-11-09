/*
所以t4才是签到题是吧
好吧我是小丑


*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e4+2,p=131,mod=996911659;
int n,i,j,q,lenc,ans,lens,l,r,mid,ss;
ll h[N][32],num[32];
char s[N][32],c[N];

char in[32];
unordered_map<char,int>mp;
int cnt,id,siz;
vector<pair<int,int> >a[100];
vector<int>sum[100];
vector<int>mx[100];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	if(n<=30000){
		for(i=1;i<=n;++i){
			scanf("%s",s[i]);
			for(j=0;s[i][j];++j){
				h[i][j]=s[i][j];
				if(j)h[i][j]=(h[i][j]+h[i][j-1]*p%mod)%mod;
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%s",c);
			lenc=strlen(c);
			for(i=0;c[i];++i){
				num[i]=c[i];
				if(i)num[i]=(num[i]+num[i-1]*p%mod)%mod;
			}
			ans=0;
			for(i=1;i<=n;++i){
				lens=strlen(s[i]);
				l=0,r=min(lens,lenc)-1,ss=-1;
				while(l<=r){
					mid=(l+r)>>1;
					if(h[i][mid]==num[mid])ss=mid,l=mid+1;
					else r=mid-1;
				}
				ans+=ss+2;
				if(ss==min(lens,lenc)-1&&lens==lenc)break;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(i=1;i<=n;++i){
		scanf("%s",in);
		if(!mp.count(in[0]))mp[in[0]]=++cnt;
		id=mp[in[0]];
		lenc=strlen(in);
		a[id].push_back({lenc,i});
		sum[id].push_back(lenc);
		siz=sum[id].size();
		if(siz>1)sum[id][siz-1]+=sum[id][siz-2];
		mx[id].push_back(lenc);
		if(siz>1)mx[id][siz-1]=max(mx[id][siz-1],mx[id][siz-2]);
	}
	scanf("%d",&q);
	while(q--){
		ans=0;
		scanf("%s",in);
		lenc=strlen(in);
		if(!mp.count(in[0])){
			ans+=n;
			printf("%d\n",ans);
			continue;
		}
		id=mp[in[0]];
		if(lenc>*mx[id].rbegin()){
			ans+=n+*sum[id].rbegin();
			printf("%d\n",ans);
			continue;
		}
		l=0,r=a[id].size()-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(mx[id][mid]>=lenc)ss=mid,r=mid-1;
			else l=mid+1;
		}
		ans+=a[id][ss].second;
		if(ss)ans+=sum[id][ss-1];
		if(a[id][ss].first!=lenc)ans+=(a[id].size()-ss)*lenc+n-a[id][ss].second;
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
a
aa
aaa
aaaa
aaaaa
6
a
aa
aaa
aaaa
aaaaa
aaaaaa

2 5 9 14 20 20
*/
/*
9
ddddddddddd
lllllllllllllllllllllllll
uuuuuuuuuuuuuuuuuuuuu
yyyyyyyyyyyyyyyyyyyyyy
aaaaaaaaaaaaaaaaaaaaaaaaaaa
oooooooooooooooo
wwwwwwwwwwwwwwwwwwwww
ooooooooooooooooooooooooooooo
aaaaaaaaaaaaa
1
ooooooooooo

31
*/
