#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
void Freopen(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
int k,q;
char s[MAXN];
int main(){
	Freopen();
	scanf("%d",&k); scanf("%s",s+1);
	int n=strlen(s+1);
	scanf("%d",&q);
	while(q--){
		string p; cin>>p; int len=p.size();
		int ans=0;
		for(int i=1;i+len-1<=n;i++){
			string tmp="";
			for(int j=i;j<=i+len-1;j++) tmp+=s[j];
//			cout<<"tmp:"<<tmp<<endl; 
//			cout<<"p:  "<<p<<endl;
			bool flag=true;
			for(int j=0;j<tmp.size();j++){
				if(!flag) break;
				for(int x=0;x<tmp.size();x++){
					if(tmp[j]==p[j] && tmp[x]==p[x]) continue;
					if(abs(j-x)>=k){
						flag=false;
						break;
					}
				} 
			}
			if(flag) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring

*/
