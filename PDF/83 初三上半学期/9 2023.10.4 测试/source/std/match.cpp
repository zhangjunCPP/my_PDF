#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ 666666
#define S 20
struct SA
{
int s[1234567],n,s0[SZ];
inline void push(int c) {s[n++]=c;}
int sa[SZ],rk[SZ],su[SZ],ork[SZ]; int h[SZ];
inline bool diff(int a,int b,int g)
{return ork[a]!=ork[b]||ork[a+g]!=ork[b+g];}
int mi[S][SZ],l2[SZ];
void build(int N)
{
	int G=n+300;
	for(int i=0;i<=G;++i) su[i]=0;
	for(int i=0;i<n;++i)
		++su[rk[i]=s[i]];
	for(int i=1;i<=G;++i) su[i]+=su[i-1];
	for(int i=0;i<n;++i)
		sa[--su[rk[i]]]=i;
	for(int g=1;g<=n;g<<=1)
	{
		for(int i=0;i<=G;++i) su[i]=0;
		static int ts[SZ]; int tn=0;
		for(int i=n-1;i>=0;--i)
		{
			if(sa[i]>=g) ts[++tn]=sa[i]-g;
			ork[i]=rk[i];
		}
		for(int i=n-g;i<n;++i) ts[++tn]=i;
		for(int i=1;i<=tn;++i) ++su[rk[ts[i]]];
		for(int i=1;i<=G;++i) su[i]+=su[i-1];
		for(int i=1;i<=tn;++i)
			sa[--su[rk[ts[i]]]]=ts[i];
		int t=0;
		for(int i=0;i<n;++i)
		{
			if(i&&diff(sa[i-1],sa[i],g)) ++t;
			rk[sa[i]]=t;
		}
		G=t;
	}
	for(int i=0;i<n;++i) rk[sa[i]]=i;
	for(int i=0;i<n;++i) s0[i+1]=s0[i]+(sa[i]<N);
	int g=0;
	for(int i=0;i<n;++i)
	{
		g=max(g-1,0);
		if(rk[i]==n-1)
		{
			h[rk[i]]=0;
			continue;
		}
		int A=i,B=sa[rk[i]+1];
		while(s[A+g]==s[B+g]) ++g;
		h[rk[i]]=g;
	}
	for(int i=0;i<n;++i) mi[0][i]=h[i];
	for(int u=0;u+1<S;++u)
		for(int i=0;i+(1<<(u+1))<=n;++i)
			mi[u+1][i]=min(mi[u][i],mi[u][i+(1<<u)]);
	for(int i=1,j=0;i<n;++i)
	{
		while((1<<j)<=i) ++j;
		l2[i]=--j;
	}
}
inline int qmin(int l,int r)
{
	int w=l2[r-l+1];
	return min(mi[w][l],mi[w][r-(1<<w)+1]);
}
}S0,S1;
typedef pair<int,int> pii;
#define fi first
#define se second
int k,q,n;
#define SS 2555555
#define mp make_pair
struct DS
{
pii u[SS]; int un=0;
int *o0[SS],o1[SS],o2[SS],o3[SS];
void push(int x,int y)
{
	++un;
	u[un]=mp(x*2,un);
	o1[un]=y+1;
}
void push_query(int x,int l,int r,int& t1,int t2)
{
	if(l>r) return;
	++un;
	u[un]=mp(x*2+1,un);
	o1[un]=l+1; o2[un]=r+1;
	o0[un]=&t1; o3[un]=t2;
}
int bs[SZ];
void edt(int x,int y)
{
//	cout<<"edt "<<x<<"\n";
	for(;x<SZ;x+=x&-x) bs[x]+=y;
}
int qsum(int l,int r)
{
//	cout<<"qsum "<<l<<","<<r<<"\n";
//	if(l>r) return 0;
	int s=0;
	for(;r;r-=r&-r) s+=bs[r];
	for(--l;l;l-=l&-l) s-=bs[l];
	return s;
}
void work()
{
	sort(u+1,u+1+un);
	for(int i=1;i<=un;++i)
	{
		int j=u[i].se;
		if(!(u[i].fi&1)) edt(o1[j],1);
		else
			*o0[j]+=o3[j]*qsum(o1[j],o2[j]);
//			cout<<*o0[j]<<"("<<o0[j]<<")\n";

	}
}
}U[2];
string u[SZ];
int ans[SZ];
char s[SZ],buf[SZ];
ll work(int o,int bp,int m,int&target,int tk)
{
	int len=k-o;
//	if(!len) return 0;
	ll ans=0;
	for(int r=1;r-len+1<=m;++r)
	{
		//ignore [r-len+1,r]
		int a=r-len,b=r+1;
//		cout<<"ignore:"<<r-len+1<<"~"<<r<<"\n";
		//let u[a] match s[x]
		//u[1] match s[x-a+1]
		//u[m] match s[x-a+m]
		assert(a>=1||b<=m);
		/*
		if(a>=1)	s[..x] need to match u[1..a]
		else		need x>=a
		if(b<=m)	s[x+len+1..] need to match u[b..m]
		else		need x+1+len<=n-m+b
		
		x>=1-len
		x<=n-1
		*/
		int l1,r1,l2,r2;
		auto workl=[&](SA&ss,int w,int a)
		{
			if(ss.h[w-1]<a) return w;
			int o=w-1;
			//min(l..o)>=a
			for(int j=1;;j<<=1)
			{
				int r=o-j+1,l=max(o-(j+j)+2,0),
				*sm=ss.mi[ss.l2[o-l+1]];
				if(l==0||sm[l]<a)
				{
					int L=l,R=r+1;
					while(L<R)
					{
						int M=(L+R)>>1;
						if(sm[M]>=a) R=M;
						else L=M+1;
					}
					return L;
				}
			}
		};
		auto workr=[&](SA&ss,int w,int a)
		{
			if(ss.h[w]<a) return w;
			int o=w;
			for(int j=1;;j<<=1)
			{
				int l=o+j-1,r=min(o+(j+j)-2,S1.n-2),
				u=ss.l2[l-o+1],
				*sm=ss.mi[u]-(1<<u)+1;
				if(r==S1.n-2||sm[r]<a)
				{
					int L=l-1,R=r;
					while(L<R)
					{
						int M=(L+R+1)>>1;
						if(sm[M]>=a) L=M;
						else R=M-1;
					}
					return L+1;
				}
			}
//			int L=w,R=S1.n-1;
//			while(L<R)
//			{
//				int M=(L+R+1)>>1;
//				if(ss.qmin(w,M-1)>=a) L=M;
//				else R=M-1;
//			}
//			return L;
		};
		if(a>=1)
		{
			//s[..x] need to match u[1..a]
			int w=S1.rk[bp+m+1-a];
			int l=workl(S1,w,a),r=workr(S1,w,a);
			l1=S1.s0[l]+1; r1=S1.s0[r+1];
		}
		else
		{
			l1=a, r1=n;
		}
		if(b<=m)
		{
			//s[x+len+1..] need to match u[b..m]
			int w=S0.rk[bp+b];
			int l=workl(S0,w,m-b+1),r=workr(S0,w,m-b+1);
//			cout<<l<<"~"<<r<<" cv"<<w<<" "<<S0.qmin(l,r-1)<<"EZ\n";
			l2=S0.s0[l]+1; r2=S0.s0[r+1];
//			cout<<"len"<<m-b+1<<" "<<bp+b<<"\n";
//			for(int i=l;i<=r;++i) cout<<S0.sa[i]<<"|";cout<<"\n";
		}
		else
		{
			l2=1, r2=n-m+b;
		}
//		cerr<<l2<<","<<r2<<"EZ\n";
		U[o].push_query(r1,l2,r2,target,tk);
		U[o].push_query(l1-1,l2,r2,target,-tk);
	}
//	cout<<len<<":"<<ans<<"\n";
	return ans;
}
int bp[SZ];



int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout); 
	scanf("%d\n",&k);
	assert(k>=1);
	while(!s[1]) cin>>(s+1);
	scanf("%d\n",&q);
	n=strlen(s+1);
	if(n<=k)
	{
		for(int i=1;i<=q;++i)
			puts("0");
		return 0;
	}
	for(int i=1;i<=q;++i)
	{
		buf[0]=0;
		while(!buf[0]) cin>>(buf);
		u[i]=buf;
	}
//	cerr<<"+\n";
	for(int i=1;i<=n;++i) S0.push(s[i]);
	S0.push(300);
	for(int i=1;i<=q;++i)
	{
		bp[i]=S0.n-1;
		for(int j=0;j<u[i].size();++j)
			S0.push(u[i][j]);
	}
//	cerr<<"+\n";
	for(int i=n;i>=1;--i) S1.push(s[i]);
	S1.push(300);
	for(int i=1;i<=q;++i)
	{
		for(int j=0;j<u[i].size();++j)
			S1.push(u[i][u[i].size()-1-j]);
	}
//	cerr<<"+\n";
	S0.build(n); S1.build(n);
//	cerr<<"+\n";
	for(int o=0;o<2;++o)
	{
		int len=k-o;
		for(int x=-len+1;x<n;++x)
		{
			int y=x+len+1;
			int p,q;
			if(x>=1) p=S1.s0[S1.rk[n-x]+1];
			else p=x;
			if(y<=n) q=S0.s0[S0.rk[y-1]+1];
			else q=y;
			U[o].push(p,q);
//			cout<<x<<","<<y<<" "<<p<<","<<q<<"  "<<n<<"\n";//"  "<<S1.rk[n-x]<<","<<S0.rk[y-1]<<"\n";
		}
	}
//	cerr<<"+\n";
//	for(int i=0;i<S0.n;++i)
//	{
//		if(S0.s[i]<128) putchar(S0.s[i]);
//		else putchar('?');
//	}
//	puts("");
//	cerr<<"+\n";
	for(int i=1;i<=q;++i)
	{
		if(u[i].size()>n) ans[i]=0;//puts("0");
		else if(u[i].size()<=k) ans[i]=int(n-(int)u[i].size()+1);
		else
//			cout<<i<<"!!\n",
			work(0,bp[i],u[i].size(),ans[i],1),
			work(1,bp[i],u[i].size(),ans[i],-1);
	}
//	cerr<<"O\n";
	U[0].work(); U[1].work();
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	//cerr<<clock()<<"ms\n";
}

