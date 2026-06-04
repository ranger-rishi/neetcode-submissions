class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int half = (total + 1) / 2;
        int l = 0;
        int r = n;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int y = half - mid;
            
            int L1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int R1 = (mid == n) ? INT_MAX : nums1[mid];
            int L2 = (y == 0) ? INT_MIN : nums2[y - 1];
            int R2 = (y == m) ? INT_MAX : nums2[y];
            
            if (L1 <= R2 && L2 <= R1) {
                if (total % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
            } else if (L1 > R2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0.0;
    }
};