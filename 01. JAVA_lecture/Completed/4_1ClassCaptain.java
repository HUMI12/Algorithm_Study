import java.util.*;

class Main{
    public char solution(int n, String str){
        char answer=' ';
        HashMap<Character, Integer> map = new HashMap<>();
        for(char x : str.toCharArray()){
            map.put(x,map.getOrDefault(x,0)+1);
        }
//        System.out.println(map.containsKey('F'));
//        System.out.println(map.size());
//        System.out.println(map.remove('C'));

        int max = Integer.MIN_VALUE;
        for(char key: map.keySet()){
            if(map.get(key)>max){
                max = map.get(key);
                answer=key;
            }
        }


        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        String str = kb.next();

        System.out.print(T.solution(n, str));

    }
}