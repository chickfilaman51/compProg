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
   
    ll N, M, R;
    cin >> N >> M >> R;
    vector<ll> cows(N);
    vector<pair<ll,ll>> stores(M);
    vector<ll> rents(R);
 
    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }
    
    for (ll i = 0; i < M; i++) {
        cin >> stores[i].first >> stores[i].second;
    }
    
    for (ll i = 0; i < R; i++) {
        cin >> rents[i];
    }
    
    while (rents.size() < N) {
        rents.push_back(0);
    }

    
    sort(all(cows), greater<ll>());
    sort(stores.begin(), stores.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second > b.second;
    });
    sort(all(rents));
    
    ll cutoff = 0;
    ll total = 0;
    for (ll i = 0; i < N; i++) {
        
        ll potentialGain = 0;
        vector<pair<ll,ll>> storesCopy = stores;
        while (cows[i] > 0) {
            if (storesCopy.size() == 0) {
                break;
            }
            if (storesCopy[0].first == 0) {
                storesCopy.erase(storesCopy.begin());
                continue;
            }
            if (storesCopy[0].first > cows[i]) {
                potentialGain += cows[i] * storesCopy[0].second;
                storesCopy[0].first -= cows[i];
                cows[i] = 0;
            } else {
                potentialGain += storesCopy[0].first * storesCopy[0].second;
                cows[i] -= storesCopy[0].first;
                storesCopy.erase(storesCopy.begin());
            }
        }
        if (potentialGain > rents[i]) {
            stores = storesCopy;
            total += potentialGain;
        } else {
            cutoff = i;
            break;
        }
    }

    for (ll i = cutoff; i < N; i++) {
        total += rents[i];
    }
    cout << total;
}  
