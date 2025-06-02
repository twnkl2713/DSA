#include<iostream>
using namespace std;

int helper(int mid, int n, int m){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * mid;
        if(ans > mid) return 2;
    }
    if(ans == mid) return 1;
    return 0;
}

int NthRoot(int n, int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = low + (high - low) / 2; 
        int midN = helper(mid, n, m);
        if(midN == -1) return mid;
        else if(midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    int n, m;
    cout << "Enter the root (n) and the number (m): ";
    cin >> n >> m;

    int result = NthRoot(n, m);
    if(result == -1)
        cout << "No integer " << n << "th root for " << m << endl;
    else
        cout << "The " << n << "th root of " << m << " is: " << result << endl;

    return 0;
}
