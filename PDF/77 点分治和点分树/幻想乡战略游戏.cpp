inline void change( Re x, Re v ) /* Sv即为g1 */
{
	TR1[x] += v * 0, Sv[x] += v;
	for ( Re i = gs[x]; i >= 2; --i )
	{
		Re tmp = fdis[x][i - 1];
		TR1[frt[x][i - 1]]	+= (LL) v * tmp;
		TR2[frt[x][i]]		+= (LL) v * tmp;
		Sv[frt[x][i - 1]]	+= v;
	}
}


inline LL ask( Re x ) /* 计算F(x) */
{
	LL ans = TR1[x];
	for ( Re i = gs[x]; i >= 2; --i )
	{
		Re tmp = fdis[x][i - 1];
		ans	+= TR1[frt[x][i - 1]];
		ans	-= TR2[frt[x][i]];
		ans	+= (LL) (Sv[frt[x][i - 1]] - Sv[frt[x][i]]) * tmp;
	}
	return(ans);
}


inline LL find( Re x )
{
	LL tmp = ask( x );
	for ( Re i = T0.head[x]; i; i = T0.a[i].next )  /* 这里枚举原树 */
		if ( ask( T0.a[i].to ) < tmp )
			return(find( T0.a[i].rt ) );
	          /* 如果to比x优秀就进入to所在连通块的重心（x在虚树上的儿子） */
	return(tmp);
}



