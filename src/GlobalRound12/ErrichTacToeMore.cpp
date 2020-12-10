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

#define duy_local

void solve() {
	int n;
	cin >> n;
	vector<string> v(n);

	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	char boardsO[3][n][n];
	char boardsX[3][n][n];

	char boardsOO[3][n][n];
	char boardsXX[3][n][n];

	for (int x=0; x<n; x++){
		for (int y=0; y<n; y++){
			for (int i=0; i<3; i++){
				boardsX[i][x][y] = v[x][y];
				boardsO[i][x][y] = v[x][y];

				boardsXX[i][x][y] = v[x][y];
				boardsOO[i][x][y] = v[x][y];
			}
		}
	}

	int changesX[3];
	int changesO[3];

	int changesXX[3];
	int changesOO[3];

	int k = 0;

	memset(changesX,0,sizeof(changesX));
	memset(changesO,0,sizeof(changesO));
	memset(changesXX,0,sizeof(changesX));
	memset(changesOO,0,sizeof(changesO));

	for (int x=0; x<n; x++){
		for (int y=0; y<n; y++){
			if (v[x][y]=='.'){
				continue;
			}

			if (v[x][y]=='X'){
				changesO[(x+y)%3]++;
				boardsO[(x+y)%3][x][y] = 'O';

				changesOO[x%3]++;
				boardsOO[x%3][x][y] = 'O';

			}
			else{
				changesX[(x+y)%3]++;
				boardsX[(x+y)%3][x][y] = 'X';

				changesXX[x%3]++;
				boardsXX[x%3][x][y] = 'X';
			}

			k++;
		}
	}

	int minChanges = INT_MAX;

	int i1,j1,ii1,jj1;

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			for (int ii=0; ii<3; ii++){
				for (int jj=0; jj<3; jj++){
					if (i==j || ii==jj){
						continue;
					}

					if (changesO[i]+changesX[j]+changesOO[ii]+changesXX[jj]<=(int)k){
						if (changesO[i]+changesX[j]+changesOO[ii]+changesXX[jj]<minChanges){
							i1=i;
							j1=j;
							ii1=ii;
							jj1=jj;
						}
						minChanges = min(minChanges,changesO[i]+changesX[j]+changesOO[ii]+changesXX[jj]);
					}
				}
			}
		}
	}

	cout << minChanges << " " << i1 << " " << j1 << " " << ii1 << " " << jj1 << "\n";

	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			for (int ii=0; ii<3; ii++){
				for (int jj=0; jj<3; jj++){
					if (i==j || ii==jj){
						continue;
					}

					if (changesO[i]+changesX[j]+changesOO[ii]+changesXX[jj]==minChanges){
						for (int x=0; x<n; x++){
							for (int y=0; y<n; y++){
								if (v[x][y]=='.'){
									cout << ".";
								}
								else if ((x+y)%3==i && x%3!=ii && x%3!=jj){
									cout << boardsO[(x+y)%3][x][y];
								}
								else if ((x+y)%3==j && x%3!=ii && x%3!=jj){
									cout << boardsX[(x+y)%3][x][y];
								}
								else if (x%3==ii){
									cout << boardsOO[(x+y)%3][x][y];
								}
								else if (x%3==jj){
									cout << boardsXX[(x+y)%3][x][y];
								}
								else{
									cout << v[x][y];
								}
							}
							cout << "\n";
						}
						return;
					}
				}
			}
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
