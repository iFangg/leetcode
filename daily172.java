// Solution 1
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        /*
         have array from 1 - n, remove all elements present in banned
         add numbers in sorted order to find max numbers summed <= max sum
        */
        Set<Integer> banned_set = new HashSet<>();
        for (int num : banned) {
            banned_set.add(num);
        }

        List<Integer> nums = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            if (!banned_set.contains(i))
                nums.add(i);
        }
        System.out.println(nums.toString());

        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            count++;
            System.out.println(sum);

            if (sum > maxSum)
                return count == 0 ? 0 : count - 1;
        }

        return count;
    }
}


// Solution 2
class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        int sum = 0;
        int result = 0;
        boolean[] isBanned = new boolean[10001];
        for (int ban : banned) {
            isBanned[ban] = true;
        }
        for (int i = 1; i <= n; i++) {
            if (sum + i > maxSum) {
                break;
            }
            if (!isBanned[i]) {
                sum += i;
                result++;
            }
        }
        return result;
    }
}
