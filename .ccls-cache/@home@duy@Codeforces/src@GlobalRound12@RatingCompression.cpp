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

#define duy_local

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void usaco(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

int arr[300000];
int st[4*300000];
int cnt[300000];

void update(int id ,int l, int r, int i, int v){
	if (i<l || r<i){
		return;
	}

	if (l==r){
		st[id] = v;
		return;
	}

	int mid = (l+r)/2;
	update(id*2,l,mid,i,v);
	update(id*2+1,mid+1,r,i,v);

	st[id] = min(st[id*2],st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
	if (v<l || r<u){
		return INT_MAX;
	}

	if (u<=l && r<=v){
		return st[id];
	}

	int mid = (l+r)/2;

	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void solve() {
	memset(arr,0,sizeof(arr));
	memset(st,0,sizeof(st));
	memset(cnt,0,sizeof(cnt));

	int n;
	cin >> n;
	int p=0;

	bool ans[n+1];
	memset(ans,false,sizeof(ans));

	for (int i=1; i<=n ;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
		update(1,1,n,i,arr[i]);
	}

	while (cnt[p+1]==1){
		p++;
	}

	ans[1] = p == n;

	ans[n] = cnt[1]>0;

	bool flag = true;

	if (ans[n]){
		int r =n,l=1;

		for (int i=1; i<=n; i++){
			if ((arr[r]==i || arr[l]==i)){
			 	if (arr[l]==i) l++;
				if (arr[r]==i) r--;

				int min2 = get(1,1,n,l,r);
				if (min2!=i+1 && min2!=INT_MAX){
					cout << i << " " << l << ":" << r << " " << min2 << " ";
					for (int j=2; j<=n-i+1; j++){
						ans[j]=false;
					}

					for (int j=n-i+2; j<=n; j++){
						ans[j]=true;
					}
					break;
				}
			}
			else{
				break;
			}

		}

	}


	for (int i=1; i<=n; i++){
		cout << ans[i];
	}

	cout << "\n";
}

int main(){
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
