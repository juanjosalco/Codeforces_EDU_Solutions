#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cin >> k;
    int closestToRight, closestToLeft;
    int l, r;
    for(int i = 0; i < k; i++){
        cin >> l >> r;
        int start = -1;
        int end = n;
        while(end > start + 1){
            int mid = (end + start) / 2;
            if(nums[mid] <= r){
                start = mid;
            } else{
                end = mid;
            }
        }
        closestToRight = end;
        start = -1;
        end = n;
        while(end > start + 1){
            int mid = (end + start) / 2;
            if(nums[mid] < l){
                start = mid;
            } else{
                end = mid;
            }
        }
        closestToLeft = start + 1;
        cout << closestToRight - closestToLeft << " ";
    }
    return 0;
}
