import java.util.*;

class Main{
    public String solution(String str1, String str2){
        String answer = "YES";
        Queue<Character> Q = new LinkedList<>();
        for(char x: str1.toCharArray()){
            Q.offer(x);
        }
        for(char x: str2.toCharArray()){
            if(Q.isEmpty()) break;
            if(x==Q.peek()) Q.poll();
        }
        if(!Q.isEmpty()) answer = "NO";
        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        String str1 = kb.nextLine();
        String str2 = kb.nextLine();

        System.out.print(T.solution(str1, str2));
    }
}