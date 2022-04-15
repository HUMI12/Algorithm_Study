import java.util.*;

class Main{

    public int solution(int n, int[][] arr){
        int answer=0;
        int max=Integer.MIN_VALUE;
        int[] cnt = new int[n];
        int[] red = new int[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                for(int k=i+1; k<n; k++){
                    if(arr[i][j] == arr[k][j] && red[k]==0) {
                        cnt[i]++;
                        cnt[k]++;
                        red[k] = 1;
                    }
                }
            }
            Arrays.fill(red,0);
        }

        for(int i=0;i<cnt.length;i++){
            if(cnt[i]>max){
                max = cnt[i];
                answer = i+1;
            }
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int[][] arr = new int[n][5];

        for(int i=0; i<n;i++){
            for(int j=0; j<5; j++){
                arr[i][j] = kb.nextInt();
            }
        }

        System.out.print(T.solution(n, arr));
    }
}