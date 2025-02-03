// Solution 1 - FAIL
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        /*
        sliding window
            inc pointers starting at idx 0 and 1 (i, j)
            dec pointers starting at idx 0 and 1
            keep max len for incr and decreasing
                if nums[i] < nums[j]
                    inc_r ++
                    update max_dec
                    dec_l ++
                
                if nums[i] > nums[j]
                    update max_inc
                    inc_l++
                    dec_r++
            
            OR 
            pointers l and r at 0 and 1 (indx i, j)
            track current gradient
            if nums[i] < nums[j]
                if gradient is +
                    r++
                else
                    update max len
                    shift window over
                    update gradient
            if nums[i] > nums[j]
                if gradient is +
                    update max len
                    shift window over
                    update gradient
                else
                    r++
            else
                update max len
                l = j
                r = l + 1
                udpate gradient
                
        */
        int n = nums.length;

        if (n == 1)
            return 1;

        int l = 0;
        int r = 1;
        int delt = nums[l] > nums[r] ? 0 : 1;
        int max = 1;

        while (l < n && r < n) {
            System.out.println(l + ", " + r);
            if (r - l <= 1) {
                if (r - l == 1 && nums[l] == nums[r]) {
                    l = r;
                    r = l + 1;
                    System.out.println(l + ", " + r);
                    if (r >= n) {
                        return Math.max(max, r - l);
                    }
                    
                    continue;
                }

                delt = nums[r - 1] > nums[r] ? 0 : 1;
                r++;
                continue;
            }

            if (nums[r - 1] < nums[r]) {
                if (delt == 1)
                    r++;
                else {
                    max = Math.max(max, r - l);
                    l = r;
                    r = l + 1;
                    if (r >= n)
                        return max;

                    delt = nums[r - 1] > nums[r] ? 0 : 1;
                }
            } else if (nums[r - 1] > nums[r]) {
                if (delt == 1) {
                    max = Math.max(max, r - l);
                    l = r;
                    r = l + 1;
                    if (r >= n)
                        return max;

                    delt = nums[r - 1] > nums[r] ? 0 : 1;
                } else {
                    r++;
                }
            } else {
                max = Math.max(max, r - l);
                l = r;
                r = l + 1;
                if (r >= n)
                    return max;
                
                delt = nums[r - 1] > nums[r] ? 0 : 1;
            }
        }

        return Math.max(max, r - l);
    }
}


// Solution 2
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        /*
        iterate thru list
        update max subarray once a change in gradient has been detected
            if ^^ and curr is less than prev
                update max with current subarr len
            if vv and curr is greater than
                same
            if curr is ==
                update max
                shift starting point of subarray to curr
        */
        int n = nums.length;

        if (n == 1)
            return 1;
        
        if (n == 2)
            return nums[0] == nums[1] ? 1 : 2;

        int grad = nums[0] < nums[1] ? 1 : 0;
        int max = nums[0] == nums[1] ? 1 : 2;
        int l = 0;

        while (n > 2 && max == 1 && l < n) {
            l++;
            if (l + 1 >= n)
                return max;

            grad = nums[l] < nums[l + 1] ? 1 : 0;
            max = nums[l] == nums[l + 1] ? 1 : 2;
        }

        for (int i = 2; i < n; i++) {
            if (nums[i - 1] == nums[i]) {
                max = Math.max(max, i - l);
                l = i;
                continue;
            }

            if (grad == 1 && nums[i - 1] > nums[i]) {
                max = Math.max(max, i - l);
                l = i - 1;
                grad = 0;
            } else if (grad == 0 && nums[i - 1] < nums[i]) {
                max = Math.max(max, i - l);
                l = i - 1;
                grad = 1;
            }
        }

        return Math.max(max, n - l);
    }
}
