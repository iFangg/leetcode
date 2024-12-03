// Solution 1
class Solution {
    public String addSpaces(String s, int[] spaces) {
        /**
            linear approach
            make new string
            if index == spaces index
                add space and then add character
            else
                keep adding characters
        */

        StringBuilder res = new StringBuilder();
        int sp_idx = 0;

        for (int i = 0; i < s.length(); i++) {
            if (sp_idx < spaces.length && i == spaces[sp_idx]) {
                res.append(' ');
                sp_idx++;
            }

            res.append(s.charAt(i));
        }

        return res.toString();
    }
}


// Solution 2
class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] ch=s.toCharArray();
        char[] charr=new char[s.length()+spaces.length];
        int idx=0,c=0;
        for (int sp:spaces){
            while (c<sp){
                charr[idx]=ch[c];
                idx++;
                c++;
            }
            charr[idx]=' ';
            idx++;
        }
        while(c<s.length()){
            charr[idx]=ch[c];
            idx++;
            c++;
        }
        return new String(charr);



    }

}
