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
    ListNode* mergeNodes(ListNode* head) {
        auto zeroes = std::vector<int>{};
        auto total = int{0};
        auto new_head = new ListNode();
        auto prev = new ListNode();
        auto merged = 0;
        while (head != nullptr) {
            if (head->val == 0) {
                zeroes.push_back(0);
                if (zeroes.size() == 2) {
                    zeroes.clear();
                    zeroes.push_back(0);
                    // std::cout << total << std::endl;
                    auto node = new ListNode(total);
                    if (new_head->val == 0) {
                        new_head = node;
                    }
                    prev->next = node;
                    prev = prev->next;
                    if (merged == 1) {
                        new_head->next = prev;
                    }

                    merged++;
                    total = 0;
                }
            } else
                total += head->val;

            head = head->next;
        }

        return new_head;
    }
};


// Solution 2
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ret = nullptr;
        ListNode* curr = nullptr;
        int sum = 0;
        while(head != nullptr){
            if(head->val == 0){
                if(sum == 0){
                    head = head->next;
                    continue;
                }
                ListNode* node = new ListNode(sum);
                if(curr == nullptr){
                    curr = node;
                    ret = node;
                    head = head->next;
                    sum = 0;
                    continue;
                }
                curr->next = node;
                curr = node;
                head = head->next;
                sum = 0;
                continue;
            }
            int x = head->val;
            sum = sum + x;
            head = head->next;
        }

        return ret;
    }
};
