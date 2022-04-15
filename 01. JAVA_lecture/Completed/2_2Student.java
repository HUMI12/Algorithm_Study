import java.util.*;


class Main{
    public int solution(int n, int[] arr){
        int answer = 1;
        int b = arr[0];

        for(int i = 1; i<n; i++){
            if(b < arr[i]) {
                answer++;
                b = arr[i];
            }
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[] arr = new int[n];
        for(int i =0; i<n; i++){
            arr[i] = kb.nextInt();
        }

        System.out.print(T.solution(n,arr));

    }
}