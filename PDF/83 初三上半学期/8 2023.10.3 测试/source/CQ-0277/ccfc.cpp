//���Ȳ����ܰ�A����һ��
//��reverseһ��,Ȼ����ABAA
//ÿ����׺��ǰ׺������һ�������ǰ׺
//AA���ͳ��? 
#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
char s[100010];
int n;
ull h[100010],pn[100010];
auto code=[](int l,int r){return h[r]-h[l-1]*pn[r-l+1];};
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	pn[0]=1;
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)pn[i]=pn[i-1]*131,h[i]=h[i-1]*131+s[i]-'a'+1;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i+1;j<=n;j++){
			int len=j-i;
			if(j+len-1<n-len&&code(i,j-1)==code(j,j+len-1)&&code(i,j-1)==code(n-len+1,n))ans++;
		}
		printf("%d ",ans);
	}
	return 0;
}
