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

void solve() {
	int n;
	cin >> n;
	int cnt[n+5];
	memset(cnt,0,sizeof(cnt));
	int arr[n];

	for (int i=0; i<n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	ull ans = 0;

	for (int i=0; i<n+2; i++){
		ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
		ans+=cnt[i]*cnt[i+1]*cnt[i+2];
		ans+=cnt[i]*cnt[i+1]*(cnt[i+1]-1)/2;
		ans+=cnt[i]*(cnt[i]-1)/2*cnt[i+1];
		ans+=cnt[i]*cnt[i+2]*(cnt[i+2]-1)/2;
		ans+=cnt[i]*(cnt[i]-1)/2*cnt[i+2];
	}

	cout << ans << "\n";
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
