//the code is from chenjh
#include<cstdio>
#define MAXN 300003
using namespace std;
using ci=const int;
int n;
struct Edge{
	int u,v;
	Edge(int _u=0,int _v=0):u(_u),v(_v){}
}E[MAXN];
int fa[MAXN],sz[MAXN];
inline int find(ci x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){x=find(x),y=find(y);if(x!=y)fa[x]=y;}
inline int mymax(int&x,ci y){return x=x>y?x:y;}
void solve_st1(){
	for(int i=1;i<=n;i++){
		int a1=0,a2=n+1;
		for(int j=1;j<=n;j++)if(i!=j){
			for(int i=1;i<=n;i++) fa[i]=i,sz[i]=0;
			int w=0;
			for(int k=1;k<n;k++)if(E[k].u!=i&&E[k].u!=j&&E[k].v!=i&&E[k].v!=j)merge(E[k].u,E[k].v);
			for(int k=1;k<=n;k++)if(k!=i&&k!=j)mymax(w,++sz[find(k)]);
			if(w<a2) a1=j,a2=w;
		}
		printf("%d\n",a1);
	}
}
void solve_st3(){
	for(int i=1,mi=n>>1;i<=mi;i++)printf("%d\n",(n+i+1)>>1);
	for(int i=(n>>1)+1;i<=n;i++)printf("%d\n",i>>1);
}
void solve_st4(){
	puts("2");
	for(int i=2;i<=n;i++) puts("1");
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	scanf("%d",&n);
	bool st3=1,st4=1;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),st3&=(u==i&&v==i+1),st4&=(u==1&&v==i+1),E[i]=Edge(u,v);
	if(st4) solve_st4();
	else if(st3) solve_st3();
	else solve_st1();
	return 0;
}
/*









                                                                                                        .
                                                                                                         .. `....
                                                                                              . ..]/],OOOOO@OOO@@OOOOO` ^. .
                                                                                             ..]OOOO@OO@OOO@OOOOOOOOOO@@OOO,.]]`  ...  .
                                                                              .     .`...\]O/OOO@OOOOO@@OOO@OOOOOOOOOOOOO\OO@OOOO/\/,\..
                                                                              ,/OOOOOOOOOOO@OOOOO@@@@@O@OO@@@@OOO@@@@@@@@OO@@O@OOOOOOOOOO\]`.
                                                                      .     . \OOOOOO@O@O@O@@@@@@@@@O@@O@@@@@@@@@@O@@@@@@@@@@@@@@O@@@@@O@OOOOO\`
                                                             .          . ...OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@OOOOO^.
                                                               .    .,..` =OO@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@O@@@@@@@@OO@O`..
                                                                 ..`,/OOOO@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOO\`
                                                           .`.  ..=OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO\..,..
                                                            .`]=OOOO@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@OOO]....
                                                      ....`\OOO@OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@O@OOO`
                                                      ./O@@@@OOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@O`
                                            .   ,.,,]OO@@OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@\.
                                             .]./\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@OO`
                                           , \OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO].
                                        ... \OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@O/`..
                                        ..,/@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@OOO^`].
                                      ..\`,OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@OO\o...
                                      ,,OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@O@OO]``
                                        [OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO/[`.
                                        \`]O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO`[.
                                      .,[OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\OO,,.,
                                     .=OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@OO[...
                                     .\O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@[`.
                                    .,=\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO@O@@@@@@@@@@OOOOOOO@O@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OO[`]...
                                   .,\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@@@@@@@@OOOOOOOO@@O@O@@OOOOOOOOOO@OOO@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO[`
                                    =O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@@@OO@@O@O@O@O@OO@@O@@@OOOOOOOOOOOOOO@OOOOOOOOOOOOO@OO@OO@@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\/``..
                                    ,[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO@@@OOOOOOOOOOOOOOO@OO@@OOOOOOOOOOOOO@OOOOOOOOOOOOOOOOO@OOOOO@@O@@OOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O\...
                                    ./@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOO@OOOOOOOOOOOOOOOOOOO@@OOOOOOOOOOOOOO@OOOOOOOOOOOOOOOO@OOOOOOOOO@OOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\^.`  .
                                    ,O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOOOOOOOOOOOOoOOOOOOOOOOOOOOOOOO@OOOOOO@@@O@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O/...
                                   .[O@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooOoooOOOOOOoOOoo\OooOoooOOOOOOOOOOOOOOOOOOOOOO@@OOO@O@O@@@@@@@@@@@@@@@@@@@@@@@@O/..
                                    ./@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOO\oo^/\OOo\/o^\o\ooOOOooooooo/==/oooooOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOO@@O@@@@@@@@@@@@@@@@@@@\]],`
                                     /O@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo[`Oooo/o,^=,[oooooOO,oooooo=oo`\ooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OO@@@@@@@@@@@@@@@@@O[\``
                                     [\@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOooo\\*\^\^**``oo*o^o\\oo,/,`\/o^^\\/\\ooooooOOOOOOOOOoOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@O\...
                                    .=O@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOoOOoooo]o/,,/``[*o^`[\***\,/o/``*,*^,\\=[o=oo\oooo\OOOOOooooOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@OO\`
                                     [\@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOooOOooo,\]^[*\\`*[,\`/][,o]^\[*`[,*`***=*[*`=*``**,\[ooOooooooooOOOOOOOOOooooooOOOOO@@@@@@@@@@@@@@@@O/.
                                      =@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOoOOoOoooOo\o/\`\*,,**,``]**\*^\,^^,,***=*`********``,oooo[/\oo/oooooooooooooooooooooOOOOOO@@@@@@@@@@@@@@@O[`.
                                      =@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOoooooo\o/o\o/]``^*,[,`,`,=*^,,,**``=`]****``^^=****`],`*`^\\oooo^/\o/[ooooooooo\/oooOOOOO@@@@@@@@@@@@@@@O`
                                     ./@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOoO/\o/o/^\][``,,/^*`````*`**`,==^*]`**^*^`=o=**`*`**`*=*,,^,oooo/\/ooo]/ooooooooooooOOOO@@@@@@@@@@@@@OO`
                                      ,@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOo/oo\\\o[\oo\`^^*=/`^]**==^^********=*=,^`,*`^o,[`**,*,*\[[=o\/\]oo=oo/o/ooo/ooooOOO@O@@@@@@@@@@@@^
                                      .O@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOoooooooo=o/oo=/[\,^\`^,=^*`**`***]=**o\^o*,*]**`=,`]*\]]/o]o\[o/oo\,*\,\/oooOOOO@@@@@@@@@@@@O`
                                      ,OO@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOO@@@OOOOOOOOOOOOOOOOOOOooooo\oo\ooo[^,\o*[`o*]]==*=/oo/oo/ooo\/oo\]\o\/\/\oo/\OoOOOO\[o*=/oooOOOO@@@@@@@@@@O[`
                                       =O@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOO@@@OOO@@O@@@@@@@OOOOOOOOOOOOOOooooooooooooo/,=oo=o\oooOoOOo\ooOoo/oOOOOOOOOOOOOOOOO/OOO/o``\oo/[oOO@@@@@@@@@@@.
                                      .\O@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOO@O@@@@@@@@@@@@@@@@@@@O@OOOOOOOOOOOOOOOOOOooooooooooooOOOOOOOOOOOOOOOOOOOOO@@@@@O@OOOOO\OOOO/^[*\\/\oOOO@@@@@@@@@`
                                      .=@@@@@@@@@@@@@OOOOOOOOOOOOO@OOO@@@O@OO@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOoOoOOOOOOOOOOOOOOOO@@OOO@@O@@@@@@OO@O@OOOOOOOOo`[/\/=oOO@@@@@@@O/
                                       .O@@@@@@@@@@@OOOOOOOOOOOOOOO@@OO@@@OO@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@O@O@OO@OO\OOOOOOO\\/``\oOO@@@O@O@O`
                                        \O@@@@@@@@@@OOOOOOOOOOOOOOOO@@OOOOOOO@OOOOOOOOOOOO@@@@@@@@@@@@@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OO@@@@OOOOOOOOOOOOOOOOO/OOOOOOO\\*\*\OO@@OOOO`
                                       ,\@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO/\,***`oO@@@@OO.
                                          @@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOooOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoOOoOOOoOOOOOoO/`,**=O@@OO@/
                                          O@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOooooo/ooooOoOOOOOOo\\***O@O@O^`
                                           O@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooOooOOOOOOOOOOOOOOOOOOOOOOOOOOoooooOOOOOOOOOOOOOOOOOOOOOOOooooooo\oo[\oooooooooOOOoo***O@@OO^
                                           =@@@@@@@OOoOOOOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOO@@@@@@OOOOOOOOOOOOOOOOOOOOOoooo\\/\oooOOOOOOOOOOOOOOOO@@@@@@OOOOOOOOOO@@@@@O/o\oooo[`**O@@OO
                                           ,@@@@@@OOoOOOOOOOOOOOOO@@OOOOOOOOOOOOOOOoooooooooo]oOOO@@@OOOOOOOOOOOOOooo\/[,**ooOOOOOOOOO@/OOOO/[[oooooooo/\ooo/`ooooooOO@/\o***O@OO.
                                            \@@@@@OooOOOOOOOOOOO@OOOOOOOOOOOO@@@@@@@@@\@@@@@OOOOOOOOOO\@OOOOOOOOOooo^`^*]*\ooooOOOOO@@OOOOO/OOOOOO@OOOOOO\o/oo/oo/ooo\\\\\****O@O/
                                            ,O@@@@OoOOOOOOOOOO@\\OOOOOOO@@@@@@@O@@@@@@@@@@OOO@@@OOOOOOOO\OOOOOOOOOoo`**=/]/ooOOOoOO@OOOOOO@@O@@@@O@O@@@@@@@@OOOo\\,]],o/],\\`**@@^
                                            .=@@@@ooOOOOOOOOO@/OOOOOOO@@@@@@@@OO@@@@@@@@@@\]]/@@@OOOO\OOO/@OOOOOOooo\*,\ooooOOooo@OOOOOO@@OOO@@@@@@@@@@@OOOO@@@OOOoooooo**OO^*=@O`
                                    /OOOOOO\/@@@@OOOOOOOOOOO@OOOOOOOOO@@@@@@@@OOOO@@@@@@@OOOO@@@@@OOOOOOOO/@OOOOOoooo\*ooooOOOo@oooOOOOOOOOOO@@@@@@@@@OoOOOO@@OOOOOOooo`*.^\@.*@O@\
                                   OOOOOOOOO`,\@@OOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOOOOOOOOOOoOOOOOo/@OOO./...,..`.,\[[O@\ooooOOooOOOOOOOOO@@OOOOOO]OOOOOOOOOOOoo**,/O\]OOOO/...
                                  =OO@@@OOOOO@`=o,@@@      =oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOOOOOOOOO@OOOOooooo\OOOOO]`oooOOooooOOOOOOOOOOOoOOOOOOOOOOOOOOOOoooo`/`*\OOOOOO/\/`=*
                                  =OO@@@@@OOOO@@\.O@@[\\/`,\oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOOOOOOOOOOo@OOOOOOOOOOOOOOOO@OOoooooo\oOOOOOOOOOOOOOoooo]ooooooo[[****]oo^\oO,[O/\OO@Oo.
                                  ,OO@@@@@@OO@@@ooOOOOOOOOO@oOOOOOOOOOOOOOooooooooooooOOOOOOOooooOOOOOOOOOOOO@OOOOOOoooo/ooOOO@OoOOOO/ooooooOOOOoooooooooo/[\o/,]ooooo\oo***\O*.O/OOOOOO.
                                  .OOOOO@@OO@O@OoOOOOOOOOOO@/OOOOOOOOOoOoooo\o\[`,/oooooooo/\oooOOOOOOOOO/OO\@OOOOoooo==]**\oO@^OO,/oO\/o,[,\ooooooo/\/[[]*,=]/ooooooo]/,****O^,*=OOOOOOO
                                   \OOOO@OOOO@@OOOOOOOOOOOO@/oOOOOOOOOOoooooo[``**`,,^**,,,`**o/ooOOOO/\OO@O@OOOOooo/o/][/[^=\O@oOO@[OOoo/=*^,[\[\[[\o\=]]/oooo/o/[[\o=o****=O^**=OOOOOOo
                                   =OOOOOOOOOO@OOOOOOOOOOOOO\oOOOOOOOOooooo^**,``[,*****,``[]/oOOOOOO/\`OO@O@OOOoOoooo/o^\^o\\/@OOOO]OOoooo/o*,*********`**[**,O/[,]******@,*,,oOOOOo^
                                    OOOOOOOOOO@OOOOOOOOOOOOO@=\OOOOOOOooooooo\oooooooOOoooOOOOOOOOOOO@O@OO\@OOOOOOooo/oo*,,[\\^/@\OOOOOoo/\]`,*`*`**,`*,*]`*]**,^*,,*******=O^**`*OOOOo`
                                    =OOOOOOOOO@OOOOOOOOOOOOOO\*OOOOOOoooooOOOOOOOOOOOOOOOOOOOOOOOOOO\.]OO/O@OOOOoooo/`\***[,``o`/\oOOOOOoooooooo/o\ooooooooooooo\o`,****,*,\/]`***o=OOO\
                                     OOOOOOOO@@OOOOOOOOOOOOOOO^*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@/=@OOOOooo\*```****,*^^*`\/OOOOOOOoooooooooooooooooooooo*=/\`,`**,**`***^=OOo^
                                     =OOOOOOOOO@OOOOOOOOOOOOOOO^*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO/@OOOOOooo^\**]**,`*`*,**]\/OOOOOOooooOOooooooooooooo/\`[`=o[\\,[,/,/`,***^=Oo/
                                      OOOOOOOOOOOOOOOOOOOOOOOOOO\,oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO^/@OOOOOOOoooo/,`**^*,,`\*,,o\^OOOOOOoooooooooo/\oo\o/[o/\\/oooooo=/^*,*,=^OOo.
                                      =OOOOOOOOOOOOOOOOOOOOOOOOOO@.\OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO,@OOOOOOOOOOoooo\],`/`\*,\\o,/\,\\OOOOOooOOOOoooooo/o/^\/\/\o/o\^/`/o\\,/`*=^=o^
                                       OOOoOOOOOOOOOOOOOOOOOOOOOOOO\,/OOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOoooo\=\o\oooo^^*=\\OOOOoOooooooooooo\]/\[^\[/]\\o/`]^**o`oo.
                                       ,OOOOOOOOOOOOOOOOOOOOOOOOOOOO@\,\OOOOOOOOOOOOOOOOOOOOOOOOO\O@OOOOOOOOOOOOOOOOOOOOOOoooooooooooo**@\/oooooooooooooooo/\\/[`,,@\oooo\/o^*,/o^
                                        =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@\`[o\OOOOOOOOOOOOOOO/[,/@@OOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOooooOO/@\O/[ooooooooooo,,]/`]oooo\o\oo\/`*Oo^
                                         OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@]]]. .  ,]]]@@@OOO@@OOOOOOOO@@@@@@@@OOOOOOOOOOOOO@@OOOOOoooOOOOOO\/O\@@@@@/[\]ooo\\oooooooooo\/,=Ooo.
                                         ,OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@OOOO@@@@@@@@@@@@@@@OOO@@@@@@@@OOOOOOOOOOOOOOOOOOOOOoOoooooo/ooooooooooo/\*Oo[^.
                                          =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@OOOOOOOO@@@@OOOOOOOOOOOOOOOOOOooOooooooooooooooo/oooo^/=o`,
                                           oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@OOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOOOOOOOoooooo\oo/oooooo/ooooooo**
                                            OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoo\OOOOOOOOoOoOoOooooooooooooooo\\`\o/
                                              \OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo*]o/[o/ooooOooooooooooooooooooo/OO/.
                                                    =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoOOOoOoOOOOOOOOOOOOOOOOOOOooOOOOOOOOOOOOOOOOOO\oooo=,*`=\/=^\/]ooooooooooooooooooo].  ..
                                                     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOoooOOOOOoo/oOOOoo\\o\\o\]/^*,``***\/\]/o]oooooooooooooo\*
                                                     =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOoOooooO/o[/ooooooooO\o\/\\\[/\`\*]]^o=/\ooooooooo/oooo\`
                                                     =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOooOOOOOOOo/\\o\O\ooooo\o/[`,*\]`o[^oooooooooooooo^^^
                                                      OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOo/[\oooOo/\oo\\o/^oo\o/o/oooooooo\o/o*
                                                      =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@O@OOOOOOOOOOOOOOOOOOOOOOOOOOO\ooooOoOoOOO/]oo=ooooooooooooo/\\
                                                      =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@OOOO@OOOOOOOOOOOOOOOOOOOOOOOOOooo\OOOOOoO/o\\\oo\ooooooooo\/`
                                                       OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@OOOO@@@@@OOOO@OOOOOOOOOOOOO@OOOOOOOOOOO/OOO/o/oo/ooooooooo[o
                                                       =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOO@@O@@OOOOOOOOOOOOOo/ooooooooooooo\\`
                                                        \OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOO@@@@OOOOOOOOOOO\oooooooooooo\`^
                                                        ,OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@O@@O@@OOOOOOOOOOOOOOOOOOOOO/OOOOOO@@@@@@@@@@@OOOOOOOOOOoOooooooooooo\^`
                                                         =OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOO/o/oOOOOO=/OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooooooooo`
                                                          \OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOo\o/oo\OOOOOOOOOOoOOOOOOOOOOOOooooooooooo/
                                                           OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooooooo/
                                                            OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoOoooooo\`
                                                             OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooo/o^
                                                              \OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@OOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooo^
                                                               =OOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooo*
                                                                OOOOOOOO@@OOOOOOOOOOOOOOOO@@@@O@OOOO@@@@@@@@@@O@@@@@@@@@@@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooo
                                                                OOOOOOOOOOO@OOOOOOOOOOOOO@@OO@@@OOOOOOOOOO@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOooooo
                                                                OOO@OOOO@@OOOOOOOOOOOOOOO@OOO@O@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooo
                                                                OOO@@@O@OO@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooo
                                                                OOO@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooo
                                                                OO@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOooooo
                                                                =O@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOOOOOOOOOOOOoOooo
                                                                =OO@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooOooooOOOOOOOOOOOOOOOOOOoooo
                                                                =OO@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOOOooooOOoOOOOOOOOOOOOOOOOOOoOoOooo
                                                                =OO@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoooo
                                                                =OOO@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooo
                                                                /OOOO@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooo
                                                                OOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoooooo
                                                                OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOO@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooo
                                                                OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOoOoooooooo^
                                                                OOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOoooooo^
                                                              ,OOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOoOoooooo^
                                                             ,OOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOOOOooooooo^
                                                   ]@@@@@@OOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@O@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooo\
                                               ,@@@@@OOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOoOOOoooooooooo`
                                           ,]@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOoOOOOOOOOooooooooooooOO\]`
                                      ,@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooooooooooooO@@@@\`
                                  ,/@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooooooooooO@@@@`    ,`
                               ,/@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@O@@@@@O@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooooooooooooO@@@@O/^
                            ]@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoooOoOOooooooooooooooooOO@@@@@@@@@\`
                       ]O@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOOoOOOooooooooooooooooOO@@@@@@@@@@@@]
                  ]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@OO@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOOOOOOOooooooooooooooooOO@@@@@@@@@@@@@@@\`
            ,]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOoOOOoOOOooooooooooooooooO@@@@@@@@@@@@@@@@@@@O]
       ]]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@OO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOOOOoOOoooooooooooooOO@@@@@@@@@@@@@@@@@@@@@@@@\]`
  ]@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@O@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOOoOOOOooooooooooooooooOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\].
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOOOOOooooooOoooooooOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@OO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooOoooooooOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooooooooooooOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOO@OOOOOO@OOOOOOOOOOOOOOOOO@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooOoOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOO@OOOOOOOO@OOO@OOOOOOOOOOOOOOOOOOOOO@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooOoooOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOO@@@OOOOOOOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOO@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOooOoooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOO@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOoOOoOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOO@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOooOoOooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoOooOOOOOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[`                                                                                                        ,[`,`[[[[[[[[[[[[,.`[    ````       ,...,,.,
³ÂÓÜ½Ý±£ÓÓ£¬´úÂëÎÞ BUG¡£
*/

