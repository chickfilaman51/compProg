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

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }

    vector<int> start(2*M + 1);
    vector<int> end(2*M + 1);
    vector<int> a_freq(M + 1);

    for (auto interval : intervals) {
        a_freq[interval.first]++;
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            start[i + j] += a_freq[i] * a_freq[j];
        }
    }

    vector<int> b_freq(M + 1);
    for (auto interval : intervals) {
        b_freq[interval.second]++;
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            end[i + j] += b_freq[i] * b_freq[j];
        }
    }

    ll ans = 0;

    for (int i = 0; i <= 2*M; i++) {
        ans += start[i];
        cout << ans << endl;
        ans -= end[i];
    }

}