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
long long n;
char s[1000050];
struct Hash_table{
	unsigned long long Base_1,base_1[1000050],Base_2,base_2[1000050],S_1[1000050],S_2[1000050];
	inline void Initialize(){
		Base_1=127;
		Base_2=29;
		base_1[0]=base_2[0]=1;
		for(int i=1;i<=n;i++){
			base_1[i]=base_1[i-1]*Base_1;
			base_2[i]=base_2[i-1]*Base_2;
		}
		for(int i=1;i<=n;i++){
			S_1[i]=S_1[i-1]*Base_1+s[i]-'a';
			S_2[i]=S_2[i-1]*Base_2+s[i]-'a';
		}
		return;
	}
	inline long long Get_key_1(long long l,long long r){
		return S_1[r]-S_1[l-1]*base_1[r-l+1];
	}
	inline long long Get_key_2(long long l,long long r){
		return S_2[r]-S_2[l-1]*base_2[r-l+1];
	}
	inline bool judge(long long l_1,long long r_1,long long l_2,long long r_2){
		return (Get_key_1(l_1,r_1)==Get_key_1(l_2,r_2))&&(Get_key_2(l_1,r_1)==Get_key_2(l_2,r_2));
	}
}Hash;
int main(){
	freopen("ccfc.in","r",stdin);
	freopen("ccfc.out","w",stdout);
	char ch;
	while(ch=getchar(),ch<'!');
	s[++n]=ch;
	while(ch=getchar(),ch>'!'){
		s[++n]=ch;
	}
	Hash.Initialize();
	for(int i=1;i<=n;i++){
		long long res=0;
		for(int j=1;j<=n;j++){
			if(n-i+1<=3*j){
				break;
			}
			if(Hash.judge(i,i+j-1,i+j,i+2*j-1)&&Hash.judge(i,i+j-1,n-j+1,n)){
				res++;
			}
		}
		write(res);
		putchar(' ');
	}
	return 0;
}

