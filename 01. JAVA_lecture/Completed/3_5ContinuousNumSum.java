import java.util.*;

class Main{
    public int solution(int n){
        int answer =0, lt=0, sum=1;
        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }

        for(int rt=1;rt<n;rt++){
            sum += arr[rt];
            while(lt<rt){
                if(sum==n) {
                    answer++;
                    sum -= arr[lt++];
                }else if(sum>n) sum -= arr[lt++];
                else break;
            }
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();

        System.out.print(T.solution(n));
    }
}