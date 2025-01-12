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
        int N, K;
        cin >> N >> K;
        vector<int> start(N);
        vector<int> end(N);
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            start[a-1]++;
            end[b-1]++;
        }
        vector<int> prefixStart(N);
        vector<int> prefixEnd(N);
        prefixStart[0] = start[0];
        prefixEnd[0] = end[0];
        for (int i = 1; i < N; i++) {
            prefixStart[i] = prefixStart[i-1] + start[i];
            prefixEnd[i] = prefixEnd[i-1] + end[i];
        }

        vector<int> cnt(N);
        
        for (int i = 0; i < N; i++) {
            cnt[i] = prefixStart[i] - prefixEnd[i] + end[i];
        }
        
        sort(all(cnt));
        cout << cnt[N/2];

    }