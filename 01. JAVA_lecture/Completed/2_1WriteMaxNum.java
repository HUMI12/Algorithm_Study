import java.util.*;

class Main{
    public ArrayList<Integer> solution(int n, int[] array){
        ArrayList<Integer> answer = new ArrayList<>();
        answer.add(array[0]);
        for(int i = 1; i<array.length; i++){
            if(array[i-1] < array[i] ) answer.add(array[i]);
        }

        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[] array = new int[n];

        for(int i=0; i<n; i++){
            array[i] = kb.nextInt();
        }
        for(int x: T.solution(n,array)){
            System.out.print(x+ " ");
        }
    }
}