#include <cstdio>
constexpr int N=5000010;
int Ch,n,M,T,ans;
bool v[N];
struct stk{
	int stk_[N],*top_;
	stk():top_(stk_){}
	void init(){
		*stk_=n+1;
	}
	void push(const int&x){
		*++top_=x;
	}
	int top()const{
		return*top_;
	}
	int pop(){
		return*top_--;
	}
	int size()const{
		return top_-stk_;
	}
}a,b,c,d;
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
bool check(){
	bool ret=0;
	if(a.size()&&a.top()<b.top()){
		b.push(a.pop());
		ret=check();
		a.push(b.pop());
		if(ret)return true;
	}
	if(b.size()){
		c.push(b.pop());
		ret=check();
		b.push(c.pop());
		if(ret)return true;
	}
	if(c.size()&&c.top()==d.top()-1){
		d.push(c.pop());
		ret=check();
		c.push(d.pop());
		if(ret)return true;
	}
	return d.top()==1;
}
void dfs(const int&x){
	if(x>n){
		if(!check()){
			ans++;
			// for(int i=1;i<=n;i++){
			// 	printf("%d ",a.stk_[i]);
			// }
			// puts("");
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			a.push(i);
			dfs(x+1);
			a.pop();
			v[i]=false;
		}
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	r(T);
	while(T--){
		r(n);r(M);
		ans=0;
		b.init();
		d.init();
		dfs(1);
		w(ans);
		putchar(10);
	}
	return 0;
}