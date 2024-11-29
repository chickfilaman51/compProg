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

void setFile(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> adj;
vector<bool> visited;
int ans = 0;
int currentMax = 0;

void dfs(int current_node, int dist) {    
    if (dist > 2) { return; }
    if (visited[current_node]) { return; }

    visited[current_node] = true;
    currentMax++;
    dist++;
    for (int neighbor : adj[current_node]) { dfs(neighbor, dist); }
}

int main() {
    setFile("planting");
    int N;
    cin >> N;
    adj.resize(N);
    visited.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++) {
        currentMax = 0;
        if (!visited[i]) {
            dfs(i, 0);
        }
        ans = max(ans, currentMax);
    }

    cout << ans << endl;


}