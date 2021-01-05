#include <bits/stdc++.h>
using namespace std;
using ll= long long;

void solve(){
	int n,x; cin >> n >> x;
	queue<pair<int,int>> q;
	
	for (int i=0; i<n; i++){
		int t; cin >> t;
		q.push(make_pair(t,1));
	}
	
	ll ans=0;
	
	while (!q.empty() && q.front().first%x==0){
		ans+=q.front().first*q.front().second;
		q.push(make_pair(q.front().first/x,q.front().second*x));
		q.pop();
	}
	
	while (!q.empty()){
		ans+=q.front().first*q.front().second;
		q.pop();
	}
	
	cout << ans << "\n";
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