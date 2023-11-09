int ip_O, n, o, x, y, T, op, MaxX, X[N], ip[N], Yl[N], Yr[N], idl[N], idr[N], head[N]; vector<int>V[N]; map<int, int>id[N];
struct QAQ { int to, next; }	a[N << 1]; /* 外层的这个是缩图所得到的树 */
inline void add( Re x, Re y ){
	a[++o].to = y, a[o].next = head[x], head[x] = o;
}

struct Tree {
	int o, head[N];
	struct QAQ { int to, next; } a[N << 2];
	inline void add_( Re x, Re y ){
		a[++o].to = y, a[o].next = head[x], head[x] = o;
	}

	inline void add( Re x, Re y ){
		add_( x, y ), add_( y, x );
	}
} T0;  /* T0:以二维平面上的连通性建成的图 */

inline void get_tree()  /* 缩图建树 */
{
	for ( Re i = 1; i <= n; ++i )
		in( x ), in( y ), MaxX = max( MaxX, x ), V[x].push_back( y ), id[x][y] = i;
	for ( Re x = 1; x <= MaxX; ++x )
		if ( !V[x].empty() )
		{
			sort( V[x].begin(), V[x].end() );
			Re last = -1; idl[x] = ip_O + 1;
			for ( Re J = 0, SZ = V[x].size(), y; J < SZ; last = V[x][J], ++J )
			{
				if ( last + 1 != (y = V[x][J]) )
					ip[id[x][y]] = ++ip_O, X[ip_O] = x, Yl[ip_O] = Yr[ip_O] = y;
				else ip[id[x][y]] = ip_O, Yr[ip_O] = y, T0.add( id[x][y], id[x][y - 1] );
				if ( id[x - 1].find( y ) != id[x - 1].end() )
					T0.add( id[x - 1][y], id[x][y] );
			}
			idr[x] = ip_O;
			if ( V[x - 1].empty() )
				continue;
			Re k = idl[x - 1];
			for ( Re j = idl[x]; j <= idr[x]; ++j )
			{
				while ( k <= idr[x - 1] && Yr[k] < Yl[j] )
					++k;
				for ( Re k_ = k; k_ <= idr[x - 1] && Yl[k_] <= Yr[j]; ++k_ )
					add( k_, j ), add( j, k_ );
			}
		}
}


struct QWQ {
	int d, y; QWQ( Re D = 0, Re Y = 0 )
	{
		d = D, y = Y;
	}


	inline bool operator<( const QWQ &O ) const
	{
		return(d < O.d);
	}
};
struct BIT {
	int		n, op; vector<int>C;   
    /* op=0:前缀  op=1:后缀(把询问、查询里的x都翻转一下就是了) */
	inline void	build( Re N )
	{
		n = N, C.push_back( inf ); while ( N-- )
			C.push_back( inf );
	}    /* 这里就不用resize了,因为要初始化为inf */


	inline void add( Re x, Re v )
	{
		if ( op )
			x = n - x + 1;
		while ( x <= n )
			C[x] = min( C[x], v ), x += x & - x;
	}


	inline int ask( Re x )
	{
		if ( op )
			x = n - x + 1;
		Re ans = inf; while ( x )
			ans = min( ans, C[x] ), x -= x & - x;
		return(ans);
	}
}	TR1[N], TR2[N];
int	rt, sum, gs[N], vis[N], maxp[N], size[N], frt[N][22]; QWQ fdis[N][22];
inline void getrt( Re x, Re fa )
{
	size[x] = Yr[x] - Yl[x] + 1, maxp[x] = 0; /* 注意size的初始化不是1 */
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] && to != fa )
			getrt( to, x ), size[x] += size[to], maxp[x] = max( maxp[x], size[to] );
	maxp[x] = max( maxp[x], sum - size[x] ); if ( maxp[x] < maxp[rt] )
		rt = x;
}


int Q[N], pan[N]; QWQ dis[N];
inline void getdis0( Re rt ) /* bfs */
{
	Re h = 1, t = 0;
	for ( Re i = Yl[rt]; i <= Yr[rt]; ++i )
		pan[Q[++t] = id[X[rt]][i]] = rt, dis[Q[t]] = QWQ( 0, i - Yl[rt] + 1 );
	while ( h <= t )
	{
		Re x = Q[h++];
		for ( Re i = T0.head[x], to; i; i = T0.a[i].next )
			if ( pan[to = T0.a[i].to] != rt && !vis[ip[to]] )
				dis[to] = QWQ( dis[x].d + 1, dis[x].y ), pan[Q[++t] = to] = rt;
	}
}


inline void getdis( Re x, Re rt, Re fa )
{
	frt[x][++gs[x]] = rt;
	for ( Re i = Yl[x]; i <= Yr[x]; ++i )
		fdis[id[X[x]][i]][gs[x]] = dis[id[X[x]][i]];  /* 距离在bfs中已获得 */
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] && to != fa )
			getdis( to, rt, x );
}


inline void sakura( Re x )
{
	Re now = sum; vis[x] = 1, getdis0( x ), getdis( x, x, 0 );
	TR1[x].build( Yr[x] - Yl[x] + 1 );
    TR2[x].build( Yr[x] - Yl[x] + 1 );
    TR2[x].op = 1; /* 树状数组的使用范围为[1,Yr-Yl+1] */
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] )
			sum = size[to] > size[x] ? 
            	now - size[x] : size[to], maxp[rt = 0] = inf, 
    				getrt( to, 0 ), sakura( rt );
}


inline void change( Re y )
{
	Re x = ip[y];
	for ( Re i = gs[x]; i; --i )
		TR1[frt[x][i]].add( fdis[y][i].y, fdis[y][i].d - fdis[y][i].y );
		TR2[frt[x][i]].add( fdis[y][i].y, fdis[y][i].d + fdis[y][i].y );
}


inline int ask( Re y )
{
	Re x = ip[y], ans = inf;
	for ( Re i = gs[x]; i; --i )
		ans	= min( ans, fdis[y][i].d + fdis[y][i].y + TR1[frt[x][i]].ask( fdis[y][i].y ) );
		ans	= min( ans, fdis[y][i].d - fdis[y][i].y + TR2[frt[x][i]].ask( fdis[y][i].y ) );
	return(ans);
}



