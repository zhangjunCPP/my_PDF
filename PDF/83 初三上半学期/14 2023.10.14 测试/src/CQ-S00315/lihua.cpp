#include<bits/stdc++.h>
//const int QWQ=1e5+5;
using namespace std;
char ch[11][33],a[33]; int ls[11]; int n,q,res;
//pair<int,int> t[QWQ][26]; 
//char ch[31]; int tot;
//void insert(){
//	int now=0,l=strlen(ch+1);
//	for (int i=1;i<=l;i++){
//		int p=ch[i]-'a';
//		if (!t[now][p].first) t[now][p].first=++tot;
//		t[now][p].second++;
//		now=t[now][p].first;
//	} 
//} 
//void find(){
//	int now=0,l=strlen(ch+1),i=1;
//	for (;i<=l;i++){
//		int p=ch[i]-'a';
//		if (!t[now][p].first) return ;
//		res+=t[now][p].second;
//		now=t[now][p].first;
//	} 
//}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	if (n<=10){
		for (int i=1;i<=n;i++){
			scanf("%s",ch[i]+1);
			ls[i]=strlen(ch[i]+1);
		}
		scanf("%d",&q);
		while (q--){
			scanf("%s",a+1);
			res=0; int l=strlen(a+1);
			for (int i=1,j;i<=n;i++){
				res++;
				for (j=1;j<=l;j++)
					if (a[j]==ch[i][j]) res++;
					else break;
				if (j==l+1&&ls[i]==l) break;
			}
			printf("%d\n",res);
		}
	}
//	else{
//		for (int i=1;i<=n;i++){
//			scanf("%s",ch+1);
//			mp[ch]=1,insert();
//		} scanf("%d",&q);
//		while (q--){
//			scanf("%s",ch+1);
//			
//			res=n; find();
//			printf("%d\n",res);
//		}
//	}
	return 0;
}
