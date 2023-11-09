#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define In inline
	#define ULL unsigned long long
	#define Re register
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		x=0;
		bool fl=0;
		char ch=getchar();
		while(ch<'0'||'9'<ch){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=x*10+(ch^48);
			ch=getchar();
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

int n,k,L;

typedef pair<int,int> Pi;

vector<Pi>el;
vector<Pi>er;

db dis[N];

int main(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	read(n,k,L);
	L++;
	int x,c;
	char opt;
//	er.emplace_back(0,0);
	f(1,n,i){
		read(x,c);
		scanf("%c",&opt);
		x++;
		if(opt=='L')el.emplace_back(x,c);
		else er.emplace_back(x,c);
	}
	sort(el.begin(),el.end());
	sort(er.begin(),er.end());
	for(auto i:er)if(i.first!=0)dis[i.second]+=L-i.first;
	for(auto i:el){
		db used=0;
		int col=i.second;
		f_((int)er.size()-1,0,j){
			if(er[j].first>i.first)continue;
			dis[col]+=(i.first-er[j].first)/2.0-used;
			col=(col+er[j].second)%k;
			used=(i.first-er[j].first)/2.0;
		}
		dis[col]+=i.first-1-used;
	}
	ff(0,k,i)printf("%.1lf\n",dis[i]);
	return 0;
}

