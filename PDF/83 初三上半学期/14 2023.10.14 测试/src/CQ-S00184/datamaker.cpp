#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=0+5;

int main(){
//	freopen("chameleon.in","r",stdin);
	freopen("chameleon.in","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cout<<100000<<' '<<1000000<<' '<<40<<'\n';
	int ct=0;
	for(int i=1;i<=100000;i++){
		int tw=rand()%2;
		char sid;
		if(tw==0&&ct<=30) ct++,sid='D';
		else sid='L';
		cout<<rand()%1000000<<' '<<rand()%(40+1)<<' '<<sid<<'\n';
	}
	return 0;
}
