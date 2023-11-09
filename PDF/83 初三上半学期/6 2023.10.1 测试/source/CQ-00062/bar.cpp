#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=54;
int n,m,k;using PII=pair<int,int>;
vector<PII> E[N];
int cnt;
char ch[100001][101];
int vis[N];
vector<int> pos;
void dfs(int v,int s,int w){
	if(v==n){
		cnt++;
		ch[cnt][0]=s/100000,ch[cnt][1]=s/10000%10,ch[cnt][2]=s/1000%10,
		ch[cnt][3]=s/100%10,ch[cnt][4]=s/10%10,ch[cnt][5]=s%10;
		for(int i=0;i<n;i++){
			ch[cnt][6+i*2]=pos[i]/10;
			ch[cnt][6+i*2+1]=pos[i]%10;
		}return;
	}for(auto i:E[v]){
		if(!vis[i.first]){
			vis[i.first]=1;
			pos[w]=i.first;
			dfs(i.first,s+i.second,w+1);
			vis[i.first]=0;
			pos[w]=0;
//			pos.pop_back();
		}
	}
}
bool cmp(char a[101],char b[101]){
	for(int i=0;i<n*2+6;i++)if(a[i]<b[i])return 0;else if(a[i]>b[i])return 1;
	return 0;
}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	n=rd(),m=rd(),k=rd();
//	if("01020304"<"01030400")return 0;
	for(int i=1;i<=m;i++){
		int u=rd(),v=rd(),w=rd();
		E[u].push_back({v,w});
	}
	pos.resize(n+1);vis[1]=1;
	pos[0]=1;
	dfs(1,0,1);
//	stable_sort(ch+1,ch+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	for(int j=i+1;j<=cnt;j++)
	if(cmp(ch[i],ch[j]))swap(ch[i],ch[j]);
/*	for(int k=1;k<=cnt;k++){
		vector<int> path;
//		cout<<ch[k]<<endl;
		for(int i=6;i<n*2+6;i+=2){
			int x=ch[k][i]*10+ch[k][i+1];
			if(x)path.push_back(x);
		}cout<<path.size()<<endl;
		cout<<(char)(ch[k][5]+'0')<<endl;
		for(int i:path)cout<<i<<' ';cout<<endl;
	}*/
	if(cnt<k)puts("-1");
	else{
		vector<int> path;
		for(int i=6;i<n*2+6;i+=2){
			int x=ch[k][i]*10+ch[k][i+1];
			if(x)path.push_back(x);
		}cout<<path.size()<<endl;
		for(int i:path)cout<<i<<' ';
	}
	return 0;
}

