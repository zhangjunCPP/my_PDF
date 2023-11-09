#include <iostream>
#include <vector>
using namespace std;

const int max_node_num = 1e5 + 10;
const int max_edge_num = 2e5 + 10;

struct Edge {
	int next;
	int to;
} edge[max_edge_num];
int cnt_edge = 0;

int head[max_node_num];
int colour[max_node_num], cur_colour = 0;
int cnt_colour[max_node_num];
bool visited[max_node_num];
bool is_loop = false;
int cur_root;
int cur_loop = 0;
vector <int> loop[max_node_num];

void add_edge(const int from, const int to);
void paint(const int cur);
void get_loop(const int cur);

int fast_read();
void fast_write(const int & num);

int main() {

	freopen("hamilton.in", "r", stdin);
	freopen("hamilton.out", "w", stdout);

	int node_num = fast_read(), edge_num = fast_read();
	for (int i = 1; i <= edge_num; ++i) {
		int from = fast_read(), to = fast_read();
		add_edge(from, to);
	}

	for (int i = 1; i <= node_num; ++i) {
		if (colour[i]) {
			continue;
		}
		++cur_colour;
		paint(i);
	}

	for (int i = 1; i <= node_num; ++i) {
		if (visited[i]) {
			continue;
		}
		++cur_loop;
		cur_root = i;
		is_loop = false;
		get_loop(i);
		if (loop[cur_loop].size() != cnt_colour[colour[i]]) {
			puts("NO");
			return 0;
		}
	}

	puts("YES");
	for (int i = 1; loop[i].size(); ++i) {
		fast_write(loop[i].size());
		putchar(' ');
		for (const int & j : loop[i]) {
			fast_write(j);
			putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}

inline void add_edge(const int from, const int to) {
	edge[++cnt_edge].to = to;
	edge[cnt_edge].next = head[from];
	head[from] = cnt_edge;
}

void paint(const int cur) {
	colour[cur] = cur_colour;
	++cnt_colour[cur_colour];
	for (int i = head[cur]; i; i = edge[i].next) {
		int to = edge[i].to;
		if (colour[to]) {
			continue;
		}
		paint(to);
	}
}

void get_loop(const int cur) {
	loop[cur_loop].push_back(cur);
	visited[cur] = true;

	for (int i = head[cur]; i; i = edge[i].next) {
		if (is_loop) {
			return;
		}
		int to = edge[i].to;
		if (to == cur_root && loop[cur_loop].size() == cnt_colour[colour[cur]]) {
			is_loop = true;
			return;
		}
		if (visited[to]) {
			continue;
		}
		get_loop(to);
	}
	
	if (!is_loop) {
		visited[cur] = false;
		loop[cur_loop].pop_back();
	}
}

inline int fast_read() {
	char ch = getchar();
	while (ch < '0' || '9' < ch) {
		ch = getchar();
	}
	int res = 0;
	while ('0' <= ch && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	}
	return res;
}

void fast_write(const int & num) {
	if (num > 9) {
		fast_write(num / 10);
	}
	putchar(num % 10 + 48);
}
