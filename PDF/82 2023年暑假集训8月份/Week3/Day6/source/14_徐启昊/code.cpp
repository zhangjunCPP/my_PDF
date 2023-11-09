#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<iterator>
#include<vector>
#include<stack>
#include<map>
#define Genshin_Impact_starts ios::sync_with_stdio(false)
#define int long long
#define F first
#define S second
#define eps 1e-6
#define RE register
#define IN inline
#define For(i,s,t) for(register int i=s;i<=t;i++)
#define rFor(i,s,t) for(register int i=s;i>=t;i--)
#define eFor(i,u) for(register int i=head[u];i;i=nxt[i])
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void swap(int &a,int &b){a=a^b,b=a^b,a=a^b;}
void Freopen(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
}
const int N=1e6+100,inf=1e9+10;
int a,b,ab;
signed main(){
	Freopen();
    Genshin_Impact_starts;
    cin.tie(0),cout.tie(0);
	cin>>a>>b;
	ab=a*b-1;
	if(ab<=200000){
		For(i,1,ab)cout<<1;
		return 0;
	}
	else if(ab<=300000){
		For(x,1,200000){
			if((ab-x)%(x+1)==0){
				int y=(ab-x)/(x+1);
				For(i,1,y)cout<<0;
				For(i,1,x)cout<<1;
				break;
			}
		}
	}
}
/*
我感觉我就是一个脑残
T1从来都没做出来过

ffffff  u       u    cccccc  k    kk
f       u       u   c        k  kk
ffffff  u       u  c         kk
f	    u       u  c         kkk
f        u     u    c        k  k 
f         uuuuu      cccccc  k    k
*/
