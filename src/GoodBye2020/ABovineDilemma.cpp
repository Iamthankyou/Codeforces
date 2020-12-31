#include <bits/stdc++.h>
using namespace std;

double area(int xa, int ya, int xb, int yb, int xc, int yc){
	return 1.0/2*abs((xb-xa)*(yc-ya)-(xc-xa)*(yb-ya));
}

void solve() {
	set<int> s;
	int n = 0;
	cin >> n;
	int arr[n];
	int cnt[51];
	
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
//			cout << area(0,1,arr[i],0,arr[j],0) << endl;
			s.insert(abs(arr[i]-arr[j]));
		}
	}	
	
	cout << s.size()<< "\n";
}

int main(){
//	freopen("duy.in.cpp","r",stdin);	
	int t;
	cin >> t;

	while (t--){
		solve();
	}

}
