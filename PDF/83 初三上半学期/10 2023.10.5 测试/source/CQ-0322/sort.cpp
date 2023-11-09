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
long long n,ans,a[1000050];
queue<long long >q;
void Sol(long long l,long long r){
//	cout<<l<<' '<<r<<endl;
//	system("pause");
	if(l>=r){
		return;
	}
	ans+=r-l+1;
//	cout<<ans<<endl;
	long long pos=0,num=0,mid=((l+r)>>1)-l+1;
//	cout<<mid<<endl;
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
		if(l<=a[i]&&a[i]<=r){
			num++;
			if(num==mid){
				pos=a[i];
				break;
			}
		}
	}
//	cout<<endl;
//	cout<<pos<<endl;
	Sol(l,pos-1);
	Sol(pos+1,r);
	return;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	read(n);
	bool is_up=1;
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=i){
			is_up=0;
		}
	}
	if(is_up){
		q.push(n);
		long long ans=0;
		while(q.empty()==0){
			long long x=q.front();
			q.pop();
			ans+=x;
			long long mid=(x+1)/2;
//			cout<<x<<' '<<mid<<endl;
			if(mid-1>=2){
				q.push(mid-1);
			}
			if(x-mid>=2){
				q.push(x-mid);
			}
		}
		write(ans);
		return 0;
	}
//	return 0;
	Sol(1,n);
	write(ans);
	return 0;
}

