// Solution 1
#include <queue>
#include <vector>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums)
    : kth_{k} {
        for (auto& n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        numbers_.push(val);

        if (numbers_.size() > kth_) {
            numbers_.pop();
        }

        return numbers_.top();
    }

private:
    int kth_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> numbers_;
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

