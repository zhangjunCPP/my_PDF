#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch = getchar();int x = 0, f = 1;
	while(ch<'0'||ch>'9'){if(ch == '-') f = -1;ch = getchar();}
	while('0'<=ch && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
int n,m;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	n=read(),m=read();
	if (n==1){
		puts("Yes");
		for (int i=1;i<=6;i++)
			printf("%d ",i*m);
		return 0;
	} if (m==2){
		puts("Yes");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=6;j++)
				printf("%d ",2*i*j);
			puts("");
		} return 0;
	} if (m&1){ puts("No"); return 0; }
	else{
		puts("Yes");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=6;j++)
				printf("%d ",i*j*m);
			puts("");
		}
	}
	return 0;
} 
