#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
struct ball{
	int l,r,c;
}e[1005];
bool boo[1005];
int n,tree1[1005],tree2[1005],ans;
void update(int x,int y,int * tree){
	while (x <= n) tree[x] += y,x += lowbit(x);
}
int find(int x,int * tree){
	int num = 0;
	while (x) num += tree[x],x -= lowbit(x);
	return num;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//*
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	//*/ 
	cin >> n;
	for (register int i = 1;i <= n;i++) update(i,1,tree1),cin >> e[i].l >> e[i].r >> e[i].c,update(e[i].l,e[i].c,tree2),update(e[i].r+1,-e[i].c,tree2);
	for (register int i = 1;i <= n;i++){
		int maxID = 0,maxx = -0x7f7f7f7f;
		for (register int j = 1;j <= n;j++){
			if (boo[j]) continue;
			int t = (find(e[j].r,tree1)-find(e[j].l-1,tree1))*e[i].c-find(j,tree2);
			//cout << j << ":" << t << " ";
			if (maxx < t) maxx = t,maxID = j;
		}
		//cout << "\n";
		boo[maxID] = 1;
		update(maxID,-1,tree1),update(e[maxID].l,-e[maxID].c,tree2),update(e[maxID].r+1,e[maxID].c,tree2);
		ans += (find(e[maxID].r,tree1)-find(e[maxID].l-1,tree1))*e[maxID].c;
	}
	cout << ans;
	return 0;
}
