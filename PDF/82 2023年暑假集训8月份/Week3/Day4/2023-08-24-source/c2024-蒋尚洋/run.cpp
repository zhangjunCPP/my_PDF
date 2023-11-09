#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll C,S,hf;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	auto rep=[](char c,int t){for(;t--;putchar(c));};
	auto trep=[&](char tr,int t){if(t)putchar(tr),rep('2',t-1);};
	cin>>C>>S;hf=C>>1;
	ll a=hf+1>>1,b=hf>>1,mxS=a*b;
	if((C&1)||S>mxS||S<hf-1)return cout<<"Impossible",0;
	if(mxS==S)return rep('2',a),trep('3',b),trep('3',a),trep('3',b),0;
	//挖角,C不变S变小,使用一列一列的挖法
	ll dif=mxS-S,x=dif/(a-1),y=dif%(a-1);
	rep('2',a);
	trep('3',b-x-(y>0));
	if(y)trep('3',y),putchar('1');
	trep('3',a-1-y);
	trep('1',x);
	putchar(x?'3':'2');
	trep('3',b);
	return 0;
}
