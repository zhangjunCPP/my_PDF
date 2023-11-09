#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
map<int,int> q;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	srand(time(0));
	int n=10,mod=1e9;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		int val=rand()%mod+1;
		cout<<val<<" ";
	}	
	return 0;
}
