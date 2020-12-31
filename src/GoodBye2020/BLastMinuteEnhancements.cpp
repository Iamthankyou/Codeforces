#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int> s;
	
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		
		if (s.count(t)){
			s.insert(t+1);
		}
		s.insert(t);
	}
	
	cout << s.size() << "\n";
}
int main(){
//	freopen("duy.in.cpp","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--){
		solve();
	}
}
