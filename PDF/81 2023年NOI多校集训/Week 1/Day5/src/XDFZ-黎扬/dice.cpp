#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//题目要求构造n个长为6的序列,满足从每个序列中任意挑出一个数使得所有数的异或和为k的倍数
//a[1]^a[2]^a[3]^...^a[n-1]^a[n]=p*k(p为常数)
int n,k,a[105][15];
int main(){
	freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    n=read();
    k=read();
    if(n==1){
        puts("Yes");
        for(int i=1;i<=6;i++){
            work(i*k);
            putchar(' ');
        }
    }
    else if(k==2){
        puts("Yes");
        for(int i=1;i<=(n-(n&1));i++){
            for(int j=1;j<=6;j++){
                work(2*j*i-1);
                putchar(' ');
            }
            putchar('\n');
        }
        if(n&1){
            for(int i=1;i<=6;i++){
                work(2*i);
                putchar(' ');
            }
        }
    }
    else if(n==2){
        puts("Yes");
        for(int i=1;i<=6;i++){
            work(i*k);
            putchar(' ');
        }
        putchar('\n');
        for(int i=1;i<=6;i++){
            work(i*k*512);
            putchar(' ');
        }
    }
    else
        puts("No");
	return 0;
}