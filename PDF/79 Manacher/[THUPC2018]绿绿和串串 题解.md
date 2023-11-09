# [#6723. [THUPC2018]绿绿和串串]([登录 - 个人在线评测](https://www.fzoi.top/problem/6723))

> 逼两句，我的做法很简单（就是来混口饭吃的），请不要因为过于简单而大吼大叫

## 题目大意

翻转操作：`abc` -> `abcba`

给你一个串$S$（经过（多次）翻转后）的部分，求出翻转前的串的长度

有一个限制条件，因为$len>|S|$一定是一个解，所以输出的长度必须$\leqslant|S|$

## 正解

首先，根据这个翻转的定义，翻转后的回文串是奇数长度，也就是说不用往串里插`#`

那么，如串`abcb`，可以发现，以`c`为中心的回文串为`bcb`，也就是说原串可能为`abc`，翻转后为`abcba`，然后题目只给了你`abcb`的部分

以此类推，大体上形如`abcb`的串，都可以把`abc`当作原串进行翻转

> `FukaMyWifefiW`，`a`=`FukaMy`，`b`=`Wif`，`c`=`e`
> 
> 题目中没有大写字母，这里是为了方便各位阅读而打的大写

总结就是，若以$i$为中心的回文串的最右端为S的最后一个字母，那么$i$就是一个答案



这个结论就是只翻转一次的情况，若多次呢？



多次的话，其实可以借助只翻转一次的情况

例如样例中的`qwqwq`，$s[3]$首先肯定是一个合法答案（翻转一次），再看$s[2]$，以$s[2]$为中心的最长回文串为$s[1]$~$s[2]$，`qwq`，这里，我们可以理解为原串为`qw`，翻转一次后为`qwq`，在翻转一次后为`qwqwq`

再举个例，`ElysiaMyWifefiWyMaisylElysia`，原串为`ElysiaMyWife`，翻转一次`ElysiaMyWifefiWyMaisylE`，再翻转一次`ElysiaMyWifefiWyMaisylElysiaMyWifefiWyMasiylE`，砍一下就是给的串了♪

总结，若以$i$为中心的最长回文串的左端点为$|S|$的开头并且右端点为一个合法的答案，那么$i$就是一个合法答案

```
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int len[N],n;
char s[N];
bool vis[N];
void manacher(){
	int mx=0,pos=0;
	for(int i=1;i<=n;++i){
		vis[i]=false;
		len[i]=(i<mx?min(len[(pos<<1)-i],mx-i):1);
		while(s[i+len[i]]==s[i-len[i]]) ++len[i];
		if(i+len[i]>mx) mx=i+len[i],pos=i;
	}
}
int ans[N],tot;
void solve(){
	tot=0;
	for(int i=n;i;--i) if(i+len[i]-1==n||(vis[i+len[i]-1]&&i-len[i]+1==1)) ans[++tot]=i,vis[i]=true;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),s[0]='%';
		manacher(),solve();
		for(int i=tot;i;--i) printf("%d ",ans[i]);
		printf("\n");
	}

	return 0;
}

```













爱门！

![是](https://cdn.fzoi.top/upload/user/yx20231001/22112108594547.jpeg)
