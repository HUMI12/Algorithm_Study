import java.util.*;

class Main{

    public String solution(String str){
        String answer = "";
        int answer_num = 0;

        String[] words = str.split(" ") ; //₩₩s로도 됨.
        int [] word_length  = new int[words.length];
        //int init_length = word_length[0] ;

        for(int i = 0 ; i< words.length ; i++ ){
            word_length[i] = words[i].length();
            if ( word_length[answer_num] >= word_length[i]){
                answer_num = answer_num;
            }
            else{
                answer_num = i;
            }
            answer = words[answer_num];
        }

        return answer;
    }

    public static void main(String[] args){
        Main T = new Main();
        Scanner kb =  new Scanner(System.in);
        String str = kb.nextLine();

        System.out.print(T.solution(str));
    }
}