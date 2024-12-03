// Solution 1
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        /*
        split string into word array
        match characters until we find the right prefix
        */

        String[] words = sentence.split("\\s+");
        for (int i = 0; i < words.length; i++) {
            String w = words[i];
            int w_idx = 0;
            int s_idx = 0;
            while (s_idx < searchWord.length() && w_idx < w.length()) {
                if (w.charAt(w_idx) != searchWord.charAt(s_idx))
                    break;

                s_idx++;
                w_idx++;
            }

            if (s_idx == searchWord.length())
                return i + 1;
        }

        return -1;
    }
}


// Solution 2
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        int len = searchWord.length();
        String stri = "";
        for(String str : words){
            if(str.length()>=len && (str.substring(0,len).equals(searchWord))){
                stri = str;
                break;
            }
        }
        int res = -1;
        int count = 0;
        if(stri.length()==0)
            return -1;
        for(String str: words){
            count++;
            if(stri.equals(str)){
                res = count;
                break;
            }
        }
        return res;
    }
}
