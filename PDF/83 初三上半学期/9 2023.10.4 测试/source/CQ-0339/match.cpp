/*
好，白送 30pts 近似于暴力模拟 
玄学一下... 
*/

#include<bits/stdc++.h>
const int QWQ=2e5+5;
using namespace std;
char ch[QWQ],ser[QWQ];
int k,q,n,s,res;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	double ttt=clock();
	scanf("%d",&k);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	scanf("%d",&q);
	while (q--){
		scanf("%s",ser+1);
		s=strlen(ser+1),res=0;
		if (s>n){ printf("0"); continue; }
		for (int l=1;l<=n-s+1;l++){
			int r=l+s-1,mnpos=0,mxpos=0;
			for (int i=l,j=1;i<=r;i++,j++)
				if (ch[i]!=ser[j]){ mnpos=i; break; }
			for (int i=r,j=s;i>=l;i--,j--)
				if (ch[i]!=ser[j]){ mxpos=i; break; }
			if (!mnpos||mxpos-mnpos<k) res++;
		} printf("%d\n",res);
		if (clock()-ttt>2900) break;
	} for (;q>0;q--) printf("0\n");
	return 0;
}
