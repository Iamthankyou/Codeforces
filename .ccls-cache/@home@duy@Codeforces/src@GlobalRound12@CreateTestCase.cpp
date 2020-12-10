#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("duy.input","w",stdout);

	int const n = 10;

	cout << 1 << "\n" << n << "\n";

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << "[" << i%3 << "]" ;
		}
		cout << "\n";
	}
}
