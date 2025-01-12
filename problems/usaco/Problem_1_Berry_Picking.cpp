#include <bits/stdc++.h>
#include <numeric>

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
    //setFile("berries");
    int N, K;
    cin >> N >> K;
    vector<int> trees(N);
    int maxTree = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        maxTree = max(maxTree, trees[i]);
    }
    sort(all(trees), greater<int>());

    int maxBessie = 0;

    for (int i = 1; i <= maxTree; i++) {
        vector<int> realArr;
        vector<int> currTrees = trees;
        vector<int> currSets;
        for (int j = 0; j < N; j++) {
            int possSets = currTrees[j] / i;
            currSets.push_back(possSets);
            currTrees[j] -= possSets * i;
        }
        vector<int> backUpSets;
        if (accumulate(currSets.begin(), currSets.end(), 0) < K) {
            sort(all(currTrees), greater<int>());
            for (int j = 0; j < N; j++) {
                backUpSets.push_back(currTrees[j]);
            }
        } 
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < currSets[j]; k++) {
                realArr.push_back(i);
            }
        }
        for (int i = 0; i < backUpSets.size(); i++) {
            realArr.push_back(backUpSets[i]);
        }
        sort(all(realArr), greater<int>());
        int bessie = 0;
        for (int i = (K/2); i < K; i++) {
            bessie += realArr[i];
        }
        maxBessie = max(maxBessie, bessie);
    }

    cout << maxBessie << endl;


}