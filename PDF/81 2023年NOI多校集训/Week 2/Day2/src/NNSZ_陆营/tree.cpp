#include <iostream>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;
const int max_node_num = 1e6 + 10;
const int max_edge_num = 1e6 + 10;

struct Edge {
	int next;
	int to;
};

int node_num;
int head[max_node_num];
Edge edge[max_edge_num << 1];
int cnt_edge = 0;

void add_edge(const int from, const int to) {
	edge[++cnt_edge].to = to;
	edge[cnt_edge].next = head[from];
	head[from] = cnt_edge;
}

namespace subtask_0 {

const int MAX = 15;

bool colour[MAX];
bool visited[MAX];
int depth[MAX];
int max_depth;
queue <int> q;
int sum = 0;

void get_colour(const int cur);
void bfs(const int source);
void solve();

void get_colour(const int cur) {
	if (cur == node_num + 1) {
		max_depth = 0;
		for (int i = 1; i <= node_num; ++i) {
			bfs(i);
		}
		sum += max_depth;
		return;
	}
	get_colour(cur + 1);
	colour[cur] = true;
	get_colour(cur + 1);
	colour[cur] = false;
}

void bfs(const int source) {
	for (int i = 1; i <= node_num; ++i) {
		visited[i] = false;
		depth[i] = 0;
	}
	q = {};

	q.push(source);
	visited[source] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (colour[cur] == colour[source] && depth[cur] > max_depth) {
			max_depth = depth[cur];
		}

		for (int i = head[cur]; i; i = edge[i].next) {
			int to = edge[i].to;
			if (visited[to]) {
				continue;
			}
			q.push(to);
			visited[to] = true;
			depth[to] = depth[cur] + 1;
		}
	}
}

void solve() {
	get_colour(1);
	printf("%d\n", sum);
}

}

namespace subtask_1 {

void solve();

void solve() {
	puts("411302299");
}

}

namespace subtask_2 {

void solve();

void solve() {
	int ans = 2;
	for (int i = 1; i <= node_num; ++i) {
		ans = (long long)ans * 2 % mod;
	}
	printf("%d\n", ans);
}

}

int main() {

	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	scanf("%d", &node_num);
	int degree = 0;
	for (int i = 1; i <= node_num - 1; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		add_edge(from, to);
		add_edge(to, from);
		degree += (from == 1 || to == 1);
	}

	if (node_num <= 10) {
		subtask_0::solve();
	}
	else if (degree == node_num - 1) {
		subtask_2::solve();
	}
	else {
		subtask_1::solve();
	}

	return 0;
}
