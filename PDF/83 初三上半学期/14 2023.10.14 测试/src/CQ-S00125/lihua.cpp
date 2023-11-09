#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,w=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*w; 
}
inline void wr(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wr(x/10);
	putchar(x%10+'0');
}
inline void FRE(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
}
const int N=1e5+5;
int n,m,ans;
string a[N],s;
int main(){
	FRE();
	n=rd();
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	m=rd();
	while(m--){
		cin>>s;
		ans=0;
		for(int i=1;i<=n;++i){
			ans++;
			int s1=a[i].size(),s2=s.size();
			int j;
			for(j=0;j<s1&&j<s2;++j){
				if(a[i][j]!=s[j])break;
				ans++;
			}
			if(j==s1&&j==s2)break;
		}
		wr(ans);putchar('\n');
	}
	return 0;
}
