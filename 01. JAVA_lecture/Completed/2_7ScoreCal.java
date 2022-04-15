import java.util.*;

class Main{
    public int solution(int n, int[] arr){
        int answer = 0;
        int i =0;
        int score = 0;
        while(i !=n){
            if(arr[i] == 1){
                score += 1;
                answer += score;
            }
            else{
                score = 0;

            }
            i++;
        }

        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();

        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = kb.nextInt();
        }

        System.out.print(T.solution(n, arr));

    }
}