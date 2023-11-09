#include<bits/stdc++.h>
#define ll long long
#define m_p make_pair
using namespace std;
const int N=100000+10;
int n,q;
string s1[N],s2[N];

void solve_10(){
	int ans=0,tad;
	bool flag;
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			ans++;
			flag=1;
			tad=min(s1[j].size(),s2[i].size());
			for(int k=0;k<tad;k++){
				if(s1[j][k]==s2[i][k]) ans++;
				else{
					flag=0;
					break;
				}
			}
			if(flag&&s1[j].size()==s2[i].size()) break;
		}
		printf("%d\n",ans);
	}
}
void solve_20(){
	vector<int> mp[30][35];//第i个字母有j个 
	for(int i=1;i<=n;i++){
		mp[s1[i][0]-'a'][s1[i].size()].push_back(i);
	}
	int tad,ans=0,ans1,len;
	for(int i=1;i<=q;i++){
		ans1=0,ans=0;
		tad=s2[i][0]-'a';
		len=s2[i].size();
		if(mp[tad][len].size()) ans1=mp[tad][len][0];
		else ans1=n;
		for(int j=1;j<30;j++){//字母个数 
			if(j==len&&mp[tad][j].size()){
				ans+=j;
				break;
			}
			for(int k=0;k<mp[tad][j].size();k++){
				if(mp[tad][j][k]<=ans1) ans+=min(j,len);
				else break;
			}
		}
		printf("%d\n",ans1+ans);
	}
}

ll has[N][32];
ll ha[32];
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	scanf("%d",&n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		if(flag){
			for(int j=1;s1[i][j]!='\0';j++){
				if(s1[i][j]!=s1[i][0]){
					flag=0;
					break; 
				}	 
			}
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		cin>>s2[i];	
		if(flag){
			for(int j=1;s2[i][j]!='\0';j++){
				if(s2[i][j]!=s2[i][0]){
					flag=0;
					break; 
				}	 
			}
		}
	}
	
	if(flag){
		solve_20();
		return 0;
	}
	solve_10();
	return 0;
}
