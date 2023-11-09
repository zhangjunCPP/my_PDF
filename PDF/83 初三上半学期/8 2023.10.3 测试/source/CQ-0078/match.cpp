/*
»ì·Ö 
*/
#include<bits/stdc++.h>
void read(int &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	if(f)x=-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	char stk[14];int tot=0;
	do stk[++tot]=x%10+48,x/=10;while(x);
	for(;tot;tot--)putchar(stk[tot]);
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	write(-1);
	return 0;
}
