#include<cstdio>
#include<vector>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x=x/10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
int n,cnt;
std::vector<int>a;
std::vector<int>sort(std::vector<int>b){
	int len=b.size();
	if(len<=1)return b;
	std::vector<int>al,ar,ii;
	int jk=b[len/2+(len%2==0?0:1)-1];
	for(int x:b){
		cnt++;
		if(x<jk)al.emplace_back(x);
		if(x>jk)ar.emplace_back(x);
	}
	al=sort(al);for(int x:al)ii.emplace_back(x);
	ii.emplace_back(jk);ar=sort(ar);for(int x:ar)ii.emplace_back(x); 
	return ii;
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	read(n);
	for(int i=1,x;i<=n;++i)read(x),a.emplace_back(x);
	sort(a);
	write(cnt);
	return 0;
}
