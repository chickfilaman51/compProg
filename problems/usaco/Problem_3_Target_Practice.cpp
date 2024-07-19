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

void setFile(string name = "") {
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    int T, C;
    cin >> T >> C;
    set<int> targets;
    for (int i = 0; i < T; ++i) {
        int pos;
        cin >> pos;
        targets.insert(pos);
    }

    string commands;
    cin >> commands;

    vector<int> prefix(C, 0);
    vector<vector<int>> suffix(C, vector<int>(5));
    int pos = 0, hits = 0;
    for (int i = 0; i < C; ++i) {
        if (commands[i] == 'F' && targets.count(pos)) {
            hits++;
            targets.erase(pos); 
        }
        prefix[i] = hits;
        if (commands[i] == 'L') --pos;
        else if (commands[i] == 'R') ++pos;
    }


    for (int i = C - 1; i >= 0; i--) {
        if (i != C - 1) {
            for (int j = -2; j <= 2; j++) {
                suffix[i][j + 2] = suffix[i + 1][j + 2];
            }
        }
        if (commands[i] == 'F') {
            hits++;
            targets.erase(pos); 
            for (int j = -2; j <= 2; j++) {
                if (targets.count(pos + j)) {
                    suffix[i][j + 2] += 1;
                }
            }
        }
        if (commands[i] == 'L') ++pos;
        else if (commands[i] == 'R') --pos;
    }
    for (int i = 0; i < C; ++i) {
        suffix[i][2] = prefix[C-1] - prefix[i];
    }
    
    int max_hits = 0;
    vector<char> poss = {'L', 'R', 'F'};
    for (int i = 0; i < C; ++i) {
        for (int j = -2; j <= 2; j++) {
            max_hits = max(max_hits, prefix[i-1] + suffix[i][j + 2]);
        }
    }
    cout << max_hits << endl;
    
}