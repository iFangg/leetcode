// Solution 1
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return nodes_;
        
        for (auto& c : root->children) {
            postorder(c);
        }

        nodes_.push_back(root->val);
        return nodes_;
    }

private:
    std::vector<int> nodes_;
};

// Solution 2
class Solution {
public:

    void postorderTraversal(Node* node, std::vector<int>& res)
    {
        if (!node)
        {
            return;
        }

        for (auto n : node->children)
        {
            postorderTraversal(n, res);
        }

        res.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        std::vector<int> res;
        postorderTraversal(root, res);
        return res;
    }
};
