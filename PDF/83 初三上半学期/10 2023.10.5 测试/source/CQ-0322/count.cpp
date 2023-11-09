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
long long t,n,now,s[10050];
int rec[10000050];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(t);
	for(int n=1;n<=1000;n++){
		for(int j=1;j<=n;j++){
			rec[n*j]+=2;
		}
		rec[n*n]--;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s[n]+=rec[i*j];
			}
		}
	}
	now=1000;
	while(t--){
		long long x,ans=0;
		read(x);
		if(x<=1000){
			write(s[x]);
		}else{
			for(int i=now+1;i<=x;i++){
				for(int j=1;j<=i;j++){
					rec[i*j]+=2;
				}
				rec[i*i]--;
			}
			for(int i=1;i<=x;i++){
				for(int j=1;j<=x;j++){
					ans+=rec[i*j];
				}
			}
			now=x;
			write(ans);
		}
		putchar('\n');
	}
	return 0;
}

