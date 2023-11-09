#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e5+5;
int n;
int a[N];
bool ins[N];
void output(){
	cout<<n<<'\n';
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return ;
}
int main(){
//	freopen("sort.in","r",stdin);
	freopen("sort.in","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	n=200000;
	for(int i=1;i<=n;i++){
		int w=rand()%20+max(0,i-10);
		while(ins[w]) w=rand()%20+max(0,i-10);
		ins[w]=true;
		a[i]=w;
	}
	output();
	return 0;
}
/*

*/
