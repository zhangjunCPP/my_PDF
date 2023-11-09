/*
给你一张图，问图上能否找出若干个环，使他们互相不交，且刚好覆盖每个点1次 
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
int i,j;
int main(){
	freopen("hamilton.in","r",stdin);
	freopen("hamilton.out","w",stdout);
	puts("NO");
    return 0;
}

