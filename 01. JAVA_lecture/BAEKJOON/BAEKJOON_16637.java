import java.util.*;

class Main{
    static ArrayList<Integer> num;
    static ArrayList<Character> ops;
    static int n;
    static int answer;
    public int calcul(int num1, int num2, char op){
        if(op == '+') return num1 + num2;
        else if(op == '*') return num1 * num2;
        else return num1 - num2;
    }
    public int dfs(String str){
        num = new ArrayList<>();
        ops = new ArrayList<>();
        answer = Integer.MIN_VALUE;
        for(int i=0; i<str.length(); i++){
            if(i%2==1) ops.add(str.charAt(i));
            else num.add(Character.getNumericValue(str.charAt(i)));
        }
        dfsreqursive(num.get(0), 0);
        return answer;
    }
    public void dfsreqursive(int val, int idx){
        if(idx==ops.size()){
            answer = Math.max(answer,val);
            return;
        }
        int res1 = calcul(val, num.get(idx+1), ops.get(idx));
        dfsreqursive(res1,idx+1);

        if(idx+1 < ops.size()){
            int res2 = calcul(num.get(idx+1), num.get(idx+2),ops.get(idx+1));
            dfsreqursive( calcul(val,res2,ops.get(idx)),idx+2 );
        }

    }
    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);
        n = kb.nextInt();
        String str = kb.next();

        Main T = new Main();
        System.out.print(T.dfs(str));

    }
}

