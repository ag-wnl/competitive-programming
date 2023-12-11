class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n-1;
        // as consider only n integers in array 1,2,3,4 -> then 4 elements will be smaller than equal to 4;
        // now if array has n+1 elements, one is repeated, for a number x: there will me > x numbers less than equal to x;
        // we need to find the smallest such number as our answer
        
        while(l < r) {
            int m = l + (r-l) / 2;
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(nums[i] <= m) cnt++;     
            }
            if(cnt <= m) l = m+1;
            else r = m;
        }
        return l;
    }
};
