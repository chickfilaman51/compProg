// in progress

#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


#define ar array
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> mins;
vector<int> maxs;
int max_node = 0;
int min_node = MAX_N;
int ans = 0;
void dfs(int current_node) {
    if (visited[current_node]) { return; }
    visited[current_node] = true;
    max_node = max(max_node, current_node);
    min_node = min(min_node, current_node);
    for (int neighbor : adj[current_node]) { dfs(neighbor); }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        adj.assign(N + 1, vector<int>());
        visited.assign(N + 1, false);
        mins.clear();
        maxs.clear();

        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if (N == 10 && M == 7) {
                dbg(a, b);
            }
        }
        
        if (N == 10 && M == 7) {

            dbg(adj);
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                max_node = i;
                min_node = i;
                dfs(i);
                mins.push_back(min_node);
                maxs.push_back(max_node);
            }
        }
        if (N == 10 && M == 7) {

            dbg(mins);
            dbg(maxs);
        }

        ans = 0;

        for (int i = 0; i < mins.size(); i++) {
            if (maxs[i] == N || i == mins.size()-1) {
                break;
            }
            int raw = (maxs[i] - mins[i+1]);
            ans += raw * raw;
        }
        cout << ans << endl;
    }

}