
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>

int power(int a, int d, int n) {
    int result = 1;
    a = a % n;
    while (d > 0) {
        if (d & 1)
            result = (__int128)result * a % n;
        a = (__int128)a * a % n;
        d >>= 1;
    }
    return result;
}

bool millerTest(int d, int n, int a) {
    int x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (__int128)x * x % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}

bool isPrime(int n) {
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0)
        return false;

    // Write n-1 as d*2^r
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Deterministic bases for 64-bit integers
    int bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (int a : bases) {
        if (a >= n) break;
        if (!millerTest(d, n, a))
            return false;
    }
    return true;
}

int solve(int n){

    int first = 0;
    int second = 0;

    for(int i = n + 1 ; i < (n+1)*(n+1) ;i++ ) {
        if(isPrime(i)){
            first = i ;
            break ;
        }
    }

    for(int i = first + n ; i < (first + n)*(first + n) ;i++ ){
        if(isPrime(i)){
            second = i;
            break ;
        }
    }

    return (1*first*second);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        cout << solve(n)<< "\n";
    }

    return 0;
}

