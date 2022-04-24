import java.util.*;
class Main{
    public int[][] solution(int n, int[][] arr){
        for(int i=0; i<n-1; i++){
            int idx =i;
            for(int j = i+1; j<n; j++){
                if(arr[j][0] < arr[idx][0]) idx =j;
                else if((arr[j][0] == arr[idx][0]) && arr[j][1] < arr[idx][1]) idx = j;
                else continue;
            }
            int[] tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
        return arr;
    }
    public static void main(String[] args){
        Main T = new Main();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        int[][] arr = new int[n][2];
        for(int i=0; i<n; i++){
            arr[i][0] = kb.nextInt();
            arr[i][1] = kb.nextInt();
        }

        int[][] answer = T.solution(n, arr);
        for(int i=0; i< n; i++){
            System.out.println(answer[i][0]+" "+answer[i][1]);
        }
    }
}

//Answer code
/*
import java.util.*;
class Point implements Comparable<Point>{
    public int x, y;
    Point(int x, int y){
        this.x=x;
        this.y=y;
    }
    @Override
    public int compareTo(Point o){
        if(this.x==o.x) return this.y-o.y;
        else return this.x-o.x;
    }
}

class Main {
    public static void main(String[] args){
        Scanner kb = new Scanner(System.in);
        int n=kb.nextInt();
        ArrayList<Point> arr=new ArrayList<>();
        for(int i=0; i<n; i++){
            int x=kb.nextInt();
            int y=kb.nextInt();
            arr.add(new Point(x, y));
        }
        Collections.sort(arr);
        for(Point o : arr) System.out.println(o.x+" "+o.y);
    }
}*/
