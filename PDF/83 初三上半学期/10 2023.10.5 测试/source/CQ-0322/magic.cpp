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
long long n,ans,o[1050],vis[1050],ord[1050];
struct Ball{
	long long l,r,c;
}a[10050];
inline void Calc(){
	long long res=0;
	for(int i=1;i<=n;i++){
		o[i]=1;
	}
	for(int i=1;i<=n;i++){
		o[vis[i]]=0;
		for(int j=a[vis[i]].l;j<=a[vis[i]].r;j++){
			res+=o[j]*a[vis[i]].c;
		}
	}
	ans=max(ans,res);
	return;
}
void dfs(long long x){
	if(x>n){
		Calc();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		ord[x]=i;
		vis[i]=x;
		dfs(x+1);
		vis[i]=0;
		ord[x]=0;
	}
	return;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	bool is_1=1;
	for(int i=1;i<=n;i++){
		read(a[i].l);
		read(a[i].r);
		read(a[i].c);
		if(a[i].l!=a[i].r){
			is_1=0;
		}
	}
	if(is_1){
		write(0);
		return 0;
	}
	dfs(1);
	write(ans);
	return 0;
}

