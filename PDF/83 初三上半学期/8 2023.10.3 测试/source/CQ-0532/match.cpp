#include <cstdio>
#include <bitset>
constexpr int N=1000010;
int n,m,tot,i,j,k,hd[N],nxt[N],addr[N],ed[N],Ch;
std::bitset<N>a,b,c,d;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
inline void w(const std::bitset<N>&a){
	for(i=m;i;i--)putchar(a[i]|48);
}
inline void w(){
	putchar(45);
	putchar(49);
}
inline int cmp(const std::bitset<N>&a,const std::bitset<N>&b){
	static int i;
	for(i=m;i&&a[i]==b[i];i--);
	if(i)return a[i]?i:-i;
	return 0;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	r(n);
	r(m);
	for(i=1;i<=n;i++){
		r(j);
		if(!j){
			i--;
			n--;
			continue;
		}
		r(k);
		addr[++tot]=k;
		ed[i]=hd[i]=tot;
		while(--j){
			r(k);
			addr[++tot]=k;
			ed[i]=nxt[ed[i]]=tot;
		}
	}
	if(!n){
		while(m--)putchar(48);
		return 0;
	}
	if(n==1){
		for(i=hd[1];i;i=nxt[i])a.set(addr[i]);
		w(a);
		return 0;
	}
	if(n==2){
		for(i=hd[1];i;i=nxt[i])a.set(addr[i]);
		for(i=hd[2];i;i=nxt[i])b.set(addr[i]);
		c=a&b;
		if(c.none()){
			w(a|b);
			return 0;
		}
		if(!(i=cmp(a,b))){
			if(addr[ed[1]]==m){
				w();
				return 0;
			}
//			printf("%d %d\n",m,addr[ed[1]]);
			a.set(addr[ed[1]]+1);
			w(a);
			return 0;
		}
		j=m+1;
		for(i=m;!a[i]||!b[i];i--)if(!a[i]&&!b[i])j=i;
		if(j>m){
			w();
			return 0;
		}
		c=b;
		c.set(j);
		for(k=m;k>j;k--)if(a[k])c.set(k);
		d=a;
		d.set(j);
		for(k=m;k>j;k--)if(b[k])d.set(k);
		w(cmp(c,d)>0?d:c);
		return 0;
	}
	if(n==m){
		while(m--)putchar(49);
		return 0;
	}
	if(n>m){
		w();
		return 0;
	}
	return 0;
}
