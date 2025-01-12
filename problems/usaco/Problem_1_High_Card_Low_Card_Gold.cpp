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
    //setFile("cardgame");
    int N;
    cin >> N;
    vector<int> elsie(N);
    vector<int> bessie;
    for (int i = 0; i < N; i++) {
        cin >> elsie[i];
    }
    for (int i = 1; i <= 2 * N; i++) {
        if (find(elsie.begin(), elsie.end(), i) == elsie.end()) {
            bessie.push_back(i);
        }
    }
    sort(all(bessie));
    
    vector<int> upperBessie(N/2);
    vector<int> lowerBessie(N/2);
    for (int i = 0; i < (N/2); i++) {
        lowerBessie[i] = bessie[i];
        upperBessie[i] = bessie[i + (N/2)];
    }
    int score = 0;
    
    for (int i = 0; i < N; i++) {
        if (i >= (N/2)) {
            for (int j = 0; j < (int)lowerBessie.size(); j++) {
                if (elsie[i] > lowerBessie[j]) {
                    score++;
                    lowerBessie.erase(lowerBessie.begin() + j);
                    break;
                } else {
                    lowerBessie.erase(lowerBessie.begin());
                }
            }
        } else {
            for (int j = 0; j < (int)upperBessie.size(); j++) {
                if (elsie[i] < upperBessie[j]) {
                    score++;
                    upperBessie.erase(upperBessie.begin() + j);
                    break;
                } else {
                    upperBessie.erase(upperBessie.begin());
                }
            }
            
        }
        
    }
    cout << score;
}
