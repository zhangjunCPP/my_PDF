#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long ull;
int t,n,m,k;
char a[200005],p[200005];
ull h1[200005],h2[200005],pn1[200005];
ull get(ull h[],int l,int r){return h[r]-h[l-1]*pn1[r-l+1];}
void init(ull h[],ull pn[],char a[],int n){
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*pn[1]+a[i]-'a';
}
void Freopen(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int main(){
	Freopen();
	scanf("%d%s%d",&k,a+1,&t);n=strlen(a+1);
	pn1[0]=1;pn1[1]=13331;for(int i=2;i<=200000;i++)pn1[i]=pn1[i-1]*pn1[1];
	init(h1,pn1,a,n);
	while(t--){
		scanf("%s",p+1);m=strlen(p+1);
		init(h2,pn1,p,m);
		int ans=0;
		for(int i=1;i<=n-m+1;i++){
			int l1=i,l2=1,first=-1,last=-1;
			while(1){
				int l=0,r=m-l2+1;
				while(l<r){
					int mid=(l+r+1)>>1;
					if(get(h1,l1,l1+mid-1)!=get(h2,l2,l2+mid-1))r=mid-1;
					else l=mid;
				}
				if(r==m-l2+1)break;
				l1+=l+1,l2+=l+1;
				if(first==-1)first=l1-1;
				last=l1-1;
				if(l2>m)break;
			}
			//printf("%d %d %d\n",i,first,last);
			if(last-first<k)++ans;
		}
		printf("%d\n",ans);
	}
}
/*
2
baccbcbabc
1
abc
*/
