#include <bits/stdc++.h>
#include<queue>
using namespace std;

bool isSubsetExists(vector<int>arr, int sum, int k){
    int l = k, h = sum - k;
    int x = arr.size();
    bool mat[2][h + 1];

    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= h; j++){
            if (j == 0){
                mat[i % 2][j] = true;
            }
            else if (i == 0){
                mat[i % 2][j] = false;
            }
            else if (arr[i - 1] <= j){
                mat[i % 2][j] = mat[(i + 1) % 2][j - arr[i - 1]] || mat[(i+ 1) % 2][j];
            }
            else{
                mat[i % 2][j] = mat[(i + 1) % 2][j];
            }
        }

        int flag = 0;
        for (int i = 1; i <= h; i++){
            if (mat[x % 2][i]){
                flag = 1;
                break;
            }
        }

        if (flag == 1){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    int t;
    cin>>t;

    while (t--){
        int n, k;
        int input;
        cin>>n>>k;

        priority_queue<int>q;
        vector<int>arr;

        for (int i = 0; i < n; i++){
            cin>>input;
            q.push(input);
        }

        int flag = 0, sum = 0, j;
        while (!q.empty()&&flag==0){
            sum += q.top();
            arr.push_back(q.top());
            q.pop();

            if (sum >= 2 * k){
                if (isSubsetExists(arr, sum, k) == true){
                    cout<<arr.size()<<endl;
                    flag = 1;
                    break;
                }
                else{
                    continue;
                }
            }
        }

        if (flag == 0){
            cout<<"-1"<<endl;
        }
    }

    return 0;
}