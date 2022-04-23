import java.util.*;

class Main{
    public int[] solution(int s, int m, int[] arr){
        int[] cache = new int[s];
        int tmp =0;
        for(int i=0; i<m; i++){
            for(int idx=0; idx<s; idx++){
                if(arr[i]!=cache[idx]){//Cache Miss
                    tmp = 0;
                    continue;
                }else {  //Cache Hit
                    tmp = idx;
                    break;
                }
            }
            if(tmp==0){ //cache Miss
                for(int j=s-1;j>0;j--){
                    cache[j] =cache[j-1];
                }
            }else{ //cache Hit
                for(int j=tmp; j>0;j--){
                    cache[j] = cache[j-1];
                }
            }
            cache[0] = arr[i];

        }

        return cache;
    }

    public static void main(String[] args){
        Main T = new Main();

        Scanner kb = new Scanner(System.in);
        int s = kb.nextInt();
        int m = kb.nextInt();
        int[] arr = new int[m];

        for(int i=0; i<m; i++){
            arr[i] = kb.nextInt();
        }

        for(int x: T.solution(s,m,arr)) System.out.print(x +" ");

    }
}