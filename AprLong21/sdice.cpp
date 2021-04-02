#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t;
    cin>>t;

    while (t--){
        long long int n;
        cin>>n;

        long long int l = n / 4; //number of complete layer
        long long int t = n % 4; //number of tops

        long long int p5 = 0, p4 = 0, p3 = 0, p2 = 0, p = 0;
        switch(t){
            case 1: p5 = 1; break;
            case 2: p4 = 2; break;
            case 3: p4 = 2; p3 = 1; break;
        }

        if (l > 0){
            p2 = l * 4;
            p = (4 - t) * 4;
        }
        long long int sum;
        sum = (p2 * 11) + (p3 * 15) + (p4 * 18) + (p5 * 20) + p;
        cout<<sum<<endl;
    }
    return 0;
}
