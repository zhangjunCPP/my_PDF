#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
inline void Freopen(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
}
int n,q;
string s[MAXN];
int main(){
	Freopen();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>s[i];
	scanf("%d",&q); int ans=0;
	if(n<=30000 && q<=30000){
		while(q--){
			string com; cin>>com;
			int ans=0;
			for(int i=1;i<=n;i++){
				ans++; bool flag=true;
				for(int j=0;j<com.size();j++){
					if(com[j]!=s[i][j]){
						ans+=j; 
						flag=false; 
						break;
					}
				}
				if(flag && com.size()==s[i].size()){ans+=com.size(); break;}
				if(flag) ans+=com.size();
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	while(q--){
		string com; cin>>com;
		int ans=0;
		for(int i=1;i<=n;i++){
			ans++;
			if(s[i][0]==com[0] && s[i].size()==com.size()){
				ans+=com.size();
				break;
			}
			if(s[i][0]!=com[0]) continue;
			if(s[i][0]==com[0])
				ans+=min((int)s[i].size(),(int)com.size());
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
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

1
aaaa
1
bb
*/
