import java.util.*;

class Main{
    public String solution(String str){
        ArrayList <Integer> Alphabet_ind = new ArrayList<Integer>();
        String answer = "";

        for(int i = 0; i< str.length(); i++){
            if( (65<=str.charAt(i)) && (str.charAt(i)<=90)  ) {  // Uppercase
                Alphabet_ind.add(i); // 문자 저장
            }
            else if ( (97<=str.charAt(i)) && (str.charAt(i) <= 122)) { //LowerCase
                Alphabet_ind.add(i);
            }
            else
                continue;
        }
        String [] Alphabet_reverse = new String[Alphabet_ind.size()];

        for(int i = 0; i<Alphabet_ind.size(); i++){
            Alphabet_reverse[i] = Character.toString(str.charAt(Alphabet_ind.get(Alphabet_ind.size()-i-1)));
        }

        StringBuilder builder = new StringBuilder(str);
        for (int i = 0; i< Alphabet_ind.size(); i++){
            builder.setCharAt(Alphabet_ind.get(i), Alphabet_reverse[i].charAt(0));
        }
        answer = builder.toString(); // 와 이렇게 그냥 변환 하면됨;;

        return answer;

    }

    public static void main(String[] args){

        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();

        System.out.print(T.solution(str));
    }

}