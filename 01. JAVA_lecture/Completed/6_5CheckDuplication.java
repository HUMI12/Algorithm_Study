import java.util.*;
class Main{
    public Character solution(int n, int[] arr){
        char answer ='U';
        for(int i=0; i<n; i++){
            if(answer == 'D') break;
            for(int j=i+1; j<n; j++) {
                if(arr[i] == arr[j]){
                    answer = 'D';
                    break;
                }
            }
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++) arr[i] =kb.nextInt();

        System.out.print(T.solution(n,arr));
    }
}