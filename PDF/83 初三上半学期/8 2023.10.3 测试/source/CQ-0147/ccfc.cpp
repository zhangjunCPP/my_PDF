#include<bits/stdc++.h>
using namespace std;
#define first fi
#define second se
#define push_back pb
typedef long long ll;
const int N=2e5+10;
void File(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
}
char s[N];
int n,ans[N];
int main(){
	File();
	cin>>(s+1);
	n=strlen(s+1);
	
	for(int i=n;;i--){
		int ff=0;
		for(int l=1,r=l+n-i+n-i+1;r<i-1;l++,r++){
			ff=1;
			int f=0;
			for(int j=l;j<=(l+r)>>1;j++){
				if(s[j]!=s[j+(n-i+1)]||s[j]!=s[i+j-l]){
					f=1;
					break;
				}
			}
			if(f==0){
				ans[l]++;
			}
		}
		if(ff==0) break;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
