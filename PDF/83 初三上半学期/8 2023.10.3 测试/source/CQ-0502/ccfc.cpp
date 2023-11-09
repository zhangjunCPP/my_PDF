#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
#define ull unsigned long long 
ull Hash[maxn],pw[maxn];
const ull p=131; 
inline ull H(int l,int r){
	ull sum=Hash[r]-Hash[l-1]*pw[r-l+1];
	return sum;
}
inline bool cmp(int l1,int r1,int l2,int r2){
	return H(l1,r1)==H(l2,r2);
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout); 
	scanf("%s",s+1);
	int n=strlen(s+1);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*p;
	for(int i=1;i<=n;i++) Hash[i]=Hash[i-1]*p+(ull)s[i];
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i+2;j<=n;j+=2){
			int len=j-i;
			int len2=len/2;
			int en=n-len2;
			if(j<=en){
				if(cmp(i,i+len2-1,i+len2,j-1) && cmp(i,i+len2-1,en+1,n)){
					ans++;
				}
			}
			else{
				break;
			}
		}
		printf("%d",ans);
		if(i!=n) printf(" ");
	}
	return 0;
}
/*
ouvouvouvouvou
0 0 1 0 0 0 0 0 0 0 0 0 0 0

vouvouvouvou
对于一个字符串，枚举B串的开头，直接计算A串结尾即可，Hash 判断。
n^2 
*/
