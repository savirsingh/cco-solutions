// code by savir singh
// 50/50 on DMOJ

#include <bits/stdc++.h>
using namespace std;

const int MM = 18;

int N, M, graph[MM][MM], dp[MM][1 << MM];

int solve(int node, int mask) {
    if (node == N - 1) dp[node][mask] = 0;
    else if (dp[node][mask] < 0) {
        for (int nxt = 0; nxt < N; ++nxt) {
            if (!(mask & 1 << nxt) && graph[node][nxt]) {
                dp[node][mask] = max(dp[node][mask], graph[node][nxt] + solve(nxt, mask | (1 << nxt)));
            }
        }
    }
    return dp[node][mask];
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, w; cin >> u >> v >> w;
        graph[u][v] = w;
    }
    memset(dp, -0x3f, sizeof dp);
    cout << solve(0, 1) << endl;
}
