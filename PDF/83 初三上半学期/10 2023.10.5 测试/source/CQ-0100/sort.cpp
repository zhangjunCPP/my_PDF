#include <cstdio>
// #include <vector>
using ll=long long;
constexpr int N=700010;
int Ch,n,a[N],id[N],i;
ll ans;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename T>
void w(T&&x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
// void Sort(std::vector<int>&a){
// 	if(a.size()<2){
// 		// k+=a.empty();
// 		return;
// 	}
// 	int k=a[a.size()-1>>1];
// 	std::vector<int>l,r;
// 	ans+=a.size();
// 	for(auto x:a){
// 		if(x<k)l.emplace_back(x);
// 		else if(x>k)r.emplace_back(x);
// 	}
// 	a.clear();
// 	Sort(l);
// 	Sort(r);
// }
class P_SGT{
	struct ss{
		int x,l,r;
	}t[N*22];
	int root[N],now,tot;
public:
	void u(const int&id){
		now++;
		int x=root[now]=++tot,L=1,R=n,mid,old=root[now-1];
		while(L<R){
			mid=L+R>>1;
			t[x].x=t[old].x+1;
			// printf("%d old=%d [%d,%d]" ,x,old,L,R);
			if(id<=mid){
				// printf(" l\n");
				R=mid;
				t[x].r=t[old].r;
				x=t[x].l=++tot;
				old=t[old].l;
			}
			else{
				// printf(" r\n");
				L=mid+1;
				t[x].l=t[old].l;
				x=t[x].r=++tot;
				old=t[old].r;
			}
		}
		t[x].x=1;
	}
	int q(const int&L,const int&R)const{
		int x=root[L-1],y=root[R],k=R-L+2>>1,l=1,r=n,mid;
		while(l<r){
			// printf("%d %d %d\n",x,y,k);
			mid=l+r>>1;
			if(t[t[y].l].x-t[t[x].l].x>=k){
				y=t[y].l;
				x=t[x].l;
				r=mid;
			}
			else{
				k-=t[t[y].l].x-t[t[x].l].x;
				y=t[y].r;
				x=t[x].r;
				l=mid+1;
			}
		}
		return l;
	}
}t;
void solve(const int&l,const int&r){
	if(l>=r)return;
	ans+=r-l+1;
	int k=a[t.q(l,r)];
	// fprintf(stderr,"%d %d %d\n",l,r,k);
	solve(l,k-1);
	solve(k+1,r);
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	r(n);
	// std::vector<int>a;
	for(i=1;i<=n;i++){
		r(a[i]);
		id[a[i]]=i;
		// a.emplace_back(k);
	}
	for(i=1;i<=n;i++)t.u(id[i]);
	// printf("%d\n",t.q(1,n));
	// Sort(a);
	solve(1,n);
	w(ans);
	return 0;
}