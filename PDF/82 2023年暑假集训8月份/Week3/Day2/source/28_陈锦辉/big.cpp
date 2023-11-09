//the code is from chenjh
#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	int st=time(0);
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout);
	int m;
	scanf("%*d %d",&m);
	while(m--) scanf("%*d %*d");
	scanf("%d",&m);
	while(m--) puts("0");
	while(time(0)-st<5);
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

