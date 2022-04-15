import java.util.*;

class Main{
    public int solution(int n){
        int answer=0;
        boolean[] prime = new boolean[n];

        for(int i =2; i<=Math.sqrt(n); i++){

            for(int j=i; j<n; j++) {
                if(prime[j] == true) continue;

                if ((j+1)%i == 0) prime[j] = true;

            }

        }
        for(int i = 2; i<=prime.length;i++){
            if(!prime[i-1]) answer++;
        }

        return answer;
    }

    public static void main(String[] args){
        Main T= new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();

        System.out.print(T.solution(n));
    }
}