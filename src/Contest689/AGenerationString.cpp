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
		int k,n;
		cin >> n >> k;

		for (int i=0; i<n; i++){
			if (i%3==0){
				cout << 'a';
			}
			else if (i%3==1){
				cout << 'b';
			}
			else{
				cout << 'c';
			}
		}

		cout << "\n";
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
