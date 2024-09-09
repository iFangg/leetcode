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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        auto matrix = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
        int row = m;
        int col = n;
        
        int count = 0;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(head != nullptr) {
            //print starting row
            for(int index = startingCol; head != nullptr && index <= endingCol; index++) {
                matrix[startingRow][index] = head->val;
                head = head->next;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; head != nullptr && index <= endingRow; index++) {
                matrix[index][endingCol] = head->val;
                head = head->next;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; head != nullptr && index >= startingCol; index--) {
                matrix[endingRow][index] = head->val;
                head = head->next;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; head != nullptr && index >= startingRow; index--) {
                matrix[index][startingCol] = head->val;
                head = head->next;
            }
            startingCol++;
        }

        return matrix;
    }
};
