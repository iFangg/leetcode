// Solution 1
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        auto intersect = std::vector<int>{};
        int i = 0;
        int j = 0;
        while (i < nums1.size() and j < nums2.size()) {
            std::cout << "start: " << nums1[i] << ", other: " << nums2[j] << "\n";
            if (nums1[i] == nums2[j]) {
                intersect.push_back(nums1[i]);
                ++i;
                ++j;
            } 
            else if (nums1[i] < nums2[j])
                ++i;
            else
                ++j;
        }

        return intersect;
    }
};
