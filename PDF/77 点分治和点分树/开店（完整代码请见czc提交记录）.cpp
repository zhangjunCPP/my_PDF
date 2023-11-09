struct QWQ {
	int v; LL S1, S2; QWQ( Re V = 0, LL s1 = 0, LL s2 = 0 )
	{
		v = V, S1 = s1, S2 = s2;
	}


	inline bool operator<( const QWQ &O ) const
	{
		return(v < O.v);
	}
};
vector<QWQ>TR[N];
inline void getdis( Re x, Re fa, Re rt, Re d )
{
	TR[rt].push_back( QWQ( A[x], d, Fa[rt] ? Dis( x, Fa[rt] ) : 0 ) ); 
    /* 如果rt没有父亲就不要求dis了 */
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] && to != fa )
			getdis( to, x, rt, d + a[i].w );
}


inline void sakura( Re x )
{
	Re now = sum; vis[x] = 1, getdis( x, 0, x, 0 );
	sort( TR[x].begin(), TR[x].end() );       /* 预排序 */
	for ( Re i = 1; i < now; ++i )
		TR[x][i].S1 += TR[x][i - 1].S1, TR[x][i].S2 += TR[x][i - 1].S2;  /* 前缀和 */
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] )
			sum = size[to] > size[x] ? now - size[x] : size[to], maxp[rt = 0] = inf, getrt( to, 0 ), Fa[rt] = x, sakura( rt );
}


inline QWQ get( Re x, Re K )    /* 获取权值小于等于K的点信息之和 */
{
	vector<QWQ>::iterator it = upper_bound( TR[x].begin(), TR[x].end(), QWQ( K ) );
	if ( it == TR[x].begin() )
		return(QWQ() );
	--it; return(QWQ( (it - TR[x].begin() ) + 1, it->S1, it->S2 ) );
}


inline LL ask( Re x, Re K )    /* 查询权值小于等于K的点与x的距离之和 */
{
	QWQ TR = get( x, K ); LL ans = TR.S1;
	if ( Fa[x] )
		ans -= TR.S2 + (LL) Dis( x, Fa[x] ) * TR.v;    
    /* 为迎合拆柿子,这里把第一次计算拿出来了 */
	for ( Re i = Fa[x]; i; i = Fa[i] )
	{
		TR = get( i, K ), ans += TR.S1 + (LL) Dis( x, i ) * TR.v;
		if ( Fa[i] )
			ans -= TR.S2 + (LL) Dis( x, Fa[i] ) * TR.v;
	}
	return(ans);
}



