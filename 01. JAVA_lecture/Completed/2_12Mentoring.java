import java.util.*;

class Main{
    public int solution(int M, int N, int[][] arr){
        int answer =0;
        boolean[][] ch_table = new boolean[N][N];
        boolean[][] answer_table= new boolean[N][N];

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                for(int k=j+1; k<N; k++){
                    ch_table[arr[i][j]-1][arr[i][k]-1] = true;
                    answer_table[arr[i][j]-1][arr[i][k]-1] = true;
                    if(ch_table[arr[i][j]-1][arr[i][k]-1] == ch_table[arr[i][k]-1][arr[i][j]-1] ){
                        answer_table[arr[i][j]-1][arr[i][k]-1] = false;
                        answer_table[arr[i][k]-1][arr[i][j]-1]= false;
                    }
                }
            }
        }

        for(int i=0; i<N;i++){
            for(int j=0; j<N;j++){
                if(answer_table[i][j]) answer++;
            }
        }



        return answer;

    }

    public static void main(String[] args){
        Main T= new Main();
        Scanner kb = new Scanner(System.in);

        int N = kb.nextInt();
        int M = kb.nextInt();
        int[][] arr = new int[M][N];

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = kb.nextInt();
            }
        }

        System.out.print(T.solution(M,N,arr));
    }
}