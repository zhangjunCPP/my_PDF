#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long ull;
int n;
char s[100005];
ull Hash1[100005],Hash2[100050],pn1[100005],pn2[100005];
void init(){
	pn1[0]=pn2[0]=1;pn1[1]=131,pn2[1]=13331;
	for(int i=2;i<=n;i++)
		pn1[i]=pn1[i-1]*pn1[1],
		pn2[i]=pn2[i-1]*pn2[1];
}
int len(int l,int r){return r-l+1;}
ull Get1(int l,int r){return Hash1[r]-Hash1[l-1]*pn1[len(l,r)];}
ull Get2(int l,int r){return Hash2[r]-Hash2[l-1]*pn2[len(l,r)];}
void Freopen(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%s",s+1);n=strlen(s+1);
	init();
	for(int i=1;i<=n;i++)
		Hash1[i]=Hash1[i-1]*pn1[1]+s[i]-'a',
		Hash2[i]=Hash2[i-1]*pn2[1]+s[i]-'a';
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=n;j>=i&&len(j,n)*3<len(i,n);j--)
			ans+=(Get1(i,i+2*len(j,n)-1)==Get1(j,n)*pn1[len(j,n)]+Get1(j,n));
		printf("%d ",ans);
	}
}
