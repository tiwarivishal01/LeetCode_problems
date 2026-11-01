class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        using State = tuple<int, int, int, char>;
        priority_queue<State, vector<State>, greater<State>> pq;

        vector<unordered_map<long long, int>> dist(n);

        pq.push({0, 0, 1, labels[0]});

        auto encode = [](int count, char ch) -> long long {
            return (static_cast<long long>(count) << 8) |
                   static_cast<unsigned char>(ch);
        };

        dist[0][encode(1, labels[0])] = 0;

        while (!pq.empty()) {
            auto [cost, node, count, last] = pq.top();
            pq.pop();

            long long state = encode(count, last);

            if (!dist[node].count(state) || dist[node][state] != cost) {
                continue;
            }

            if (node == n - 1) {
                return cost;
            }

            for (auto& [next, weight] : adj[node]) {
                char ch = labels[next];
                int newCount = (ch == last) ? count + 1 : 1;

                if (newCount > k) {
                    continue;
                }

                long long newState = encode(newCount, ch);
                int newCost = cost + weight;

                if (!dist[next].count(newState) ||
                    newCost < dist[next][newState]) {
                    dist[next][newState] = newCost;
                    pq.push({newCost, next, newCount, ch});
                }
            }
        }

        return -1;
    }
};