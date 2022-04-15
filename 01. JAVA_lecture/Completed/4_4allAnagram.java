import java.util.*;

class Main{
    public int solution(String str1, String str2){
        int answer = 0, lt=0;
        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();
        boolean tmp = false;

        for(char x: str2.toCharArray()){
            map1.put(x,map1.getOrDefault(x,0)+1);
        }
        for(int rt = 0; rt<str1.length(); rt++){
            map2.put(str1.toCharArray()[rt],map2.getOrDefault(str1.toCharArray()[rt],0)+1);
            if(rt-lt==str2.length()-1){
//                for(char key: map1.keySet()){
//                    if(map2.containsKey(key) && map1.get(key) == map2.get(key)) tmp = true;
//                    else {
//                        tmp = false;
//                        break;
//                    }
//                }
                if(map1.equals(map2)) answer++;

                map2.put(str1.toCharArray()[lt], map2.getOrDefault(str1.toCharArray()[lt],0)-1);
                if(map2.get(str1.toCharArray()[lt])==0) map2.remove(str1.toCharArray()[lt]);
                lt++;
            }
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb= new Scanner(System.in);
        String str1 = kb.nextLine();
        String str2 = kb.nextLine();

        System.out.print(T.solution(str1,str2));

    }
}