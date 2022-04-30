package samsung_pr;
import java.util.*;

public class Main {
	static int[][] map;
	static int[] paper = {0,5,5,5,5,5};
	static int ans =Integer.MAX_VALUE;
	
	public static void main(String[] args) {
		Main T = new Main();
		Scanner kb = new  Scanner(System.in);
		map = new int[10][10];
		
		for(int i=0; i<10; i++) {
			for(int j=0;j<10; j++) {
				map[i][j] = kb.nextInt();
			}
		}
		
		T.DFS(0,0,0);
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
		System.out.print(ans);
	}
	
	
	public void DFS(int x, int y, int res) {
		if(x>=9 && y>9) {
			ans = Math.min(ans,res);
			return;
		}
		
		if(ans<=res) return;
		
		if(y>9) {
			DFS(x+1,0,res);
			return;
		}
		
		if(map[x][y]==1) { 
			for(int i=5; i>=1; i--) {
				if(paper[i]>0 && isAttatch(x,y,i)) {
					update_state(x,y,i,0);//색종이 붙이는 함수 .
					paper[i]--;
					DFS(x,y+1,res+1);
					update_state(x,y,i,1);
					paper[i]++;
				}
			}
		}
		else {
			DFS(x, y+1, res);
		}
	}
	
	public boolean isAttatch(int x, int y, int n) {
		for(int i=x; i<x+n; i++) {
			for(int j=y; j<y+n; j++) {
				if(i<0 || i>9 || j<0 || j>9) return false;
				if(map[i][j]!=1) return false;
			}
		}
		return true;
	}
	
	public void update_state(int x, int y, int n, int state) {
		for(int i=x; i<x+n; i++) {
			for(int j=y; j<y+n; j++) {
				map[i][j] = state;
			}
		}
	}
	
}
