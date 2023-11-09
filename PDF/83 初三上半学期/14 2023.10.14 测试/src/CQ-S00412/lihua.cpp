#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=1e5+5;
int n;
char s[N][32];
int ln[N];
int cnt[32][26];
int zai[32][26];
struct ask{
	int id,len,z,l;
}p[N];int ans[N];
void solve(){
	memset(zai,127,sizeof zai);
	for(int i=1;i<=n;i++){
		int x=strlen(s[i]+1);ln[i]=x;
		for(int j=1;j<=x;j++)s[i][j]-='a';
		zai[x][s[i][1]]=min(zai[x][s[i][1]],i);
	}
	int q=rd();for(int i=1;i<=q;i++){
		char ch[32];scanf("%s",ch+1);
		int len=strlen(ch+1),r;
		r=min(zai[len][ch[1]-'a'],n);
		p[i]={i,len,r,ch[1]-'a'};
	}
	sort(p+1,p+1+q,[](ask a,ask b){return a.z<b.z;});
	int now=1;
	for(int i=1;i<=n;i++){
		int x=ln[i];
		cnt[x][s[i][1]]++;
		while(now<=n&&p[now].z==i){
			ans[p[now].id]=p[now].z;
			for(int j=1;j<=p[now].len;j++)ans[p[now].id]+=cnt[j][p[now].l]*j;
			for(int j=p[now].len+1;j<=30;j++)ans[p[now].id]+=cnt[j][p[now].l]*p[now].len;
			now++;
		}
	}for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	n=rd();int fl=1;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=2;s[i][j];j++)if(s[i][j]!=s[i][1]){
			fl=0;break;
		}
	}
	if(fl)return solve(),0;
	int q=rd();
	while(q--){
		char ch[32];
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt++;
			int f=0;
			for(int j=1;s[i][j]&&ch[j];j++){
				if(ch[j]==s[i][j]){
					cnt++;
					if(j==len&&len==strlen(s[i]+1)){
						f=1;break;
					} 
				}
				else{
					break;
				}
			}if(f)break;
		}cout<<cnt<<endl; 
	} 
	return 0;
}
/*
10
aaaaa
bbbbbb
ccccccc
aaaaaa
cccccccc
aaa
bbbbb
aaaa
bbbbb
cccc
5
aaaaa
cccccc
bbbb
ccc
aaaaaa
*/
