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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> pfx(N);
    pfx[0] = A[0];
    for (ll i = 1; i < N; i++) {
        pfx[i] = pfx[i - 1] + A[i];
    }
    map<ll, ll> cnt;
    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (pfx[i] == X) {
            ans++;
        }
        ans += cnt[pfx[i] - X];
        cnt[pfx[i]]++;
    }
    cout << ans << endl;

}