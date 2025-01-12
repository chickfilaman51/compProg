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
    //setFile("split");
    int N;
    cin >> N;
    vector<pair<ll,ll>> A(N);
    map<ll,ll> possX;
    map<ll,ll> possY;
    ll minX = INF;
    ll minY = INF;
    ll maxX = 0;
    ll maxY = 0;
    vector<ll> xVals;
    vector<ll> yVals;

    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        minX = min(minX, A[i].first);
        minY = min(minY, A[i].second);
        maxX = max(maxX, A[i].first);
        maxY = max(maxY, A[i].second);
    }

    for (int i = minX; i <= maxX; i++) {
        possX[i] = 0;
    }
    for (int i = minY; i <= maxY; i++) {
        possY[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        possX[A[i].first]++;
        possY[A[i].second]++;
    }

    for (int i = minX; i <= maxX; i++) {
        if (possX[i] == 0) {
            xVals.push_back(i);
        }   
    }
    for (int i = minY; i <= maxY; i++) {
        if (possY[i] == 0) {
            yVals.push_back(i);
        }
    }

    sort(all(A));

    
    vector<pair<pair<ll,ll>,pair<ll,ll>>> minMaxesX(maxX-minX+1);
    vector<pair<pair<ll,ll>,pair<ll,ll>>> minMaxesY(maxY-minY+1);
    minMaxesX[i-minX] = {{INF,0},{INF,0}};
    for (int i = minX; i <= maxX; i++) {
        minMaxesX[i-minX] = {{INF,0},{INF,0}};
    }

    

}