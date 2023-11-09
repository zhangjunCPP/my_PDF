#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
ll resof[670][1<<15];//预处理每十位的结果
struct mybitset{//只压30位
	unsigned val[330];
	void set(int pos,int v){val[pos/30]|=v<<(pos%30);}
	void operator|=(const mybitset&o){for(int i=0;i<330;i++)val[i]|=o.val[i];}
	ll calc(){
		ll ret=1;
		for(int i=0,j=0;i<330;i++,j+=2)
		ret=ret*resof[j][val[i]&0b111111111111111]%mod*resof[j+1][(val[i]>>15)&0b111111111111111]%mod;
		return ret;
	}
};



int n,q,a[100010],prime[100010],pid[100010],tot;//注意下标从0开始,好和bitset吻合
void prime_init(){
	for(int i=2;i<=100000;i++)
	if(!prime[i]){prime[tot++]=i;for(int j=i;j<=100000;j+=i)prime[j]=1;}
	for(int i=0;i<tot;i++)pid[prime[i]]=i;
	for(int i=0;i<670;i++){
		resof[i][0]=1;
		for(int s=1;s<(1<<15);s++)resof[i][s]=resof[i][s&~-s]*prime[i*15+__builtin_ctz(s)]%mod;//注意到没有素数的位置被标了1 
	}
}
//前面70个直接乱求



struct fac_t{int p,t;};
vector<fac_t>fac[100010];
void fact_init(){
	for(int i=2;i<=100000;i++)
	if(fac[i].empty())for(int j=i;j<=100000;j+=i){
		int t=0,x=j;for(;x%i==0;x/=i)t++;
		fac[j].push_back({i,t});
	}
}


ll ans[100010];
struct Ques{int l,id;};
vector<Ques>ques[100010];
void first_70_solve(){
	for(int i=0;i<70;i++){
		static int mx[100010],ans_mx[100010];
		fill_n(ans_mx+1,q,0);fill_n(mx+1,n,0);
		for(int j=1;j<=n;j++){
			int x=0;
			for(auto _:fac[a[j]])if(_.p==prime[i]){x=_.t;break;}
			for(int k=j;k&&x>mx[k];k--)mx[k]=x;
			for(auto _:ques[j])ans_mx[_.id]=max(ans_mx[_.id],mx[_.l]);
		}
		ll powp[20]{1};
		for(int j=1;j<20;j++)powp[j]=powp[j-1]*prime[i];
		for(int j=1;j<=q;j++)(ans[j]*=powp[ans_mx[j]])%=mod;
	}
}


//莫队统计 
mybitset each[100010];
int bigf[100010],cnt[100010];//不会同时有两个大的
int blk,qtot;
struct moques{int l,r,id;bool operator<(const moques&o)const{return l/blk==o.l/blk?r<o.r:l<o.l;}}mo[220010];
void last_solve(){
	for(int i=1;i<=n;i++){
		for(auto x:fac[a[i]]){
			if(pid[x.p]>=70)bigf[i]=pid[x.p];
		}
	}
	static mybitset now;
	sort(mo+1,mo+qtot+1);
	int l=1,r=0;
	auto test=[&l,&r](int p){if(!p)return;if(!cnt[p])now.set(p,0);else now.set(p,1);};
	for(int i=1;i<=qtot;i++){
		while(l>mo[i].l)l--,cnt[bigf[l]]++,test(bigf[l]);
		while(r<mo[i].r)r++,cnt[bigf[r]]++,test(bigf[r]);
		while(l<mo[i].l)l++,cnt[bigf[l-1]]--,test(bigf[l-1]);
		while(r>mo[i].r)r--,cnt[bigf[r+1]]--,test(bigf[r+1]);
		each[mo[i].id]|=now;
	}
}
int main(){
	freopen("boring.in","r",stdin);
	freopen("boring.out","w",stdout);
	prime_init(),fact_init();
	cin>>n>>q;fill_n(ans+1,q,1);blk=1e5/sqrt(2.2e5);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,k;i<=q;i++){
		scanf("%d",&k);
		for(int l,r;k--;)scanf("%d%d",&l,&r),ques[r].push_back({l,i}),mo[++qtot]={l,r,i};
	}
	first_70_solve();
	last_solve();
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]*each[i].calc()%mod);
	return 0;
}
