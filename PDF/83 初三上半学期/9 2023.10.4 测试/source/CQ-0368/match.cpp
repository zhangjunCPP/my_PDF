#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
int n,k,m;
char s[2010],t[2010];
ull hs[2010],ht[2010],pn[2010];
auto code=[](ull*h,int l,int r){return h[r]-h[l-1]*pn[r-l+1];}; 
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%s%d",&k,s+1,&m);n=strlen(s+1);
	pn[0]=1;for(int i=1;i<=2000;i++)pn[i]=pn[i-1]*131;
	for(int i=1;i<=n;i++)hs[i]=hs[i-1]*131+s[i]-'a'+1;
	for(int i=1;i<=m;i++){
		scanf("%s",t+1);int len=strlen(t+1);
		for(int p=1;p<=len;p++)ht[p]=ht[p-1]*131+t[p]-'a'+1;
		int ans=0;
		for(int p=1;p+len-1<=n;p++){
			int l=1,r=len;
			while(l<r){
				int mid=l+r>>1;
				if(code(hs,p,p+mid-1)==ht[mid])l=mid+1;
				else r=mid;
			}if(l+k>len||code(hs,p+l+k-1,p+len-1)==code(ht,l+k,len))ans++;
		}printf("%d\n",ans);
	}
	return 0;
}
