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
#define mod 1000000007
long long t,n,m,k,cnt,ans,cor[1050],fir[1050];
struct edge{
	long long fr,to,dif,sam,nxt;
}e[1000050];
inline void Calc(long long x){
	long long res=1;
	for(int i=1;i<=m;i++){
		if(cor[e[i].fr]==cor[e[i].to]){
			res*=e[i].sam;
		}else{
			res*=e[i].dif;
		}
	}
	for(int i=0;i<x;i++){
		res*=k-i;
		res%=mod;
	}
	ans+=res;
	ans%=mod;
	return;
}
void dfs(long long x,long long Con){
	if(Con>k){
		return;
	}
	if(x>n){
		Calc(Con);
		return;
	}
	for(int i=1;i<=Con;i++){
		cor[x]=i;
		dfs(x+1,Con);
	}
	cor[x]=Con+1;
	dfs(x+1,Con+1);
	return;
}
int main(){
	freopen("trans.in","r",stdin);
	freopen("trans.out","w",stdout);
	read(t);
	while(t--){
		ans=0;
		read(n);
		read(m);
		read(k);
		bool fl=1;
		for(int i=1;i<=m;i++){
			read(e[i].fr);
			read(e[i].to);
			read(e[i].dif);
			read(e[i].sam);
			if(e[i].sam!=0){
				fl=0;
			}
		}
		if(fl){
			ans=1;
			for(int i=1;i<=m;i++){
				ans*=e[i].dif;
				ans%=mod;
			}
			for(;n;n--){
				ans*=k;
				ans%=mod;
				k--;
			}
		}else{
			dfs(1,0);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

