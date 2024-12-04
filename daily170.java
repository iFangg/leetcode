// Solution 1
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        /*
        keep track of index of str2 substitute
        for str1 indices 0 to n-1
            if str1[i] == str2[j] or str1[i] + 1 == str2[j]
                increment str2 index
        
        if str2 index = end of str2
            return true
        
        else
            return false
        */
        int idx_2 = 0;

        for (int i = 0; i < str1.length(); i++) {
            if (idx_2 >= str2.length())
                break;
            char curr_char = str1.charAt(i);
            char subseq_char = str2.charAt(idx_2);
            char next = curr_char == 'z' ? 'a' : (char)(curr_char + 1);

            if (curr_char == subseq_char || next == subseq_char) {
                idx_2++;
            }
        }

        return idx_2 == str2.length() ? true : false;
    }
}


// Solution 2
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int n1 = str1.length() ;
        int n2 = str2.length() ;
        int ptr1 = 0 ;
        int ptr2 = 0 ;
        while(ptr1 < n1 && ptr2 < n2){
            char sch = str1.charAt(ptr1) ;
            char tch = str2.charAt(ptr2) ;
            if(sch != tch){
                if( sch +1 == tch   ||  sch - 25 == tch){
                 ptr1 ++ ;
                 ptr2 ++ ;
                }
                else{
                ptr1 ++ ;
                }
            }

            else{
            ptr1 ++ ;
            ptr2 ++ ;
            }

            if(ptr1 == n1  && ptr2 != n2)
            return false ;       
                
        }
        return true ;
        
    }
}
