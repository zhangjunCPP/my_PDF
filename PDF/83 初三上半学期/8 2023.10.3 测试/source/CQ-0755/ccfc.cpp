
#include<bits/stdc++.h>

using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){ if (ch=='-') f=-1; ch=getchar(); }
	while (isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
} 
char ch[305]; int n;
int work(int l,int r){
	int res=0;
	for (int len=1;len*3+1<=r-l+1;len++){
		bool fl=1;
		for (int i=l,j=1;j<=len;j++,i++)
			if (ch[i]!=ch[i+len]){ fl=0; }
		if (!fl) continue;
		for (int i=l,j=r-len+1,k=1;k<=len;k++,i++,j++)
			if (ch[i]!=ch[j]){ fl=0; }
		if (!fl) continue;
		res++;
	} return res;
}
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for (int l=1;l<=n;l++)
		printf("%d ",work(l,n));//ยาะด 
	return 0;
}
/*

*/
