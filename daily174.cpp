// Solution 1 - FAIL
import java.util.*;

class Solution {
    private int max_sum = 0;
    private int[][] events_;
    public int maxTwoEvents(int[][] events) {
        /*
        dp solution
            dp(i) = max sum at endTime i
            dp(0) = 0
            dp(i) = max of [ dp(i - 1), dp(i - 1) + curr_int val ] ???
            idk send help for dp
            
        recusurive (non-dp) solution
            for each event, e
                if end of int < prev start, continue
                add to max sum
                update max xum
                update new interval end
                recurse
                TAKES TOO LONG
            
            dfs events
            create edge list
            traverse to find max
        */

        events_ = events;
        Arrays.sort(events_, (int[] a, int[] b) -> a[0] - b[0]);
        System.out.println(Arrays.deepToString(events_));
        HashMap<Integer, Set<List<Integer>>> adjs = new HashMap<>();
        HashMap<List<Integer>, Integer> edges = new HashMap<>();

        for (int[] e : events) {
            List<Integer> edge = Arrays.asList(e[0], e[1]);

            edges.put(edge, Math.max(edges.getOrDefault(edge, 0), e[2]));

            if (!adjs.containsKey(e[1]))
                adjs.put(e[1], new HashSet<List<Integer>>());

            for (int[] e1 : events) {
                if (e == e1 || e[1] >= e1[0])
                    continue;
                
                List<Integer> neighb = Arrays.asList(e1[0], e1[1]);
                if (e1[0] > e[1])
                    adjs.get(e[1]).add(neighb);
            }
        }

        Set<List<Integer>> seen = new HashSet<>();
        dfs(adjs, edges, seen, 0, 0, 0);

        return max_sum;
    }

    private void dfs(HashMap<Integer, Set<List<Integer>>> adjs, HashMap<List<Integer>, Integer> edges, Set<List<Integer>> seen, int start, int end, int curr_sum) {
        max_sum = Math.max(max_sum, curr_sum);
        if (end == 0) {
            for (int[] e : events_) {
                List<Integer> e_list = Arrays.stream(e).boxed().collect(Collectors.toList());

                if (!seen.contains(e_list)) {
                    seen.add(e_list);
                    max_sum = Math.max(max_sum, curr_sum + e[2]);
                    dfs(adjs, edges, seen, e[0], e[1], curr_sum + e[2]);
                }
            }

            return;
        }

        if (!adjs.containsKey(end))
            return;


        for (List<Integer> n : adjs.get(end)) {
            int new_sum = curr_sum + edges.get(n);
            dfs(adjs, edges, seen, n.get(0), n.get(1), new_sum);
        }
    }
}


// Solution 2
import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;
        
        // Step 1: Sort the events by their start time
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        
        // Step 2: Create the suffix array for the maximum event value from each event onward
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = events[n - 1][2];  // Initialize the last event's value
        
        // Populate the suffixMax array
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = Math.max(events[i][2], suffixMax[i + 1]);
        }
        
        // Step 3: For each event, find the next event that starts after it ends
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            int nextEventIndex = -1;
            
            // Perform binary search to find the next non-overlapping event
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEventIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            // If a valid next event is found, update the max sum
            if (nextEventIndex != -1) {
                maxSum = Math.max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }
            
            // Also consider the case where we take only the current event
            maxSum = Math.max(maxSum, events[i][2]);
        }
        
        return maxSum;
    }
}

