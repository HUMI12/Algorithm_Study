import java.util.*;

class Main2 {
    public String solution(String str){
        char tmp;
        String answer = "";

        for(int i = 0; i<str.length(); i++){
            tmp = str.charAt(i);
            if( (65 <= tmp) && (tmp <= 90)){
               tmp = Character.toLowerCase(tmp);
            }
            else {
                tmp = Character.toUpperCase(tmp);
            }
            answer = answer + tmp;
        }
        return answer;
    }

    public static void main(String[] args){
        Main2 T = new Main2();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();
        System.out.print(T.solution(str));

    }
}
