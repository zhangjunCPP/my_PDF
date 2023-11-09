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
long long n,m,k,cnt,kno[1000050],vis[1000050],fir[1000050],d[1000050],is_posi[1000050];
vector<long long >rec[1000050];
struct edge{
	long long fr,to,val,nxt;
}e[1000050];
inline void add(long long fr,long long to,long long val){
	e[++cnt].fr=fr;
	e[cnt].to=to;
	e[cnt].val=val;
	e[cnt].nxt=fir[fr];
	fir[fr]=cnt;
	return;
}
long long dfs(long long x){
	if(is_posi[x]){
		return 0;
	}
	vis[x]=1;
	for(int i=fir[x];i;i=e[i].nxt){
		if(vis[e[i].to]){
			continue;
		}
		long long val=dfs(e[i].to);
		if(val==-1){
			continue;
		}
		rec[x].push_back(val+e[i].val);
	}
	sort(rec[x].begin(),rec[x].end());
	vis[x]=0;
	if(rec[x].size()>d[x]){
		return rec[x][d[x]];
	}else{
		return -1;
	}
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=k;i++){
		long long x;
		read(x);
		is_posi[x]=1;
	}
	if(is_posi[1]){
		write(0);
		return 0;
	}
	for(int i=1;i<=n;i++){
		read(d[i]);
	}
	for(int i=1;i<=m;i++){
		long long fr,to,val;
		read(fr);
		read(to);
		read(val);
		add(fr,to,val);
		add(to,fr,val);
	}
	dfs(1);
	sort(rec[1].begin(),rec[1].end());
	if(rec[1].size()<d[1]){
		write(-1);
	}else{
		write(rec[1][d[1]]);
	}
	return 0;
}
