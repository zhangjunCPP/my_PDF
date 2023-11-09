#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char ch;
	bool sgn=0;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=x*10+ch-48;
	}
	if(sgn){
		x=-x;
	}
	return;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
inline void read(long long &x){
	x=0;
	char ch;
	bool sgn=0;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=x*10+ch-48;
	}
	if(sgn){
		x=-x;
	}
	return;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
long long t,m,n,ans,cnt,deg[1000050],fir[1000050];
bool vis[1000050];
struct edge{
	long long fr,to,key,nxt;
}e[2000050];
inline void add(long long fr,long long to){
	e[++cnt].fr=fr;
	e[cnt].to=to;
	e[cnt].nxt=fir[fr];
	fir[fr]=cnt;
	return;
}
inline long long Calc(long long x){
	long long res=0,cir=0;
	for(int i=fir[x];i;i=e[i].nxt){
		res+=1ll*(vis[e[i].to]^1);
		vis[e[i].to]=1;
	}
	for(int i=fir[x];i;i=e[i].nxt){
		long long y=e[i].to;
		for(int j=fir[y];j;j=e[j].nxt){
			cir+=vis[e[j].to];
		}
	}
	for(int i=fir[x];i;i=e[i].nxt){
		vis[e[i].to]=0;
	}
	return res+cir/2;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		read(m);
		cnt=0;
		ans=0;
		for(int i=1;i<=n;i++){
			fir[i]=0;
		}
		bool is_chain=1,is_circle=1,is_flower=1;
		if(m!=n-1){
			is_chain=is_flower=0;
		}
		if(m!=n){
			is_circle=0;
		}
		for(int i=1;i<=m;i++){
			long long fr,to;
			read(fr);
			read(to);
			add(fr,to);
			add(to,fr);
			deg[fr]++;
			deg[to]++;
			if(fr!=1){
				is_flower=0;
			}
			if(fr!=i){
				is_chain=is_circle=0;
			}
			if(to!=i+1){
				is_chain=0;
			}
			if(to!=i%n+1){
				is_circle=0;
			}
		}
		if(n>1000&&(is_chain||is_circle)){
			write(2);
			putchar('\n');
			continue;
		}
		if(n>1000&&is_flower){
			write(deg[1]);
			putchar('\n');
			continue;
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,Calc(i));
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

