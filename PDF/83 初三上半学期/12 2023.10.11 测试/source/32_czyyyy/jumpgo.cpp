#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int n,cnt;
char s[505];
bitset<1<<20> vis;
int key(char*ch){
	int x=0;
	for(int i=1;i<=n;i++)x=x*2+ch[i]-'0';
	return x;
}
char ch[505];
void dfs(){
	if(vis[key(ch)])return;
//	for(int i=1;i<=n;i++)cout<<ch[i];
//	cout<<endl;
	vis[key(ch)]=1;cnt++;
	for(int i=1;i<n-1;i++){
		if(ch[i]=='1'&&ch[i+1]=='1'&&ch[i+2]=='0'){
			swap(ch[i],ch[i+2]);dfs();swap(ch[i],ch[i+2]); 
		}if(ch[i]=='0'&&ch[i+1]=='1'&&ch[i+2]=='1'){
			swap(ch[i],ch[i+2]);dfs();swap(ch[i],ch[i+2]);
		}
	}
}
void get(int x){
	if(x==n+1){vis.reset();dfs();return;}
	if(s[x]=='?'){ch[x]='1';get(x+1);ch[x]='0';get(x+1);}else ch[x]=s[x],get(x+1);
}
int main(){
	freopen("jumpgo.in","r",stdin);
	freopen("jumpgo.out","w",stdout);
	n=rd();scanf("%s",s+1);
	get(1);
	printf("%d",cnt);
	return 0;
}
/*
3   4   5   6   7   8    9    10
10  26  70  192 534 1500 4246 12092
2   6   28  52  150 432  1246 
10
??????????
*/
