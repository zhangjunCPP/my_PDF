//the code is from chenjh
#include<cstdio>
#include<cstring>
#define MAXN 100005
using namespace std;
inline int Min(const int x,const int y){return x>y?x:y;}
int n,q;
char s[MAXN][35];
int ls[MAXN];
char t[35];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]),ls[i]=strlen(s[i]);
	scanf("%d",&q);
	while(q--){
		scanf("%s",t);
		int lt=strlen(t);
		int ans=0;
		for(int i=1;i<=n;i++){
			int j,mj=Min(ls[i],lt);
			for(j=0;j<mj&&s[i][j]==t[j];j++);
			ans+=j+1;
			if(j==mj&&ls[i]==lt)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

