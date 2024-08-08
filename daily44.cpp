// Solution 1 - FAIL
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // bucket sort? have a bucket for every 2 heights
            // with height 1, 2, 3 you can group 1-2, 2-3
        
        // options are:
            // place current book on the same shelf (if possible)
            // place current book on the next shelf down
            // take minimum height of these
        // dp - dp(i) = min height using up to the ith book
        // dp(i) = dp(i - 1) if within shelf width, or dp(i - 1) + book_i height if outside of shelf width
        // dp(0) = height of first book
        // dp(1) = min height of first + second book
        // keep track of min height, height of current shelf, width of current shelf
        auto dp = std::vector<std::tuple<int, int, int>>(books.size());
        dp[0] = std::make_tuple(books[0][1], books[0][1], books[0][0]);

        return std::get<0>(recurse(dp, books, shelfWidth, static_cast<int>(books.size() - 1)));
    }
 private:
    std::tuple<int, int, int> recurse(std::vector<std::tuple<int, int, int>>& dp, vector<vector<int>>& books, int shelfWidth, int curr_book) {
        if (curr_book == 0)
            return dp[0];
        
        auto prev = recurse(dp, books, shelfWidth, curr_book - 1);
        auto prev_height = get<0>(prev);
        auto width = get<2>(prev);
        auto same_shelf = 0;
        auto new_shelf = books[curr_book][1];

        if (width + books[curr_book][0] > shelfWidth) {
            same_shelf = new_shelf;
            width = books[curr_book][0];
        } else if (prev_height < books[curr_book][1]) {
            same_shelf = books[curr_book][1];
            width += books[curr_book][0];
        } else {
            width += books[curr_book][0];
        }

        dp[curr_book] = std::make_tuple(std::min(prev_height + same_shelf, prev_height + new_shelf), std::min(same_shelf, new_shelf), width);
        return dp[curr_book];
    }
}


// Solution 2
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // DP array to store the minimum height for each book
        vector<int> dp(books.size() + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= books.size(); ++i) {
            int width = 0, height = 0;

            // Try to place books[i-1], books[i-2], ..., books[0] on the same shelf
            for (int j = i; j > 0; --j) {
                width += books[j-1][0];
                if (width > shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }

        return dp[books.size()];
    }
};


