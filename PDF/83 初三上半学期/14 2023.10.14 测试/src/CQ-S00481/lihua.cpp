#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define i64 __int128
#define lowbit(i) i&(-i)
const int N = 1e5+5,P = 131;
int n,q,typ,pos[27][50],sum[27][N]; 
int hs[N];
string s[N],t;
int main(){
	freopen("lihua.in","r",stdin);
	freopen("lihua.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;typ = 1;
	for(int i=1;i<=n;i++) cin >> s[i];
	cin >> q;
	for(int i=1;i<=n;i++){
		int siz = s[i].size();
		for(int j=1;j<siz;j++){
			if(s[j]!=s[j-1]) typ = 0; 
		}
	}	
	if(n<=10 && q<=10){
		for(int i=1;i<=q;i++){
			cin >> t;
			int ans = 0;
			for(int j=1;j<=n;j++){
				ans++;
				int ck = (t.size()==s[j].size());
				int lim = min(t.size(),s[j].size());
				for(int k=0;k<lim;k++){
					if(s[j][k]==t[k]) ans++;
					else{
						ck = 0;
						break;
					}
				}
				if(ck) break;
			}
			cout << ans << '\n';
		}
	}else if(typ){
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++) sum[j][i] = sum[j][i-1];
			sum[s[i][0]-'a'][i] += s[i].size();
		}
		for(int i=1;i<=n;i++){
			int siz = s[i].size();
			if(!pos[s[i][0]-'a'][siz]) pos[s[i][0]-'a'][siz] = i;
		}
		for(int i=1;i<=q;i++){
			cin >> t;
			int siz = t.size();
			if(!pos[t[0]-'a'][siz]) cout << n << '\n'; 
			else{
				int j = pos[t[0]-'a'][siz];
				cout << sum[t[0]-'a'][j]+n << '\n'; 
			}
		}
	}
	return 0;
}
//f(i,j,k)表示前i个字符串，
//按照最后一次出现位置离线 
 
