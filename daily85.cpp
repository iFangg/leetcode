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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        /*
        track prev and current nodes
        find gcd
            insert node with value gcd as nod after prev and before current
        */

        auto start = head;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            if (prev != nullptr) {
                ListNode* gcd_node = new ListNode(std::gcd(prev->val, head->val), head);
                prev->next = gcd_node;
            }

            prev = head;
            head = head->next;
        }

        return start;
    }
};


// Solution 2
 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        if (str.find(',') == string::npos) {
            cout << str;
            continue;
        }
        stringstream ss(str); ss.ignore();
        int prev; ss >> prev; ss.ignore();
        cout << '[' << prev;
        for (int curr; ss >> curr; ss.ignore()) {
            cout << ',' << gcd(prev, curr) << ',' << curr;
            prev = curr;
        }
        cout << ']';
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL)return head;
        ListNode * temp = head->next,*prev = head;
        while(temp!=NULL){
            int k = gcd(prev->val,temp->val);
            ListNode * newnode = new ListNode(k);
            newnode->next = temp;
            prev->next = newnode;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
