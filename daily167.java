// Solution 1
class Solution {
    public boolean checkIfExist(int[] arr) {
        /**
        linear approach
        keep hashmap of numbers and occurences
        if a number's double or half exists, return true
         */

        HashMap<Integer, Integer> exists = new HashMap<Integer, Integer>();

        for (int n : arr) {
            if (n % 2 == 0 && exists.containsKey(n / 2))
                return true;
            
            if (exists.containsKey(n * 2))
                return true;
            
            exists.put(n, 1);
        }

        return false;
    }
}


// Solution 2
class Solution {
    public boolean checkIfExist(int[] arr) {
        for(int i=0;i<arr.length;i++){
            float t=(float)arr[i]/2;
            int x=search(arr,t);
            if(x!=i && x!=-1)return true;
        }
        return false;
    }
    public int search(int []arr,float target){
        for(int i=0;i<arr.length;i++){
            if((float)arr[i]==target){
                return i;
            }
        }
        return -1;
    }
}

