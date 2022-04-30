package samsung_pr;

import java.util.*;

public class Main {
	static int n;
	static int[][] ch;
	static int answer = 0;
	
	
	public void gotarget(int x, int y, int direction) {
		if(x==n && y==n){
			answer++;
			return;
		}else {
			switch(direction) {
			case 0: //가로
				if(y+1 <=n && ch[x][y+1] ==0) {
					gotarget(x, y+1, 0);
				}
				break;
			case 1: //세로
				if(x+1 <=n && ch[x+1][y]==0) {
					gotarget(x+1, y, 1);
				}
				break;
			case 2:  //대각
				if(y+1 <= n && ch[x][y+1]==0) {
					gotarget(x, y+1, 0);
				}
				if(x+1 <= n && ch[x+1][y]==0) {
					gotarget(x+1, y, 1);
				}
				break;
			}
			if(x+1 <=n && y+1 <=n && ch[x][y+1]==0 && ch[x+1][y]==0 && ch[x+1][y+1]==0) {
				gotarget(x+1, y+1, 2);
			}
				

		}
	}
	
	public static void main(String[] args) {
		Main T = new Main();
		Scanner kb = new Scanner(System.in);
		n = kb.nextInt();
		ch = new int[n+1][n+1];

	
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++){	
				ch[i][j] = kb.nextInt();
			}
		}

		T.gotarget(1,2,0);
		System.out.print(answer);
		
	}

}