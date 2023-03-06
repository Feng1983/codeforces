class MinCostFlow {
public:
    static constexpr int INF = 1'000'000'000;
    const int n;
    std::vector<std::tuple<int, int, int>> e;
    std::vector<std::vector<int>> g;
    std::vector<int> h, dis, pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, INF);
        pre.assign(n, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] != d)
                continue;
            for (int i : g[u]) {
                auto [v, f, c] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + hu] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != INF;
    }
    MinCostFlow(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int f, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, f, c);
        g[v].push_back(e.size());
        e.emplace_back(u, -f, 0);
    }
    auto minCostMaxFlow(const int s, const int t) {
        int flow = 0, cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i)
                h[i] += dis[i];
            for (int i = t; i != s; i = std::get<0>(e[pre[i] ^ 1])) {
                --std::get<2>(e[pre[i]]);
                ++std::get<2>(e[pre[i] ^ 1]);
            }
            ++flow;
            cost += h[t];
        }
        return std::make_pair(flow, cost);
    }
};
