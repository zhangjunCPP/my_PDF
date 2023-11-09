#include<bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=310;
int k,q,n,len;
char s[N],t[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	k=read();
	scanf("%s",s+1),n=strlen(s+1);
	q=read();
	while(q--){
		int ans=0;
		scanf("%s",t+1),len=strlen(t+1);
		for(int i=1;i<=n-len+1;++i){
			int j=i+len-1,flag=1;
			for(int st=i;st<=j;++st){
				for(int ed=i;ed<=j;++ed){
					if(s[st]!=t[st]&&s[ed]!=t[ed]){
						if(abs(st-ed)>=k){flag=0;break;}
					}
				}
				if(!flag)break;
			}
			if(flag)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
