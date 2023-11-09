#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	char ch;
	bool sgn=0;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=x*10+ch-48;
	}
	if(sgn){
		x=-x;
	}
	return;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
inline void read(long long &x){
	x=0;
	char ch;
	bool sgn=0;
	while(ch=getchar(),ch<'!');
	if(ch=='-'){
		sgn=1;
	}else{
		x=ch-48;
	}
	while(ch=getchar(),ch>'!'){
		x=x*10+ch-48;
	}
	if(sgn){
		x=-x;
	}
	return;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
long long p,k,n,ans;
vector<pair<int,int > >res;
inline long long qpow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1){
			ans*=x;
		}
		x*=x;
		y>>=1;
	}
	return ans;
}
int main(){
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	read(p);
	read(k);
	n=qpow(p,k);
	if(k==1){
		write(1);
		for(int i=0;i<p;i++){
			write(i);
			putchar(' ');
		}
		return 0;
	}
	if(p==2){
		for(int i=0;i<n;i+=2){
			res.push_back(make_pair(i,i+1));
		}
		long long siz=res.size();
		for(int i=0;i<siz;i++){
			for(int j=i+1;j<siz;j++){
				res.push_back(make_pair(res[i].first,res[j].first));
				res.push_back(make_pair(res[i].second,res[j].second));
				res.push_back(make_pair(res[i].first,res[j].second));
				res.push_back(make_pair(res[i].second,res[j].first));
			}
		}
		cout<<res.size()<<endl;
//		for(int i=0;i<res.size();i++){
//			write(res[i].first);
//			putchar(' ');
//			write(res[i].second);
//			putchar('\n');
//		}
		return 0;
	}
	return 0;
}

