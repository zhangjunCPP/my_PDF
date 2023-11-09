#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct SAM{
	struct hzzdj{
		int son[30],len,father;
	}hz[N*2];
	int tot,last;int cz[N*2];
	vector<int>lt[N*2],E[N*2]; 
	void getnew(int length){
		hz[++tot].len=length;
		hz[tot].father=-1;
		memset(hz[tot].son,0,sizeof(hz[tot].son));
	}
	void init(){
		tot=-1;last=0;
		getnew(0);
	}
	void insert(char ch,int id){
		int cha=ch-'a';
		getnew(hz[last].len+1);
		int p=last,cur=tot;
		lt[cur].push_back(id);
		cz[id]=cha;
		while(p!=-1&&!hz[p].son[cha]){
			hz[p].son[cha]=cur;
			p=hz[p].father;
		}
		if(p==-1){
			hz[cur].father=0;
		}
		else{
			int q=hz[p].son[cha];
			if(hz[q].len==hz[p].len+1){
				hz[cur].father=q;
			}
			else{
				int nq=++tot;
				hz[nq].len=hz[p].len+1;
				memcpy(hz[nq].son,hz[q].son,sizeof(hz[q].son));
				hz[nq].father=hz[q].father;
				hz[q].father=hz[cur].father=nq;
				while(p!=-1&&hz[p].son[cha]==q){
					hz[p].son[cha]=nq;
					p=hz[p].father;
				}
			}
		}
		last=cur;
	}
	int d[N*2],t[N*2];
	void tp(){
		for(int i=0;i<=tot;i++){
			for(int j:E[i]){
				d[j]++;
			}
		} 
		queue<int>q;
		for(int i=0;i<=tot;i++){
			if(!d[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			t[++t[0]]=u;
			for(int i:E[u]){
				d[i]--;
				if(!d[i])q.push(i);
			}
		}
	}
	void dfs(int u){
		for(int v:E[u]){
			dfs(v);
			for(int i:lt[v]){
				lt[u].push_back(i);
			}
		}
//		sort(lt[u].begin(),lt[u].end());
	}
	int mp[N*2],vis[N*2];
	long long ans[N];
	void dfs2(int u,int id){
		if(id*3+1>n)return;
//		cout<<id<<"  "<<u<<" :";
		for(int i=0,ls=lt[u].size();i<ls;i++){
//			cout<<lt[u][i]<<" ";
			mp[lt[u][i]]=i;
			vis[lt[u][i]]=id;
		}
//		cout<<"   "<<hz[u].len; 
//		cout<<endl;
		for(int i=0,ls=lt[u].size();i<ls;i++){
			if(vis[lt[u][i]+id]!=id)continue;
			int y=mp[lt[u][i]+id];
			if(lt[u][i]-id>id&&lt[u][y]-lt[u][i]==id){
				ans[lt[u][y]]++;
//				cout<<id<<" "<<lt[u][i]<<" "<<lt[u][y]<<endl;
			}
		} 
		dfs2(hz[u].son[cz[id+1]],id+1);
	}
	void sol(){
		for(int i=1;i<=tot;i++){
			E[hz[i].father].push_back(i);
		}
		tp();dfs(0);
		int u=0;
		dfs2(hz[u].son[cz[1]],1);
	} 
}sam;
char ch[N];
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	scanf("%s",ch+1);
	int len=1;
	while(ch[len]){len++;}
	len--;n=len;
//	cout<<len<<endl;;
	sam.init();
	for(int i=len;i;i--){
		sam.insert(ch[i],len-i+1);
//		cout<<ch[i];
	}
//	cout<<endl;
	sam.sol();
	for(int i=len;i;i--){
		printf("%lld ",sam.ans[i]);
	}
	return 0;
}

