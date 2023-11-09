#include <iostream>
#include <stack>
#include <vector>

const int M = 200003;
const int N = 100002;

int n, m;

std::stack<int> stack;

struct Edge {
	int to, nxt;
} ed[M];
int head[N], cnt;

void add_edge(int u, int v) {
	ed[++cnt].to = v, ed[cnt].nxt = head[u], head[u] = cnt;
}

int vis_n[N], vis_e[M];
int in[N], out[N];

std::vector<std::vector<int>> circle;

void dfs(int x) {
	if(vis_n[x] == 2)	return;
	if(vis_n[x] == 1)	{
		std::vector <int> _ans;
		while(stack.top() != x)	{
			_ans.push_back(stack.top());
			vis_n[stack.top()] = 2;
			stack.pop();
		}
		_ans.push_back(stack.top());
		vis_n[stack.top()] = 2;
		stack.pop();
		circle.push_back(_ans);
		return;
	}
	vis_n[x] = 1;
	stack.push(x);
	for (int i = head[x]; i; head[x] = ed[i].nxt, i = ed[i].nxt) {
		if(vis_n[x] == 2)	return;
		int to = ed[i].to;
		if (vis_e[i] == 1) continue;
		if (vis_n[to] == 2) continue;
		dfs(to);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("hamilton.in", "r", stdin);
	freopen("hamilton.out", "w", stdout);

	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		add_edge(u, v);
		++in[v], ++out[u];
	}

	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0 || out[i] == 0) {
			std::cout << "NO" << std::endl;
			return 0;
		}
	}

	for(int i = 1; i <= n; ++i)	{
		if(vis_n[i] != 2)	{
			dfs(i);
		}
	}

	std::cout << "YES" << std::endl;

	for(auto i : circle)	{
		std::cout << i.size() << ' ';
		for(auto j : i)	{
			std::cout << j << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
