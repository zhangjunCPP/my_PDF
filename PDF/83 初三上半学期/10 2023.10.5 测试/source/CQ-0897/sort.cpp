#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned LL
	#define Re register
	#define f(a,b,i) for(Re int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		static bool fl;
		static char ch;
		x=0;
		fl=0;
		ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
		}
		if(ch=='.'){
			ch=getchar();
			static db d;
			d=1.0;
			while('0'<=ch&&ch<='9'){
				x+=d*(ch^48);
				d*=0.1;
				ch=getchar();
			}
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 100050

int n;

int a[N];

vector<int>b,c;

int cnt=0;

In void Sort(int l,int r){
	if(r<=l)return;
//	cout<<l<<" "<<r<<endl;
//	f(l,r,i)cout<<a[i]<<" ";
//	cout<<endl;
	int amid=a[l+(int)ceil((r-l+1)/2.0)-1];
	b.clear();
	c.clear();
//	cout<<amid<<endl;
	f(l,r,i){
		cnt++;
		if(a[i]<amid)b.emplace_back(a[i]);
		if(a[i]>amid)c.emplace_back(a[i]);
	}
	int it=l;
	for(auto x:b)a[it++]=x;
	int jt=it;
	a[it++]=amid;
	for(auto x:c)a[it++]=x;
//	f(l,r,i)cout<<a[i]<<" ";
//	cout<<endl;
	Sort(l,jt-1);
	Sort(jt+1,r);
}

int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
//	freopen("D:\\down\\sort\\sort5.in","r",stdin);
	read(n);
	f(1,n,i)read(a[i]);
	Sort(1,n);
	printf("%d",cnt);
	return 0;
}

