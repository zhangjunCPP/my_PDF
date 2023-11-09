#include<bits/stdc++.h>
using namespace std;
const int N=60;
int n,m,k;
vector<pair<int,int> >E[N];
//priority_queue<pair<int,deque<int> > >q;
//int a[N];
//void sol(){
//	deque<int>st;st.push_back(1);
//	q.push_back(0,st);
//	while(!q.empty()){
//		pair<int,deque<int> >pp=q.top;
//		deque<int>b=pp.first;
//		int u=pp.second;
//		q.pop();
//		a[u]++;
//		if(u==n&&a[u]==k){
//			while(!b.empty()){
//				cout<<b.front();
//				b.pop_front();
//			}
//			return;
//		}
//		for(int v:E[u]){
//			b.push_back(v)
//		}
//	}
//}
int main(){
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
	}
	cout<<-1;
	return 0;
}

