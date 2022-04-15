import java.util.*;

class Main{
    public Integer[] solution(Integer[] arr1, Integer[] arr2){
        Integer[] answer = new Integer[arr1.length+ arr2.length];

        List<Integer> list1 = new ArrayList(Arrays.asList(arr1));
        List<Integer> list2 = new ArrayList(Arrays.asList(arr2));

        list1.addAll(list2);
        Collections.sort(list1);

        answer = list1.toArray(new Integer[0]);

        return answer;

    }


    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        Integer[] arr1 = new Integer[n];
        for(int i=0; i<n; i++){
            arr1[i] = kb.nextInt();
        }

        n = kb.nextInt();
        Integer[] arr2 = new Integer[n];
        for(int i=0; i<n; i++){
            arr2[i] = kb.nextInt();
        }

        for(int x:T.solution(arr1, arr2)){
            System.out.print(x+ " ");
        }
    }
}