import java.util.*;

class Main{
    public int Solution(int n, int k, int[] arr){
        int answer = Integer.MIN_VALUE;
        int lt=0, cnt=0;


        for(int rt=0; rt<n;rt++){
           if(arr[rt]==0) cnt++;
           while(cnt>k){
               if(arr[lt] == 0) cnt--;
               lt++;
           }
           answer=Math.max(answer,rt-lt+1);
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int k = kb.nextInt();
        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = kb.nextInt();
        }
        System.out.print(T.Solution(n,k,arr));
    }
}