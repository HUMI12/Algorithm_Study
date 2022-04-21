import java.util.*;

class Person{
    int id;
    int priority;
    public Person(int id, int priority){
        this.id = id;
        this.priority = priority;
    }
}

class Main {
    public int solution(int n, int m, int[] array){
        int answer =0;
        Queue<Person> Q = new LinkedList<>();
        for(int i=0; i<n; i++){
            Q.offer(new Person(i,array[i]));
        }
        while(!Q.isEmpty()){
            Person tmp = Q.poll();
            for(Person x: Q){
                if(x.priority >tmp.priority){
                    Q.offer(tmp);
                    tmp = null;
                    break;
                }
            }
            if(tmp != null){
                answer++;
                if(tmp.id == m ) return answer;
            }
        }

        return answer;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);

        int n = kb.nextInt();
        int m = kb.nextInt();
        int[] array = new int[n];

        for(int i=0; i<n; i++){
            array[i] = kb.nextInt();
        }
        System.out.print(T.solution(n,m,array));


    }
}
