import java.util.*;

class Main{
    public String solution(String str, int num){
        String answer = "";
        int[] num_contain = new int[num];

        for(int i=0; i< num; i++){
            for(int j=7*i; j<7*i+7;j++){
                if(str.charAt(j) == '#') num_contain[i] = num_contain[i]*2 + 1;
                else num_contain[i] = num_contain[i]*2;
            } //십진수 완성.
            answer += (char)num_contain[i];
        }

        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int num = (Integer) kb.nextInt();
        kb.nextLine();
        String str = kb.next();
        System.out.print(T.solution(str,num));
    }
}