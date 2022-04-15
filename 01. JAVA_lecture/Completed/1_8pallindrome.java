import java.util.*;

class Main{
    public String solution(String str){
        String answer = "YES";
        int lt = 0;
        int rt = str.length()-1;
        char[] s = str.toCharArray();

        while(lt < rt){
            if( !Character.isAlphabetic(s[lt]) ) lt ++;
            else if( !Character.isAlphabetic(s[rt]) ) rt--;
            else{
                if( Character.compare(Character.toUpperCase(s[rt]), Character.toUpperCase(s[lt])) == 0 ){
                    lt++;
                    rt--;
                }else{
                    answer = "NO";
                    break;
                }
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