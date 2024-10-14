// Solution 1
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        /*
        make max heap of nums
        pop top, add to score, replace number and push back to heap
        return total score
        */
        auto heap = std::priority_queue<long long>{};

        for (auto& n : nums) {
            heap.push(n);
        }

        long long score = 0;

        for (auto i = 0; i < k; ++i) {
            // check if heap is empty?
            long long n = heap.top();
            heap.pop();

            score += n;
            heap.push(std::ceil(static_cast<double>(n) / 3));
        }

        return score;
    }
};


// Solution 2
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        priority_queue<pair<int,int>> pq;
        long long ans = 0;
        int lim = nums.size();
        vector<int> fr(lim + 1,0);
      
        for(int i : nums) {
          if(i > lim)
            pq.push({i,1});
          else
            fr[i]++;
        }
      
        while(k > 0 && !pq.empty()) {
            auto [x,f] = pq.top(); pq.pop();
          
            while(!pq.empty() && pq.top().first==x){
                f+=pq.top().second;
                pq.pop();
            }
          
            int d;
          
            if(!pq.empty()){
                while(x > lim && x > pq.top().first && k > 0){
                    d=min(k,f);
                    k-=d;
                    ans+=1ll*d*x;
                    x=(x+2)/3;
                }
            } else{
                d=min(k,f);
                k-=d;
                ans+=1ll*d*x;
                x=(x+2)/3;
            }
          
            if(x > lim)
              pq.push({x,f});
            else
              fr[x]+=f;
        }
      
        for(int i = lim,d; i > 1 && k>0; i--){
            ans+=1ll*min(k,fr[i])*i;
            k-=min(fr[i],k);
            fr[(i+2)/3]+=fr[i];
        }
      
        if(k>0)
          ans+=k;
        return ans;
    }
};
