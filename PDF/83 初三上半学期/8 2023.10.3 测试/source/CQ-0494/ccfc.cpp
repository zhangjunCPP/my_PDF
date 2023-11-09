#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=1e5+10;
int ans[N];
char s[N];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<3*i-2*n-2;++j){
			int len=1,flag=1;
			while(len<=n-i+1){
				int x=j+len-1,y=j+n-i+1+len-1,z=i+len-1;
				if(s[x]!=s[y]||s[x]!=s[z]||s[y]!=s[z]){flag=0;break;}
				++len;
			}
			if(flag)++ans[j];
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
