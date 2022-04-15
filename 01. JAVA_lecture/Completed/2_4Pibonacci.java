import java.util.*;

class Main{
    public ArrayList<Integer> solution(int n){
        ArrayList<Integer> answer = new ArrayList<>();
        answer.add(1);
        answer.add(1);
        answer.add(2);

        for (int i=3; i<n; i++){
            answer.add(answer.get(i-2)+answer.get(i-1));
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();

        for(int x: T.solution(n)){
            System.out.print(x+" ");
        }
    }
}