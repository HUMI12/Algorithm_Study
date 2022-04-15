import java.util.*;

class ReverseString{
    public String [] solution(String [] words){
        String [] reverse_words = new String[words.length];

        for(int i=0; i < words.length ; i ++){
            StringBuffer sb = new StringBuffer(words[i]);
            reverse_words[i] = sb.reverse().toString();
        }

        return reverse_words;
    }
    public static void main(String args[]){
        ReverseString T = new ReverseString();
        Scanner kb = new Scanner (System.in);
        int n =kb.nextInt();
        String [] words = new String[n];

        for(int i = 0 ; i < n; i ++){
            words[i] = kb.next();
        }
        for(int i = 0 ; i< n; i++){
            System.out.println(T.solution(words)[i]);
        }
    }
}