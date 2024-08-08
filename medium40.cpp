// Solution 1
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort array by x_start
        // loop through finding all intersections
        // when x_start is strictly greater than our current upper bound
            // add 1 to arrows and reset bounds to x_start and x_end
        
        std::sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0])
                return a[1] < b[1];

            return a[0] < b[0];
        });

        auto arrows = 1;
        auto lo = points[0][0];
        auto hi = points[0][1];
        for (auto i = 1; i < points.size(); ++i) {
            if (hi < points[i][0]) {
                arrows++;
                lo = points[i][0];
                hi = points[i][1];
            }

            hi = std::min(hi, points[i][1]);
        }

        return arrows;
    }
};


// Solution 2
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();


const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
	constexpr std::size_t alignment = alignof(std::max_align_t); // Default maximum alignment
	size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
	size_t total_size = size + padding;
	char* aligned_ptr = &buffer[buffer_pos + padding];
	buffer_pos += total_size;
	return aligned_ptr;
}
void operator delete(void* ptr) {
}

// Overload the delete[] operator to do nothing
void operator delete[](void* ptr) {}

#include <execution>

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int nArrows = 1;
		vector<pair<int, int>> pointsPairs;
		pointsPairs.reserve(points.size());
    
		std::transform(points.begin(), points.end(), std::back_inserter(pointsPairs),
			[](const vector<int>& point) -> pair<int, int> {
				return { point[0], point[1] };
			});
		std::sort(std::execution::par,pointsPairs.begin(), pointsPairs.end(), [](pair<int, int>& lhs, pair<int, int>& rhs) {
			return lhs.second < rhs.second;
			});
    
		int end = pointsPairs[0].second;
		for (const auto& point: pointsPairs){
			if (end < point.first) {
				end = point.second;
				nArrows++;
			}
		}
		return nArrows;
	}
};
