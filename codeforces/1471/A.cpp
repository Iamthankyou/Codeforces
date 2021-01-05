#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	int n,x; cin >> n >> x;
	ll ans1=0,ans2=0;
	
	for (int i=0; i<n; i++){
		int t; cin >> t;
		ans1+=t;
		ans2+=ceil((double)t/x);
//		cout << ceil((double)t/x);
	}
	
	ans1=ceil((double)ans1/x);
	
	cout << ans1 << " " << ans2 << "\n";
}

int main(){
//	freopen("duy.in.cpp","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	
	while (t--){
		solve();
	}
}