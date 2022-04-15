import java.util.*;

class Main{
    public String solution(String str, char c){
        String answer = "";
        ArrayList<Integer> tmp = new ArrayList<>();
        ArrayList<Integer> contain = new ArrayList<>();

        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == c) tmp.add(i);// 1 5 10
        }

        for(int i = 0; i<tmp.size(); i++){
            contain.add(i);
        }

        for (int i=0; i < str.length(); i++){
            for(int j=0; j<tmp.size(); j++){
                contain.set(j, Math.abs( i - tmp.get(j) ));

            }
            Collections.sort(contain);
            answer += contain.get(0).toString() + " ";
        }
        return answer;
    }
    //teachermode e
    public static void main(String[] args){

        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();
        char c = kb.next().charAt(0);

        System.out.print(T.solution(str,c));

    }
}