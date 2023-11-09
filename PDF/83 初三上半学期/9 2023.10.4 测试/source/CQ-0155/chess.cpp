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
long long p,k,ans;
bool Line[2050],vis[2050][2050];
vector<pair<int,int > >res;
vector<int > rec[100050];
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
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(p);
	read(k);
	long long n=qpow(p,k);
	if(k==1){
		write(1);
		putchar('\n');
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
		for(int i=0;i<res.size();i++){
			write(res[i].first);
			putchar(' ');
			write(res[i].second);
			putchar('\n');
		}
		return 0;
	}
	ans=1;
	long long times=p;
	for(int i=2;i<=k;i++){
		ans*=p*p;
		ans+=times;
		times*=p;
	}
	write(ans);
	putchar('\n');
	times=0;
	for(int i=0;i<n;i++){
		write(i);
		times++;
		if(times==p){
			ans--;
			putchar('\n');
			times=0;
		}else{
			putchar(' ');
		}
	}
	for(int i=0;i<p;i++){
		for(int j=i;j<n;j+=p){
			write(j);
			times++;
			if(times==p){
				ans--;
				putchar('\n');
				times=0;
			}else{
				putchar(' ');
			}
		}
	}
	long long del=1;
	for(int i=0;i<p;i++){
		for(int l=1;l<p;l++){
			long long r=l;
			write(i);
			putchar(' ');
			for(int j=0;j<p;j++){
				if(i==j){
					continue;
				}
				write(j+r*p);
				r+=del;
				if(r>=p){
					r-=(p-1);
				}
				putchar(' ');
			}
			putchar('\n');
		}
		del++;
		if(del==p-1){
			del=1;
		}
	}
	return 0;
}

