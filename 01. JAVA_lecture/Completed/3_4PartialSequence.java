import java.util.*;

class Main{
    public int Solution(int N, int M, int[] arr){
        int answer = 0, rt =-1, lt =0;
        int sum = 0;

        while(rt<N-1){
            rt++;
            sum+=arr[rt];
            if(sum==M) answer++;
            while(sum>=M){
                sum -= arr[lt++];
                if(sum == M) answer++;
            }
        }


        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int N = kb.nextInt();
        int M = kb.nextInt();
        int[] arr = new int[N];

        for(int i=0; i<N;i++)             arr[i] = kb.nextInt();


        System.out.print(T.Solution(N,M,arr));
    }
}