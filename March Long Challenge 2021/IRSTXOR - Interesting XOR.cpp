#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;

    while(t--){
        ll c;
        cin>>c;

        ll temp = c;
        ll i=0;

        while(temp>0){
            temp = temp/2;
            i++;
        }

        ll a = pow(2, i - 1) - 1;
        ll b = a ^ c;

        cout<<a * b<<"\n";
    }
	
	return 0;
}
