import java.util.*;

class Main{
    public ArrayList<Integer> solution(int N, int K, int[] arr){
        ArrayList<Integer> answer = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        int rt=0, lt=0;

        for(rt=0; rt<N; rt++){
            map.put(arr[rt],map.getOrDefault(arr[rt],0)+1);
            if(rt-lt==K-1){
                answer.add(lt,map.size());
                map.put(arr[lt],map.getOrDefault(arr[lt],0)-1);
                if(map.get(arr[lt]) ==0) map.remove(arr[lt]);
                lt++;
            }
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int N = kb.nextInt();
        int K = kb.nextInt();
        int[] arr = new int[N];

        for(int i=0; i<N;i++){
            arr[i] = kb.nextInt();
        }


        for(int x: T.solution(N,K,arr)){
            System.out.print(x+" ");
        }
//        System.out.print(T.solution(N,K,arr));

    }
}