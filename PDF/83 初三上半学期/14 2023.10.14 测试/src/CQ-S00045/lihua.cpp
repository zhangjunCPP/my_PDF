#include<bits/stdc++.h>
const int N=1e5+1,L=31;
int n,q,len[N];
char s[N][L],t[L];
namespace sub1{
	bool check(){
		for(int i=1;i<=n;i++)
			for(int j=2;j<=len[i];j++){
				if(s[i][j]!=s[i][1]) return 0;
			}
		return 1;
	}
	void work(){
		scanf("%d",&q);
		while(q--){
			scanf("%s",t+1);
			int ans=0,len=strlen(t+1);
			for(int i=1;i<=n;i++){
				ans++;
				if(t[1]==s[i][1]){
					ans+=std::min(len,::len[i]);
					if(len==::len[i]) break;
				}
			}
			printf("%d\n",ans);
		}
	}
}
namespace sub2{
	void work(){
		scanf("%d",&q);
		while(q--){
			scanf("%s",t+1);
			int ans=0,len=strlen(t+1);
			for(int i=1;i<=n;i++){
				ans++;
				for(int j=1;j<=std::min(len,::len[i]);j++){
					if(s[i][j]==t[j]) ans++;
					else{
						goto endd;
						break;
					}
				}
				if(len==::len[i]) break;
				endd:;
			}
			printf("%d\n",ans);
		}
	}
}
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
	if(sub1::check()) sub1::work();
	else sub2::work();
	return 0;
}
/*
5
jiarandaxiaojie
jiarenmensheidonga
jiangshuaisanjun
beimingningxiao
fenbenglixi
4
jianghua
jiaruo
beiguan
feng

8
majmunica
majmun
majka
malina
malinska
malo
maleni
malesnica
3
krampus
malnar
majmun

5
aaa
bbbb
cccc
aaaa
aaaaa
1
aaaaa
*/

