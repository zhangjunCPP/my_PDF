struct Query { int l, r, id, co; inline bool operator<( const Query &O ) const {
		       return(l != O.l ? l > O.l : id < O.id);
	       }
}; vector<Query>Q[N];

inline void getdis( Re x, Re rt, Re fa, Re d1, Re d2 ) /* d1:最小值 d2:最大值 */{
	d1 = min( d1, x );
    d2 = max( d2, x );
    Q[rt].push_back( (Query) { d1, d2, 0, A[x] } );
	frt[x][++gs[x]] = rt, fd1[x][gs[x]] = d1, fd2[x][gs[x]] = d2;
	for ( Re i = head[x], to; i; i = a[i].next )
		if ( !vis[to = a[i].to] && to != fa )
			getdis( to, rt, x, d1, d2 );
}

inline void change( Re x, Re l, Re r, Re id ) /* 插入第id次询问l,r,x */{
	for ( Re i = 1; i <= gs[x]; ++i )
		if ( l <= fd1[x][i] && fd2[x][i] <= r ){
			Q[frt[x][i]].push_back( (Query) { l, r, id, 0 } ); break;
		}
}

struct BIT {
	int		C[N];
	inline void	CL( Re x ){
		while ( x <= n )
			C[x] = 0, x += x & - x;
	}
	inline void add( Re x, Re v ){
		while ( x <= n )
			C[x] += v, x += x & - x;
	}
	inline int ask( Re x ){
		Re ans = 0; 
        while ( x )ans += C[x], x -= x & - x;
		return(ans);
	}
} TR;

inline int GetAns(){
	for ( Re i = 1; i <= 100000; ++i )mir[i] = inf;
	for ( Re rt = 1; rt <= n; ++rt ){   /* 枚举点分树上的点 */
		sort( Q[rt].begin(), Q[rt].end() );
		for ( IT it = Q[rt].begin(); it != Q[rt].end(); ++it )
			if ( it->id ) 
                Ans[it->id] = TR.ask( it->r );  /* 查询 */
			else if ( it->r < mir[it->co] ) 
                TR.add( mir[it->co], -1 ), TR.add( mir[it->co] = it->r, 1 );
		       /* 节点信息，更新此颜色的最小右端点 */
		for ( IT it = Q[rt].begin(); it != Q[rt].end(); ++it )
			if ( !(it->id) ) TR.CL( mir[it->co] ), mir[it->co] = inf;
	}
}

