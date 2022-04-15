import java.util.*;

class Main{
    public String solution(String str){
        String answer="";
        char[] s = str.toCharArray();

        for(int i = 0; i< str.length(); i++){
            if( 0 <= Character.getNumericValue(s[i]) && Character.getNumericValue(s[i])<=9 ){
                if(answer != "" || s[i] != '0')   answer += s[i];
            }
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        String str = kb.nextLine();

        System.out.print(T.solution(str));
    }
}