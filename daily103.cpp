// Solution 1 - FAIL
class MyCircularDeque {
public:
    MyCircularDeque(int k)
    : max_size_{k},
    curr_size_{0},
    dq_{},
    head_{std::make_pair(-1, -1)},
    tail_{std::make_pair(-1, -1)},
    empty_{true},
    full_{false} {
        dq_ = std::vector<int>(k, -1);
    }
    
    bool insertFront(int value) {
       return insert_value(true, value);
    }
    
    bool insertLast(int value) {
        return insert_value(false, value);
    }
    
    bool deleteFront() {
        return delete_value(true);
    }
    
    bool deleteLast() {
        return delete_value(false);
    }
    
    int getFront() {
        return head_.second;
    }
    
    int getRear() {
        return tail_.second;  
    }
    
    bool isEmpty() {
        return empty_;
    }
    
    bool isFull() {
        return full_;
    }

private:
    bool insert_value(bool front, int value) {
        if (isFull())
            return false;
        
        if (curr_size_ == 0) {
            head_ = std::make_pair(0, value);
            tail_ = std::make_pair(0, value);
        }

        auto current = value;
        auto index = head_.first;
        int dir = 1;
        
        if (!front) {
            index = tail_.first;
            dir = -1;
        }

        for (auto i = 0; i < max_size_; ++i) {
            auto temp = dq_[index];
            if (temp != -1) {
                dq_[index] = value;
                current = temp;
            }

            index = (index + dir + max_size_) % max_size_;
        }

        empty_ = false;
        curr_size_++;
        if (curr_size_ == max_size_)
            full_ = true;
        return true;
    }

    bool delete_value(bool front) {
        if (isEmpty())
            return false;
        
        auto index = head_.first;
        int dir = 1;
        dq_[index] = -1;

        if (!front) {
            index = tail_.first;
            dir = -1;
        }

        index = (index + dir + max_size_) % max_size_;
        for (auto i = 0; i < max_size_; ++i) {
            if (dq_[index] == -1) {
                index = (index + dir + max_size_) % max_size_;
                continue;
            }
            

            break;
        }

        if (front) {
            head_.first = index;
            head_.second = dq_[index];
        } else {
            tail_.first = index;
            tail_.second = dq_[index];
        }
        
        curr_size_--;

        if (curr_size_ == 0) {
            head_ = tail_ = std::make_pair(-1, -1);
            empty_ = true;
        }
        
        if (isFull())
            full_ = false;

        return true;
    }

    int max_size_;
    int curr_size_;
    
    std::vector<int> dq_;
    std::pair<int, int> head_;
    std::pair<int, int> tail_;

    bool empty_;
    bool full_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */


// Solution 2
class MyCircularDeque {
public:
    MyCircularDeque(int k)
    : max_size_{k},
    curr_size_{0},
    dq_(k, -1),
    head_{0},
    tail_{k - 1},  // Initialize tail to the last index
    empty_{true},
    full_{false} {
    }
    
    bool insertFront(int value) {
       return insert_value(true, value);
    }
    
    bool insertLast(int value) {
        return insert_value(false, value);
    }
    
    bool deleteFront() {
        return delete_value(true);
    }
    
    bool deleteLast() {
        return delete_value(false);
    }
    
    int getFront() {
        return isEmpty() ? -1 : dq_[head_];
    }
    
    int getRear() {
        return isEmpty() ? -1 : dq_[tail_];
    }
    
    bool isEmpty() {
        return empty_;
    }
    
    bool isFull() {
        return full_;
    }

private:
    bool insert_value(bool front, int value) {
        if (isFull())
            return false;
        
        if (front) {
            head_ = (head_ - 1 + max_size_) % max_size_;
            dq_[head_] = value;
        } else {
            tail_ = (tail_ + 1) % max_size_;
            dq_[tail_] = value;
        }

        empty_ = false;
        curr_size_++;
        full_ = (curr_size_ == max_size_);
        return true;
    }

    bool delete_value(bool front) {
        if (isEmpty())
            return false;
        
        if (front) {
            dq_[head_] = -1;
            head_ = (head_ + 1) % max_size_;
        } else {
            dq_[tail_] = -1;
            tail_ = (tail_ - 1 + max_size_) % max_size_;
        }

        curr_size_--;
        empty_ = (curr_size_ == 0);
        if (empty_) {
            head_ = 0;
            tail_ = max_size_ - 1;
        }
        full_ = false;
        return true;
    }

    int max_size_;
    int curr_size_;
    std::vector<int> dq_;
    int head_;
    int tail_;
    bool empty_;
    bool full_;
};
