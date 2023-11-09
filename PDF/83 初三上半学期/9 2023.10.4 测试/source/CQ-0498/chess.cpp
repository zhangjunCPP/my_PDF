#include<bits/stdc++.h>
using namespace std;
template<typename T> void _(T &x){
	x=0; bool f=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
}
const int N=4e3;
int p,k,n;
int ksm(int a,int b){
	int res=1;
	for(;b;b>>=1,a=a*a) if(b&1) res=res*a;
	return res;
}
namespace sub1{
	void work(){
		printf("%d\n",n*(n-1)/2);
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
			printf("%d %d\n",i,j);
	}
}
namespace sub2{
	void work(){
		puts("1");
		for(int i=0;i<n;i++) printf("%d ",i);
	}
}
namespace sub3{//sbsbsbsbsbsbsbsbsbsb
	vector<vector<int> > st;
	vector<int> now;
	vector<pair<int,int> > c;
	bool tag[N][N];
	bool dfs(int last){
		if((int)now.size()==p){
			st.emplace_back(now);
			now.clear();
			c.clear();
			return 1;
		}
		for(int i=last;i<n;i++){
			bool flag=1;
			for(auto j:now) if(tag[i][j]){
				flag=0;
				break;
			}
			if(flag){
				for(auto j:now){
					tag[i][j]=tag[j][i]=1; 
					c.emplace_back(make_pair(i,j));
				}
				now.emplace_back(i);
				dfs(i);
			}
		}
		for(;!c.empty();c.pop_back()){
			tag[c.back().first][c.back().second]=0;
			tag[c.back().second][c.back().first]=0;
		}
		return 0;
	}
	void work(){
		for(int i=0;i<n;i++) tag[i][i]=1;
		for(int i=1;i<=1000000;i++) dfs(0);
		printf("%d\n",(int)st.size());
		for(auto i:st){
			for(auto j:i) printf("%d ",j);
			puts("");
		}
	}
}
int main(){
//	cout<<ksm(5,5);
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&p,&k);
	n=ksm(p,k);
	if(p==2) sub1::work();
	else if(k==1) sub2::work();
	else sub3::work();//sbsbsbsbsbsbsbsbsbsbsb
	return 0;
}

