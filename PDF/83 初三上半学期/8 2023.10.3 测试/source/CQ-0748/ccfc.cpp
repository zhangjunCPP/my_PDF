#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
inline void Freopen(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}
char s[MAXN];
int main(){
	Freopen();
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int k=1;i+k*3<n;k++){
			string s1="",s2="",s3="",s4="";
//			int len=tmp-k*3;
			for(int j=i;j<=i+k-1;j++) s1+=s[j];
			for(int j=i+k;j<=i+k*2-1;j++) s2+=s[j];
			for(int j=i+k*2;j<=n-k;j++) s3+=s[j];
			for(int j=n-k+1;j<=n;j++) s4+=s[j]; 
			if(s1==s2 && s2==s4) ans++;
		}
		printf("%d ",ans);
	}
	return 0;
} 
