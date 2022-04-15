import java.util.*;

class Main{

    public int solution(int n, int[][] arr){

        int answer=0;
        int tmp=0;
        ArrayList<Integer> sum = new ArrayList<>();

        // 행의 합 저장
        for(int i=0; i<n;i++) {
            for (int j = 0; j < n; j++) {
                tmp = tmp + arr[i][j];
            }
            sum.add(tmp);
            tmp =0;
        }
        // 열의 합 저장
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                tmp = tmp + arr[j][i];
            }
            sum.add(tmp);
            tmp =0;
        }
        // 대각선 저장1
        for(int i=0; i<n; i++){
            tmp = tmp + arr[i][i];
        }
        sum.add(tmp);
        tmp=0;

        //대각선 저장2
        for(int i=0; i<n; i++){
            tmp = tmp + arr[n-1-i][i];
        }
        sum.add(tmp);
        answer = Collections.max(sum);



        return answer;

    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int[][] arr = new int[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j] = kb.nextInt();
            }
        }

        System.out.print(T.solution(n,arr));


    }
}