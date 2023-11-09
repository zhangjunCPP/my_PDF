#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double
	#define ULL unsigned long long
	#define In inline
	#define Re register
	#define f(a,b,i) for(Re int i=a;i<=b;i++)
	#define ff(a,b,i) for(Re int i=a;i<b;i++)
	#define f_(a,b,i) for(Re int i=a;i>=b;i--)
	#define ff_(a,b,i) for(Re int i=a;i>b;i--)
	const int inf=0x3f3f3f3f;
	const int INF=0x7f7f7f7f;
	const LL infll=0x3f3f3f3f3f3f3f3fll;
	const LL INFll=0x7f7f7f7f7f7f7f7fll;
	template<typename T>void read(T &x){
		x=0;
		bool fl=0;
		char ch=getchar();
		while(ch<'0'||'9'<ch){
			if(ch=='-')fl=1;
			ch=getchar();
		}
		while('0'<=ch&&ch<='9'){
			x=(x<<3)+(x<<1)+(ch^48);
			ch=getchar();
		}
		x=fl?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	system("maze.exe < D:\\down\\maze\\ex_maze1.in > maze_ans.txt");
	system("fc D:\\down\\maze\\ex_maze1.ans  maze_ans.txt");
	
	system("maze.exe < D:\\down\\maze\\ex_maze2.in > maze_ans.txt");
	system("fc D:\\down\\maze\\ex_maze2.ans  maze_ans.txt");
	
	system("maze.exe < D:\\down\\maze\\ex_maze3.in > maze_ans.txt");
	system("fc D:\\down\\maze\\ex_maze3.ans  maze_ans.txt");
	
	system("maze.exe < D:\\down\\maze\\ex_maze4.in > maze_ans.txt");
	system("fc D:\\down\\maze\\ex_maze4.ans  maze_ans.txt");
	return 0;
}

