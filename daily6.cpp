// Solution 1
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        auto max_len = int{0};
        auto left = int{0};
        auto right = int{0};
        auto max_dq = std::deque<int>{};
        auto min_dq = std::deque<int>{};
        while (right < nums.size() and left <= right) {
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[right])
                max_dq.pop_back();
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right])
                min_dq.pop_back();
                
            max_dq.push_back(right);
            min_dq.push_back(right);
            
            if (nums[max_dq.front()] - nums[min_dq.front()] <= limit) {
                max_len = std::max(max_len, right - left + 1);

                right++;
            }
            else {
                left++;
                if (!max_dq.empty() && max_dq.front() < left)
                    max_dq.pop_front();
                if (!min_dq.empty() && min_dq.front() < left)
                    min_dq.pop_front();
            }
        }

        return max_len;
    }
}


// Solution 2
#pragma GCC optimize("O3","unroll-loops")
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        // if the diff between the max and min element of an subarray < k then all other 
        // elements' diff is also < k
        int n = nums.size();
        if(nums.size()==0)return 0;
        // we will keep queue to track the index of max and min element in current window 
        // q1 will track max and subsequent index value will decrease 
        // q2 will track min and subsequent index value will increase 
        deque<int>q1,q2;   
        int i=0,j=0,ans=0;
        while(j<n){
            // to maintain order - if new element is greater than last element 
            // remove last and insert current element in q1  vice versa for q2
            while(!q1.empty() && nums[q1.back()]<nums[j])q1.pop_back();
            while(!q2.empty() && nums[q2.back()]>nums[j])q2.pop_back();
            q1.push_back(j);
            q2.push_back(j);
            while(!q1.empty() && !q2.empty() &&
             (nums[q1.front()] - nums[j]>limit || nums[j]-nums[q2.front()]>limit)){
                if(nums[q1.front()] - nums[j]>limit){
                    i= max(i,q1.front()+1);
                    q1.pop_front();
                }
                if(nums[j]-nums[q2.front()]>limit){
                    i= max(i,q2.front()+1);
                    q2.pop_front();
                }
             }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
