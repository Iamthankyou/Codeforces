#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int deg[n+1];
	int w[n+1];
	
	for (int i=1; i<=n; i++){
		cin >> w[i];
		deg[i]=0;
	}
	
	for (int i=1; i<n; i++){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	
	long long ans= 0;
	vector<int> toSort;
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<deg[i]; j++){
			toSort.push_back(-w[i]);
		}
		ans+=w[i];
	}
	
	sort(toSort.begin(),toSort.end());
	
	for (auto &v:toSort){
		cout << ans << " ";
		ans+=-v;
	}	
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
//	freopen("duy.in.cpp","r",stdin);
	int t = 0;
	cin >> t;
	
	while (t--){
		solve();
	}
}