/*
��ͬ����Ծ�õ�����ͬ���汻�����ǲ�ͬ�ġ�
���Թؼ�����һ�������������ٴΡ�
����������������1������Ծ�����嶯һ�������µ����ڶ�����
һ�Կ���һ���ߣ�������ͼ����ܡ�
����Ƚ���֣�Ӧ���ǲ�������������������������
������Ϊ�� dp����Ϊû�кõ������仮�֣�Ҳû��ʲô�ر�����ơ�
�ǿ��ܻ�������Ĺ����⡣
�뷨�Ǹ� 1 �ĸ�����أ���Ϊ�о��κη��������Թ�Լ���ճ������� 1���ٳ�ȥ��
Ȼ���Լ����������������������ʶ��˵��޼࿼Ա�ס���
Ҳ���ǣ�ɢ��� 1 ��һ���ܴա�
�����Ҿ��������� dp��

*/
#include<bits/stdc++.h>
#define _fre_(file,in,out) (in&&(std::freopen(file".in","r",stdin))),(out&&(std::freopen(file".out","w",stdout)))
namespace IO{
	template<typename _Tp>
	void read(_Tp &&x){
		x=0;bool sign=false;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') sign=true;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+(sign?-(ch&15):(ch&15));
	}
	template<typename _Tp>
	void uwrite(_Tp x){
		if(x>9) uwrite(x/10);
		putchar((x%10)|48);
	}
	template<typename _Tp>
	void write(_Tp x){(x<0&&(putchar('-'),x=-x)),uwrite(x);}
	void write(char ch){putchar(ch);}
}
template<typename ...Args>
void read(Args &&...args){(void)std::initializer_list<int>{(IO::read(args),0)...};}
template<typename ...Args>
void write(Args &&...args){(void)std::initializer_list<int>{(IO::write(args),0)...};}
namespace MAIN{
	constexpr int N=505,mod=1e9+7;
	int n;
	char s[N];
	namespace solve1{
		std::set<std::basic_string<int>> S;
		std::basic_string<int> tmp;
		int ans;
		void dfs(int p){
			if(S.find(tmp)!=S.end()) return;
			S.emplace(tmp);
			if(p==n+1) return;
			for(int i=2;i<n;++i){
				if(tmp[i]&&tmp[i-1]!=tmp[i+1]){
					std::swap(tmp[i-1],tmp[i+1]);
					dfs(p+1);
					std::swap(tmp[i-1],tmp[i+1]);
				}
			}
		}
		void predfs(int p){
			if(p==n+1){
				for(int i=1;i<=n;++i) tmp[i]=s[i]&15;
				S.clear(),dfs(1),ans+=S.size();
				return;
			}
			if(s[p]!='?') return predfs(p+1);
			else s[p]='0',predfs(p+1),s[p]='1',predfs(p+1),s[p]='?';
		}
		void solve_main(){tmp.resize(n+1),predfs(1),std::printf("%d",ans);}
	}
	namespace solve2{
		void solve_main(){}
	}
	namespace solve3{
		void solve_main(){}
	}
	void _main_(){
		std::scanf("%d%s",&n,s+1);
		return solve1::solve_main();
	}
}
signed main(){
	_fre_("jumpgo",1,1);
	return MAIN::_main_(),0;
}
