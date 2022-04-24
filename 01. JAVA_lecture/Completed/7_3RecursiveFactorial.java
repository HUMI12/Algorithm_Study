import java.math.BigInteger;
import java.util.*;
class Main{
    public BigInteger DFS(BigInteger n){
        if(n.equals(BigInteger.ONE)) return BigInteger.ONE;
        else return n.multiply(DFS(n.subtract(BigInteger.ONE)));
    }
    public static void main(String[]args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        BigInteger n = kb.nextBigInteger();
        System.out.println(T.DFS(n));
    }
}