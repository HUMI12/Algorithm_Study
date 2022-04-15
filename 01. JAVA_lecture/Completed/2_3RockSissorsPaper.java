import java.util.*;

class Main{
    public ArrayList<String> solution(int n, int[] arr_A, int[] arr_B){
        ArrayList<String> answer = new ArrayList<>();

        for(int i=0; i<n; i++){
            if( (arr_A[i] - arr_B[i] == 1) ||  (arr_A[i] - arr_B[i] == -2) ) answer.add("A");
            else if((arr_A[i] - arr_B[i] == 2) ||  (arr_A[i] - arr_B[i] == -1)) answer.add("B");
            else answer.add("D");
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int arr_A[] = new int[n];
        int arr_B[] = new int[n];

        for(int i=0; i< n; i++){
            arr_A[i] = kb.nextInt();
        }
        for(int i=0; i<n; i++){
            arr_B[i] = kb.nextInt();
        }

        for(String x: T.solution(n,arr_A,arr_B)){
            System.out.println(x);
        }
    }
}