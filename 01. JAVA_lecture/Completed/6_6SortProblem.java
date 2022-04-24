import java.util.*;

class Main{
    public List<Integer> solution(int n, int[] Height){
        List<Integer> answer = new ArrayList<>();

        int[] arr = Height.clone();
        Arrays.sort(Height);
        for(int i=0; i<n; i++){
            if(arr[i] != Height[i]) answer.add(i+1);
            if(answer.size()==2) break;
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[] Height = new int[n];


        for(int i=0; i<n; i++){
            Height[i] = kb.nextInt();
        }

        for(int x: T.solution(n, Height)) System.out.print(x+ " ");
    }
}