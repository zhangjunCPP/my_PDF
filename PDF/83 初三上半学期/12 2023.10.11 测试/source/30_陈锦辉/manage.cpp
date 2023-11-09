//the code is from chenjh
#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define MAXN 500005
using namespace std;
typedef pair<int,int> PII;
int n,m;
int a[MAXN],b[MAXN];//访问顺序，最后一次访问时间。 
queue<PII> Q;
void read(int& x){
	x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+(ch^'0');
}
void write(int x){
	static short sta[10];
	int p=0;
	for(;x;x/=10)sta[++p]=x%10;
	while(p)putchar(sta[p--]|'0');
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
//	scanf("%d%d",&n,&m);
	read(n),read(m);
	int d=0;
	for(int i=1;i<=m;i++){
//		scanf("%d",&a[i]);
		read(a[i]);
		if(!b[a[i]]) b[a[i]]=1,++d;
	}
	for(int k=1;k<=n;k++){
		int sz=0,ans=0;
		while(!Q.empty()) Q.pop();
		memset(b,0,sizeof(int)*(n+1));
		for(int i=1;i<=m;i++){
			if(b[a[i]]){Q.emplace(b[a[i]]=i,a[i]);continue;}
			for(PII u;!Q.empty() && sz>=k;){
				u=Q.front();Q.pop();
				if(u.first==b[u.second])b[u.second]=0,--sz;
			}
			Q.emplace(b[a[i]]=i,a[i]);
			++sz,++ans;
		}
//		printf("%d ",ans);
		write(ans),putchar(' ');
		if(ans==d){
			for(++k;k<=n;++k) write(d),putchar(' ');//printf("%d ",d);
			return 0;
		}
	}
	return 0;
}

