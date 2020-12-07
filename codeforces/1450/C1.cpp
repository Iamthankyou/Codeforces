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
	vector<string> v(n);

	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	char boards[3][n][n];

	for (int x=0; x<n; x++){
		for (int y=0; y<n; y++){
			for (int i=0; i<3; i++){
				boards[i][x][y] = v[x][y];
			}
		}
	}

	int changes[3];
	memset(changes,0,sizeof(changes));

	for (int x=0; x<n; x++){
		for (int y=0; y<n; y++){
			if (v[x][y]=='.'){
				continue;
			}
			changes[(x+y)%3]++;
			boards[(x+y)%3][x][y] = 'O';
		}
	}

	if (changes[0]<=changes[1]&&changes[0]<=changes[2]){
		for (int x=0; x<n; x++){
			for (int y=0; y<n; y++){
				cout << boards[0][x][y];
			}
			cout << "\n";
		}
	}
	else if (changes[1]<=changes[2]){
		for (int x=0; x<n; x++){
			for (int y=0; y<n; y++){
				cout << boards[1][x][y];
			}
			cout << "\n";
		}
	}
	else{
		for (int x=0; x<n; x++){
			for (int y=0; y<n; y++){
				cout << boards[2][x][y];
			}
			cout << "\n";
		}
	}


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

	#ifdef duy_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif

	int t;
	cin >> t;

	while (t--){
		solve();
	}
}
