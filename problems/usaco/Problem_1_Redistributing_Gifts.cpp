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
    int N;
    cin >> N;
    vector<vector<int>> prefs(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            prefs[i][j] = a-1;
        }
    }
    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        cows[i] = i;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < find(all(prefs[i]), cows[i]) - prefs[i].begin(); j++) {
            int currentItem = cows[i];
            int prefferedItem = prefs[i][j];
            int personPreffered = find(all(cows), prefferedItem) - cows.begin();
            if (find(all(prefs[personPreffered]), currentItem) - prefs[personPreffered].begin() < find(all(prefs[personPreffered]), prefferedItem) - prefs[personPreffered].begin()) {
                swap(cows[i], cows[personPreffered]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << cows[i] + 1 << endl;
    }


    



}