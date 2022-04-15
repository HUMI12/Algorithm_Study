import java.util.*;

class Main{
    public String solution(String str){
        String answer="";
        int count=0;
        str = str + " ";
        for(int i=0; i < str.length()-1; i++){
            if(str.charAt(i) == str.charAt(i+1)){
                count++;
            }
            else{
                answer += str.charAt(i);
                if(count+1 >1) answer+= String.valueOf(count+1);
                count = 0;
            }
        }

        return answer;
    }
    //KKKKHSSSSSSSE K 같은게 나오면 그자리 개수만큼
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();

        System.out.print(T.solution(str));
    }
}