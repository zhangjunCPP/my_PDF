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
long long n,m,k,q;
char s[1000050],t[1000000];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(k);
	char ch;
	while(ch=getchar(),ch<'!');
	s[++n]=ch;
	while(ch=getchar(),ch>'!'){
		s[++n]=ch;
	}
	read(q);
	for(int i=1;i<=q;i++){
		m=0;
		while(ch=getchar(),ch<'!');
		t[++m]=ch;
		while(ch=getchar(),ch>'!'){
			t[++m]=ch;
		}
		if(n*m>100000000){
			write(0);
			putchar('\n');
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(i+m-1>n){
				break;
			}
			long long dif=-1,fl=1;
			for(int j=1;j<=m;j++){
				if(s[i+j-1]!=t[j]){
					if(dif==-1){
						dif=j;
						continue;
					}
					if(dif!=-1&&j-dif>=k){
						fl=0;
						break;
					}
				}
			}
			ans+=fl;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

