#include <bits/stdc++.h>
using namespace std;

void solve(){
	queue<pair<int,int>> q;
	int w,h,n;
	cin >> w >> h >> n;
	
	int t=1;
	
	while (w%2==0){
		t*=2;
		w/=2;
	}
	
	
	while (h%2==0){
		t*=2;
		h/=2;
	}
	
	if (n<=t){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	
}

int main(){
//	freopen("duy.in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	while (t--){
		solve();
	}
}
