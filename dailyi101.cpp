// Solution 1
class MyCalendar {
public:
    MyCalendar()
    : bookings_{} {}
    
    bool book(int start, int end) {
        auto booking = std::make_pair(start, end);
        for (auto& b : bookings_) {
            if (end <= b.first)
                continue;
            
            if (start >= b.second)
                continue;
            
            return false;
        }

        bookings_.push_back(booking);

        return true;
    }

private:
    std::vector<std::pair<int, int>> bookings_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 make matrix for start and end times?
 keep track of existing start and ending times
 */

// Solution 2
char speedUp = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'z';
}();

class MyCalendar {
    struct Node {
        int start, end;
        Node(int start, int end) : start(start), end(end) {}
        bool operator<(const Node& other) const { return other.start >= end; }
    };
    set<Node> s;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = s.lower_bound({start, end});
        if (it != s.end() && it->start < end)
            return false;
        s.insert({start, end});
        return true;
    }
};
