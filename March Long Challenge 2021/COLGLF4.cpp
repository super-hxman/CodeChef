#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int minv(long long int x, long long int y){
    if ( x < y){
        return x;
    }
    return y;
}

long long int maxv(long long int x, long long int y){
    if (x > y){
        return x;
    }
    return y;
}

long long int magic(long long int n, long long int e, long long int h, long long int a, long long int b, long long int c){
    if (n <= 0){
        //no orders
        return 0;
    }
    
    //initialise to maximum value
    long long int ans = 1e15;

    //cost if all orders are cakes
    if ((n <= e) && (n <= h)){
        ans = minv(ans, n*c);
    }

    //cost if all the orders are milkshakes
    if (3*n <= h){
        ans = minv(ans, n*b);
    }

    //cost if all orders are omlettes
    if (2*n <= e){
        ans = minv(ans, n*a);
    }

    /*
    milkshake and cake only
    let milkshake be x --> x milkshake and (n - x) cakes
    milkshake:  3x + (n - x) <= h
                x <= (h - n) / 2    | x is at least 1
                (h - n) / 2 >= 1
    cakes:      n - x <= e
                x >= n - e | x = (h - n) / 2
                (h - n) / 2 >= n - e
    */
    if (((h - n) / 2 >= 1) && ((h - n) / 2 >= n - e)){
        /*
        price   = (xb) + ((n - x)c)
                = x(b - c) + nc
        */

        //if (b - c) < 0 ; price will decrease as x increases
        //=> max value of x
        if ((b - c) < 0){
            long long int temp = minv(n - 1, (h - n) / 2);
            ans = minv(ans, (b - c) * temp + n * c);
        }

        //if (b - c) > 0 ; price will decrease as x decreases
        //=> min value of x
        else{
            long long int temp = maxv(1, n - e);
            ans = minv(ans, (b - c) * temp + n * c);
        }        
    }

    /*
    omlette and chocolate cakes
    let omlette be x --> x omlette and (n - x) cakes
    eggs: 2x + (n - x) <= 2 ==> x <= (e - n)
    bars: n - x < h ==> x >= n - h

    x should be in range of 1 to n - 1
    therefore :
    */
    if (e - n >= 1 && e - n >= n - h){
        /*
        price   = xa + (n - x)c
                = (a - c)x + nc
        */

        //if (a-c) < 0 ; price decreases as x increases
        //=> max value of x
        if (a - c < 0){
            long long temp = minv(n - 1, e - n);
            ans = minv(ans, (a- c) * temp + n * c);
        }

        //if (a - c) > 0 ; price decreases as x decreases
        //=> min value of x
        else{
            long long temp = maxv(1, n- h);
            ans = minv(ans, (a - c) * temp + n * c);
        }
    }

    //omlette and milkshake
    if ((e/2 >= 1) && (e/2 >= (3 * n - h + 2) / 3)){
        if (a - b < 0){
            long long int temp = minv(n - 1, e/2);
            ans = minv(ans, (a - b) * temp + n * b);
        }
        else{
            long long int temp = maxv(1, (3*n - h + 2)/ 3);
            ans = minv(ans, (a - b) * temp + n * b);
        }
    }

    //omlette, milkshake and cake
    if ((e >= 3) && (h >= 4) && (n >= 3)){
        ans = minv(ans, a + b + c + magic(n - 3, e - 3, h - 4, a, b, c));
    }

    return ans;
}


int main(){
    long long t;
    cin>>t;

    while (t--){
        long long int n;    //number of orders
        long long int e;    //number of eggs left
        long long int h;    //number of chocolate bars left
        long long int a;     //price of omlette
        long long int b;     //price of chocolate milkshake
        long long int c;     //price of chocolate cake

        cin>>n>>e>>h>>a>>b>>c;

        long long int ans;
        ans = magic(n, e, h, a, b, c);

        if (ans == 1e15){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}


