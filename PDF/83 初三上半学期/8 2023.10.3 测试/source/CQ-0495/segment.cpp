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
long long n,ans,vis[1000050],a[1000050];
inline void Calc(){
	long long Min=1145141919810114514,Max=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			continue;
		}
		long long val=a[i];
		if(vis[i+1]==0){
			val+=a[i+1];
		}
		Min=min(Min,val);
		Max=max(Max,val);
	}
	ans=min(ans,Max-Min);
	return;
}
void dfs(long long x){
	if(x>n){
		Calc();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	if(x!=n){
		dfs(x+2);
	}
	vis[x]=0;
	return;
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	ans=1145141919810114514;
	dfs(1);
	write(ans);
	return 0;
}

