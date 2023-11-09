#include<bits/stdc++.h>
using namespace std;
char s[229028];
map<pair<int,int>,bool>H;
inline void quitf(int sit,const char out[],int x=0)
{
	if(sit==2)printf("JF ");
	else if(sit)printf("WA ");
	else printf("AC ");
	printf("%s",out);
	if(sit==1)printf("ans=%d",x);
	exit(0);
}
const int _jf=2,_wa=1,_ac=0;
ifstream fin;
ofstream fout;
int main()
{
	fin.open("src.out",fstream::in);
	fin>>s;
	fin.close();
	int n=strlen(s);
	if(n>20)quitf(_wa,"Answer is too long.");
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		int pos=0,base=1,num=0;
		for(int j=0;j<n;j++)if((i>>j)&1)pos+=(s[j]-'0')*base,base<<=1,num++;
		if(!H[make_pair(pos,num)])ans++,H[make_pair(pos,num)]=true;
	}
	fin.open("data.in",fstream::in);
	int a,b;
	fin>>a>>b;
	fin.close();
	if(ans!=a*b-1)quitf(_wa,"Wrong ",ans);
	else quitf(_ac,"Correct");
	return 0;
}
