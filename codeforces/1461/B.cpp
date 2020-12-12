#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

#define duy_online

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void usaco(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

int min(int a, int b, int c){
	return a<b&&a<c?a:b<c?b:c;
}

void solve() {
	int n, m; cin>>n>>m;
       int dp[n+2][m+2];
       memset(dp,0,sizeof(dp));
       bool block[n+2][m+2];
       for(int i=1;i<=n;i++) {
           for (int j=1; j<=m; j++) {
               char ch; cin>>ch;
               if (ch=='*') block[i][j]=1;
               else block[i][j]=0;
           }
       }
       ll ans=0;
       for (int i = n; i>=1; i--) {
           for (int j = m; j>=1; j--) {
               if (!block[i][j]) continue;
               dp[i][j]=block[i][j]+min(dp[i+1][j],dp[i+1][j-1], dp[i+1][j+1]);
               ans+=dp[i][j];
           }
       }
       cout<<ans<<"\n";
  }

int main() {
	#ifdef duy_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif

// Fast << >>
	send help

	#ifdef duy_local
		usaco("duy");
	#endif

	int t;
	cin >> t;
	while (t--){
		solve();
	}

	#ifdef duy_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}
