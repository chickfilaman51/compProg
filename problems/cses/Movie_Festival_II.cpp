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
    ll N,K;
    cin >> N >> K;
    vector<pair<ll, ll>> movies(N);
    for (ll i = 0; i < N; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(all(movies),[](pair<ll,ll> a, pair<ll,ll> b){
        return a.second < b.second;
    });
    dbg(movies);
    vector<ll> curr;
    ll watched = 0;
 
    for (ll i = 0; i < N; i++) {
        if (i < K) {
            curr.push_back(movies[i].second);
            watched++;
        } else {
            
            auto it = upper_bound(curr.rbegin(), curr.rend(), movies[i].first,
                       [](int a, int b){return a>=b;});
            if (it != curr.rend()) {
                curr.push_back(movies[i].second);
                curr.erase((++it).base());
                watched++;
            }
        }
        dbg(curr);
        
    }
    cout << watched;
}