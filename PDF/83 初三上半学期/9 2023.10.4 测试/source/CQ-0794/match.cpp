#include<bits/stdc++.h>
using namespace std;
int K; 
const int maxn=2e5+5;
char s[maxn],t[maxn];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout); 
	scanf("%d",&K);
	scanf("%s",s+1);
	int n=strlen(s+1);
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",t+1);
		int m=strlen(t+1);
		int ans=0;
		for(int i=1;i+m-1<=n;i++){
			int lst=0;
			for(int j=i,k=1;j<=i+m-1;j++,k++){
				if(s[j]!=t[k]){
					lst=j;
					break;
				}
			}
			int pre=0;
			for(int j=i+m-1,k=m;j>=i;j--,k--){
				if(s[j]!=t[k]){
					pre=j;
					break;
				}
			}
			if(pre-lst<K) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
����һ������ƥ�䡣
ö����˵㡣
�񰡣�������������Ĳ��ԡ�
��ֱ�ӳͷ��ң���Ҫ����ô�ӱȵĿ�������ĥ�Ұ��� 
Ȼ�����жϰɡ� 
���Ѿ����ˡ� 
*/
