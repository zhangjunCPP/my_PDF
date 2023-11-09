/*
疑似水题？
字符串哈希
不会被卡吧？ 
*/ 
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull N=1e5+10,p=233;
ull h[N],jc[N];
ull ha(int i,int len){
	int j=i+len-1;
	return h[j]-(i?h[i-1]*jc[len]:0);
}
char s[N];
int len,i,l,ans[N];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	jc[0]=1;
	for(i=1;i<=len;++i)jc[i]=jc[i-1]*p;
	for(i=0;i<len;++i){
		h[i]=s[i];
		if(i)h[i]+=h[i-1]*p;
	}
//	while(1){
//		int x,y;
//		scanf("%d%d",&x,&y);
//		printf("%d\n",ha(x,y));
//	}
	for(i=0;i<len;++i){
//		if((len-i)%4)continue;
		for(l=(len-i-1)/3;l;--l){
			if(ha(i,l)==ha(i+l,l)&&ha(i+l,l)==ha(len-l,l))
				++ans[i];
		}
	}
	for(i=0;i<len;++i)printf("%d ",ans[i]);
	return 0;
}

