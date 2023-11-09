#include<bits/stdc++.h>
using namespace std;
namespace io{
	template<typename T> T read(){
		T x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		return f?-x:x;
	}
	template<typename T> void read(T &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()){
			if(ch=='-'){
				f=1;
			}
		}
		for(;ch>='0'&&ch<='9';ch=getchar()){
			x=(x<<1)+(x<<3)+(ch^48);
		}
		x=f?-x:x;
	}
	template<typename T> void write(T x){
		if(x<0){
			x=-x,putchar('-');
		}
		if(x>9){
			write(x/10);
		}
		putchar(x%10+'0');
	}
}
using ll=long long;
const int N=1e5+5;
const int K=505;
int n,k,one;
int t[N];
ll sum[N];
struct node{
	int tm,cost;
	node(int _tm=0,int _cost=0){
		tm=_tm,cost=_cost;
	}
}p[K];
int main(){
	freopen("happy.in","r",stdin);
	freopen("happy.out","w",stdout);
	
	io::read(n),io::read(k);
	for(int i=1;i<=n;i++){
		io::read(t[i]);
	}
	for(int i=1;i<=k;i++){
		p[i]=node(io::read<int>(),io::read<int>());
	}
	p[k+1]=node(0,io::read<int>());
	if(!k){
		for(int i=1;i<=n;i++){
			io::write(p[k+1].cost),putchar('\n');
		}
	}else{
		sort(p+1,p+k+1+1,[](node a,node b){
			return a.cost==b.cost?a.tm>b.tm:a.cost<b.cost;
		});
		sum[0]=0;
		sum[1]=p[1].cost;
		for(int i=2;i<=n;i++){
			sum[i]=0x3f3f3f3f3f3f3f3f;
			for(int j=1;j<=i;j++){
				ll cost=0;
				for(int l=1;l<=k+1;l++){
					int tm=t[j]+p[l].tm-1;
					int _=lower_bound(t+1,t+n+1,tm)-t;
					cost+=p[l].cost;
					if(_>=i){
						break;
					}
				}
				sum[i]=min(sum[i],cost);
			}
		}
		for(int i=1;i<=n;i++){
			io::write(sum[i]-sum[i-1]),puts("");
		}
	}
	
	return 0;
}
