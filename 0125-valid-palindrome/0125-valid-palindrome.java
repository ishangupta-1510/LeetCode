class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();

        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if('a' <= c && c <= 'z'){
                sb.append(c);
            }else if('A' <= c && c <= 'Z'){
                int x = (int)(c - 'A');
                char z = (char)('a'+ x);
                sb.append(z);
            }else if('0' <= c && c <= '9'){
                sb.append(c);
            }
        }
        System.out.print(sb);
        int i=0, j = sb.length()-1;
        while(i<j){
            if(sb.charAt(i) != sb.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}