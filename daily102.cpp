// Solution 1 - FAIL
class MyCalendarTwo {
public:
    MyCalendarTwo()
    : double_bookings_{},
    booking_ids_{},
    bookings_{},
    id_{0} {}

    bool book(int start, int end) {
        auto booking = std::make_tuple(id_, start, end);
        std::cout << "current booking is: " << id_ << ", " << start << " - " << end << std::endl;

        for (auto& b : bookings_) {
            auto& id = std::get<0>(b);
            auto& b_first = std::get<1>(b);
            auto& b_sec = std::get<2>(b);

            if (b_first >= end)
                continue;
            
            if (b_sec <= start)
                continue;
            
            std::cout << "booking is: " << id << ", " << b_first << " - " << b_sec << std::endl;
            std::cout << "is overlapping\n";
            
            if (double_bookings_.contains(id)) {
                std::cout << "triple booked!\n";
                return false;
            }

            double_bookings_[id] = id_;
        }

        bookings_.push_back(booking);
        id_++;
        return true; 
    }

private:
    std::unordered_map<long long, long long> double_bookings_;
    std::unordered_set<long long> booking_ids_;
    std::vector<std::tuple<long long, int, int>> bookings_;
    long long id_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 *
   

// Solution 2
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (const auto& interval : overlaps) {
            if (interval.first < end && start < interval.second) {
                return false; // Triple booking
            }
        }
        
        for (const auto& interval : bookings) {
            if (interval.first < end && start < interval.second) {
                overlaps.emplace_back(std::max(start, interval.first), std::min(end, interval.second));
            }
        }
        
        bookings.emplace_back(start, end);
        return true;
    }

private:
    std::vector<std::pair<int, int>> bookings;
    std::vector<std::pair<int, int>> overlaps;
};
