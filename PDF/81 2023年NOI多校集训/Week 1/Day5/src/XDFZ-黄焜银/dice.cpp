/*
注意题目的要求
异或和是k的倍数 
a^b==3
那么a^3==b
尽量取小的，题目有值域限制 
*/ 
#include<bits/stdc++.h>
using namespace std;
inline int re(){
    int x=0;bool f=1;
    char c=getchar();
    while(c<48||c>57){if(c==45)f=0;c=getchar();}
    while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?x:-x;
}
void wr(int x){
    if(x<0)putchar(45),x=-x;
    if(x>9)wr(x/10);
    putchar(x%10+48);
}
int n,k,i,j,cnt,num[20000000];
set<int>st;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	n=re(),k=re();
//	for(i=0;i<6;++i)st.insert(i);
//	for(i=2;i<n;++i){
//		printf("i=%d\n",i);
//		cnt=0;
//		set<int>::iterator it=st.begin();
//		while(it!=st.end()){
//			for(j=0;j<6;++j)num[++cnt]=*it^j;
//			++it;
//		}
//		for(j=1;j<=cnt;++j)st.insert(num[j]);
//	}
//	set<int>::iterator it=st.begin();
//	while(it!=st.end())printf("%d ",*it),++it;
	if(n==1){
		puts("Yes");
		for(i=0;i<6;++i)printf("%d ",k*i);
		return 0;
	}
	if(k==2){
		puts("Yes");
		if(n&1){
			for(i=0;i<6;++i)printf("%d ",i*2+1);putchar(10);
			for(i=0;i<6;++i)printf("%d ",i*2+1);putchar(10);
			n-=2;
			while(n--){for(i=0;i<6;++i)printf("%d ",i*2);putchar(10);}
		}
		else while(n--){for(i=0;i<6;++i)printf("%d ",i*2);putchar(10);}
		return 0;
	}
	puts("No");
    return 0;
}

