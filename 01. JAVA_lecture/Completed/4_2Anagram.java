import java.util.*;

class Main{
    public String solution(String str1, String str2){
        String answer = "YES";
        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        for(char x: str1.toCharArray()){
            map1.put(x,map1.getOrDefault(x,0)+1);
        }
        for(char x: str2.toCharArray()){
            map2.put(x,map2.getOrDefault(x,0)+1);
        }

        for(char x: map1.keySet()){
            if(map2.containsKey(x))
                if(map1.get(x) == map2.get(x)) answer = "YES";
                else {
                    answer = "NO";
                    break;
                }
            else {
                answer = "NO";
                break;
            }
        }


        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb= new Scanner(System.in);
        String str1 = kb.nextLine();
        String str2 = kb.nextLine();

        System.out.print(T.solution(str1, str2));

    }
}