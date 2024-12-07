// Solution 1 - FAIL
class Solution {
    public boolean canChange(String start, String target) {
        /*
        match strings
        get order of target and start string
        return if orders are equal
        doesn't account for backwards movement!

        keep track of L and R positions in start, compare to target
        all Ls in start should be >= target Ls
        all Rs in start should be <= than target Rs
        */

        List<Integer> l_pos = new ArrayList<Integer>();
        List<Integer> r_pos = new ArrayList<Integer>();

        for (int i = 0; i < start.length(); i++) {
            if (start.charAt(i) == 'L')
                l_pos.add(i);
            
            if (start.charAt(i) == 'R')
                r_pos.add(i);
        }

        for (int i = 0; i < target.length(); i++) {
            if (target.charAt(i) == 'L') {
                if (l_pos.isEmpty())
                    return false;

                if (l_pos.get(0) < i)
                    return false;
                else if (!r_pos.isEmpty() && l_pos.get(0) > r_pos.get(0))
                    return false;
                else
                    l_pos.remove((int) 0);
            }

            if (target.charAt(i) == 'R') {
                if (r_pos.isEmpty())
                    return false;

                if (r_pos.get(0) > i)
                    return false;
                else if (!l_pos.isEmpty() && r_pos.get(0) < l_pos.get(0))
                    return false;
                else
                    r_pos.remove((int) 0);
            }
        }

        return true;
    }
}

// Solution 2
class Solution {
    public boolean canChange(String start, String target) {
        if (start.equals(target)) {
            return true;
        }
        int waitL = 0;
        int waitR = 0;
        
        for (int i = 0; i < start.length(); i++) {
            char curr = start.charAt(i);
            char goal = target.charAt(i);
            
            if (curr == 'R') {
                if (waitL > 0) {
                    return false;
                }
                waitR++;
            }
            if (goal == 'L') {
                if (waitR > 0) {
                    return false;
                }
                waitL++;
            }
            if (goal == 'R') {
                if (waitR == 0) {
                    return false;
                }
                waitR--;
            }
            if (curr == 'L') {
                if (waitL == 0) {
                    return false;
                }
                waitL--;
            }
        }
        
        return waitL == 0 && waitR == 0;
    }
}
