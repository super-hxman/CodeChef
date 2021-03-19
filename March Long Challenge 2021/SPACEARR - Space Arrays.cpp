#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;

  while (t--){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++){
      cin>>arr[i];
    }

    sort(arr, arr+n);

    int count = 0;
    int p = 0;
    for (int i = 0; i < n; i++){
      if (i + 1 - arr[i] < 0){
        p = 1;
        break;
      }
      count += i + 1 - arr[i];
    }

    if (p == 1){
      cout<<"Second"<<endl;
    }
    else{
      if (count % 2 == 1){
        cout<<"First"<<endl;
      }
      else{
        cout<<"Second"<<endl;
      }
    }
  }
  return 0;
}
