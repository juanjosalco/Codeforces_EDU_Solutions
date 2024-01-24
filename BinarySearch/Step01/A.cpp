#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        bool found = false;
        while(r >= l){
            int mid = (l + r) / 2;
            if(nums[mid] == x){
                found = true;
                break;
            } else if( nums[mid] < x){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        if(found){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}