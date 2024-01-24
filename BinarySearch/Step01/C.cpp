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
        int l = -1;
        int r = n;
        while(r > l + 1){
            int mid = (l + r) / 2;
            if(nums[mid] < x){
                l = mid;
            } else{
                r = mid;
            }
        }
        cout << r + 1 << endl;
    }
    return 0;
}