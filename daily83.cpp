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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        /*
        count total then divide by parts?
        assign a node to each bucket
        find total number of nodes
        if total is <= k simply return the pre-computation
        else find how minimum num of nodes which fit in each bucket
        increase size of node list in each bucket by 1 from left to right

        we start with buckets of size one? or buckets of min size
        */
        auto split = std::vector<ListNode*>(k, nullptr);
        if (head == nullptr)
            return split;

        auto total = 0;
        auto start = head;
        while (head != nullptr) {
            total++;
            head = head->next;
        }

        auto min_nodes = total / k;
        auto node_list_sizes = std::vector<int>(k, min_nodes);
        auto curr_total = min_nodes * k;
        auto index = 0;
        while (curr_total < total) {
            node_list_sizes[index]++;

            index = (index + 1) % k;
            curr_total++;
        }

        for (auto i = 0; i < k; ++i) {
            auto count = 1;
            auto curr_head = start;
            split[i] = curr_head;

            while (count < node_list_sizes[i] and start != nullptr) {
                // std::cout << "count is " << count << ", node is " << start->val << std::endl;
                ++count;
                start = start->next;
            }

            auto prev = start;
            if (prev != nullptr) {
                start = start->next;
                prev->next = nullptr;
            }
        }

        return split;
    }
};


// Solution 2

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

       vector<ListNode*>ans;

        ListNode* temp1 = head;
        ListNode* curr = head;
        int count = 0;

        while(temp1 != NULL)
        {
            count++;
            temp1 = temp1->next;
        }

        int i = count % k;
        int j = count / k;


        ListNode* temp = head;

        if(k <= count)
        {
            while(temp != NULL)
            {
                 ans.push_back(curr);
                 int l = 1;

                while(l<j && temp != NULL)
                {
                  
                    l++;
                    temp = temp->next;          
                }

                if(i>0)
                {
                    i--;
                    temp = temp->next;
                }
             
                if(temp == NULL)
                {
                    break;
                }

                curr = temp->next;
                temp->next = NULL;
                temp = curr;

            }

          

        }
        else{

            while(temp != NULL)
            {
                ans.push_back(curr);
                curr = temp->next;
                temp->next = NULL;
                temp = curr;
                k--;
            }

            while(k--)
            {
                ans.push_back(NULL);
            }
        }

        return ans;


        
    }
};
