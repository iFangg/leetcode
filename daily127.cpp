// Solution 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        /*
        have hashmap for each level of tree
        calculate all nodes
            and then sums after all nodes have been processed?
        
        store sums in a max heap
        */
        level_sums = std::unordered_map<long long, long long>{};
        bfs(root, 0);

        auto heap = std::priority_queue<long long>{};

        for (auto& [l, v] : level_sums) {
            heap.push(v);
        }

        long long res = -1;
        for (auto i = 0; i < k; ++i) {
            if (heap.empty())
                return -1;
            
            res = heap.top();
            heap.pop();
        }

        return res;
    }

private:
    void bfs(TreeNode* node, int lvl) {
        if (node == nullptr)
            return;

        if (!level_sums.contains(lvl))
            level_sums[lvl] = 0;
        
        level_sums[lvl] += node->val;
        bfs(node->left, lvl + 1);
        bfs(node->right, lvl + 1);
    }

    std::unordered_map<long long, long long> level_sums;
};


// Solution 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
		std::vector< std::int64_t > levelSums;
		int64_t maxSum = std::numeric_limits< int64_t >::min();
		int maxSumLevel = INT_MAX;
		
		if( root == nullptr )
			return 0;
		
		std::queue< TreeNode *> q;	// BFS
		q.push( root );
		
		int currentLevel = 1;
		while( not q.empty() ) {
			
			// Sum all the nodes on the current level
			int64_t levelSum = 0;
			
			auto pending = q.size();
			while( pending-- ) {
				
				auto *node = q.front();
				q.pop();
				
				levelSum += node->val;
				
				if( node->left )
					q.push( node->left );
				if( node->right )
					q.push( node->right );
			}
			
			levelSums.emplace_back( levelSum );
			
			++currentLevel;
		}
		
		if( levelSums.size() < k )
			return -1;
		
		std::nth_element(
			levelSums.begin(),
			levelSums.begin() + (k-1),
			levelSums.end(),
			std::greater<>()
		);
		
		auto kth = *(levelSums.begin() + k-1);
		return kth;
    }
};
