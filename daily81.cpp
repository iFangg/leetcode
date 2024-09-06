// Solution 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        auto to_remove = std::unordered_set<int>(nums.begin(), nums.end());
        auto curr = head;
        ListNode* prev = nullptr;
        auto new_head = head;
        while (curr != nullptr) {
            auto replaced = false;
            if (to_remove.contains(curr->val)) {
                replaced = true;
                if (prev == nullptr) {
                    new_head = curr->next;
                } else {
                    if (prev == new_head)
                        new_head->next = curr->next;

                    prev->next = curr->next;
                }
            }

            if (!replaced)
                prev = curr;
            curr = curr->next;
        }

        return new_head;
    }
};


// Solution 2
class Solution {
public:
    ListNode* modifiedList(vector<int>& excludeValues, ListNode* head) {
        bitset<100001> excludeSet; 
        for (int val : excludeValues) {
            excludeSet.set(val);
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        
        while (curr->next) {
            if (excludeSet[curr->next->val]) {
                curr->next = curr->next->next;  
            } else {
                curr = curr->next;  
            }
        }
        
        return dummy.next;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
