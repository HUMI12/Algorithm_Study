import java.util.*;

class Main{
    public String solution(String str){
        String answer;
        int rt = 0;
        int lt = str.length() -1;
        char[] s = str.toCharArray();
        int check_flag = 0;

        while(rt < lt){
            if(Character.compare(Character.toUpperCase(s[rt]), Character.toUpperCase(s[lt])) == 0){
                rt ++;
                lt --;
            }else {
                check_flag = 1;
                break;
            }
        }
        if(check_flag==1) answer = "NO";
        else answer ="YES";

        return answer;

    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        String str = kb.nextLine();
        System.out.print(T.solution(str));
    }
}