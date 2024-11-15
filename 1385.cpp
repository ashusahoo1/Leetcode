//1385. Find the Distance Value Between Two Arrays

#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for(auto&num : arr1){
            // Binary search to find the closest element
            auto it = lower_bound(arr2.begin(), arr2.end(), num);
            bool valid = true;
            // Check the closest higher or equal element
            if(it != arr2.end() && abs(*it - num) <= d){
                valid = false;
            }
            // Check the closest lower element
            if(it != arr2.begin() && std::abs(*(it - 1) - num) <= d) {
                valid = false;
            }
            if(valid==true){
                count++;
            }
        }

        return count;
    }
};
// logic for checking closest lower and closest higher 
<!-- Suppose arr1 = [3, 10] and arr2 = [1, 5, 9] with d = 2.
For num = 3 from arr1:
Closest Higher or Equal Element: The lower_bound function will find the smallest element in arr2 that is not less than num. Here, it will point to 5 because 5 is the first element in arr2 that is greater than or equal to 3.
Closest Lower Element: The element just before the lower_bound result, which is 1 in this case.
Now, the checks are:
Is abs(5 - 3) <= 2? Yes, so valid becomes false.
Is abs(1 - 3) <= 2? Yes, so valid remains false.
Since valid is false, 3 is not counted.
For num = 10 from arr1:
Closest Higher or Equal Element: lower_bound will point to the end of arr2 because all elements in arr2 are less than 10.
Closest Lower Element: The last element in arr2, which is 9.
Now, the checks are:
There is no higher or equal element within arr2 that is less than or equal to 10.
Is abs(9 - 10) <= 2? Yes, so valid becomes false.
Since valid is false, 10 is not counted. -->
