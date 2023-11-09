//上界:p^k-1(1+p+p^2+...p^k-1)
//考虑把数拆分成p进制.如果对每一位我都能匹配前面的位和他相等且这一位与他不等的就好了.
//然后考虑分治成p个组
//现在考虑怎么解决下面问题:
/*
0 1 2 3 4 ... p-1
0 1 2 3 4 ... p-1
...(p组)
将所有不在一行一列的配对
好像函数(x,(kx+b)%p)(x=0...p-1)合适?
看一下:在kx+b这个组里的对是((x1,kx1+b),(x2,kx2+b)),不可能有重!,两点确定一条一次函数!
那这个会怎么样:(x,(kx+b)%p^k)(x=0...p-1)
也无重!(x1-x2)%p!=0 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int p,k,n=1;
	cin>>p>>k;
	for(int i=1;i<=k;i++)n*=p;
	cout<<n*(n-1)/p/(p-1)<<endl;
	for(int i=0,low=1;i<k;i++,low*=p)
	for(int sm=0,high=n/low/p;sm<low;sm++)
	for(int k=0;k<high;k++)
	for(int b=0;b<high;b++,puts(""))
	for(int x=0;x<p;x++)printf("%d ",sm+low*x+low*p*((k*x+b)%high));
	return 0;
}
