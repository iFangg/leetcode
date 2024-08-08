// Solution 1
class Solution {
public:
    void merge_sort(vector<int>& A, vector<int>& B, int n) {
        copy(A, 0, n, B);
        split_merge(A, 0, n, B);
    }

    void split_merge(vector<int>& B, int begin, int end, vector<int>& A) {
        if (end - begin <= 1)
            return;
        
        int mid = (begin + end) / 2;
        split_merge(A, begin, mid, B);
        split_merge(A, mid, end, B);

        merge(B, begin, mid, end, A);
    }

    void merge(vector<int>& B, int begin, int mid, int end, vector<int>& A) {
        int i = begin;
        int j = mid;

        for (auto k = begin; k < end; ++k) {
            if (i < mid and (j >= end or A[i] <= A[j])) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
        }
    }

    void copy(vector<int>& A, int begin, int end, vector<int>& B) {
        for (auto k = begin; k < end; ++k) {
            B[k] = A[k];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        auto work = std::vector<int>(nums.size());
        merge_sort(nums, work, nums.size());
        return nums;
    }
};


