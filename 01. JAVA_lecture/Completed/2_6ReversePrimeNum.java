import java.util.*;

class Main{
    public ArrayList<Integer> solution (int n, int[] arr){
        ArrayList<Integer> answer = new ArrayList<>();
        int[] tmp = new int[n];
        boolean prime ;
        //123  100 20 3   300  300
        //  3 ,  32, 321

        // Reverse number
        for(int i=0; i<arr.length; i++) {
            tmp[i] = 0;
            while (arr[i] != 0) {
                tmp[i] = 10 * tmp[i] + arr[i] % 10;
                arr[i] = arr[i] / 10;
            }
        }

        //Sorting prime number
        for(int i=0; i<tmp.length; i++){
            prime = true;
            for(int j=2; j <= Math.sqrt(tmp[i]);j++){
                if(tmp[i]%j == 0 ){
                    prime = false;
                    break;
                }
            }

            if(prime ==true && tmp[i] != 1) answer.add(tmp[i]);
        }
        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i]= kb.nextInt();
        }

        for(int x: T.solution(n,arr)){
            System.out.print(x+" ");
        }
    }
}