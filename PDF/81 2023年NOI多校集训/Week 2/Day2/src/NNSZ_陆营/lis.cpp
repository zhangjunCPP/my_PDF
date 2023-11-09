#include <iostream>
#include <algorithm>
using namespace std;

const int max_node_num = 5e5 + 10;
const int max_edge_num = 5e5 + 10;

struct Edge {
	int next;
	int to;
};

int head[max_node_num];
Edge edge[max_edge_num << 1];
int cnt_edge = 0;

int node_num;
int weight[max_node_num];
int deleted;
int stack[max_node_num], top = 0;
int max_len;

void add_edge(const int from, const int to);
void dfs(const int cur, const int fa);

int main() {
    
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);

	scanf("%d", &node_num);
	for (int i = 1; i <= node_num - 1; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		add_edge(from, to);
		add_edge(to, from);
	}
    for (int i = 1; i <= node_num; ++i) {
        scanf("%d", &weight[i]);
    }

    int ans = node_num;
    for (deleted = 1; deleted <= node_num; ++deleted) {
        max_len = 0;
        for (int i = 1; i <= node_num; ++i) {
            if (i == deleted) {
                continue;
            }
            dfs(i, 0);
        }
        ans = min(ans, max_len);
    }

    printf("%d\n", ans);

	return 0;
}

void add_edge(const int from, const int to) {
	edge[++cnt_edge].to = to;
	edge[cnt_edge].next = head[from];
	head[from] = cnt_edge;
}

void dfs(const int cur, const int fa) {
    int prev_top = top;
    int pos = -1, prev_element = -1;
    if (weight[cur] > stack[top]) {
        stack[++top] = weight[cur];
    }
    else {
        pos = lower_bound(stack + 1, stack + top + 1, weight[cur]) - stack;
        prev_element = stack[pos];
        stack[pos] = weight[cur];
    }
    max_len = max(max_len, top);

    for (int i = head[cur]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == fa || to == deleted) {
            continue;
        }
        dfs(to, cur);
    }

    if (prev_element != -1) {
        stack[pos] = prev_element;
    }
    if (top != prev_top) {
        --top;
    }
}
