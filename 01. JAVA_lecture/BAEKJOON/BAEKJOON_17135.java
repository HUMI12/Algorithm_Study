package samsung_pr;

import java.util.*;

class Main{
	static int answer=0;
	static int n, m, d;
	static int[][] map;
	static int[][] initmap;
	static int[][] ch;
	
	public static void init() {
		for(int i =1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				map[i][j] = initmap[i][j];
			}
		}
	}
	public void arc_pos(int pos1, int k, int tar_num, ArrayList<Integer> archer) {
		if(tar_num==0) {
			init();
			game(archer);
			return;
		}else {
			for(int i= pos1;i<=k ; i++) {
				archer.add(i);
				arc_pos(i+1,k, tar_num-1, archer);
				archer.remove(archer.size()-1);
			}
		}
	}
	public int distance(int r1, int c1, int r2, int c2) {
		return Math.abs(r1-r2) + Math.abs(c1-c2);
	}
	public void game(ArrayList<Integer> archer) {
		int res =0;
		for(int i=1; i<=n; i++) {
			int[][] ch = new int[n+1][m+1];
			// decide the enemy who will be died by each archer.
			for(int j=0; j<archer.size();j++) {
				int temp = archer.get(j); // 궁수의 x좌표
				int minD = Integer.MAX_VALUE;
				int minR = Integer.MAX_VALUE;
				int minC = Integer.MAX_VALUE;
				
				for(int x=1; x<=n; x++) {
					for(int y=1; y<=m; y++) {
						if(map[x][y]==1) { // if enemy in here
							if(minD>=distance(x,y,n+1,temp)) {
								if(minD>distance(x,y,n+1,temp)) {
									minD = distance(x, y, n+1, temp);
									minR = x;
									minC = y;
								}else {
									if(minC > y) {
										minR= x;
										minC = y;
									}
								}
							}
						}
					}
				}
				if(minD <= d) {
					ch[minR][minC] = 1; //check the enemy who will be died.
				}
			}
			for(int x=1; x<=n; x++) {
				for(int y=1; y<=m; y++) {
					if(ch[x][y]==1) {
						map[x][y] =0;
						res++;
					}
				}
			}
			for(int y=1;y<=m; y++) map[n][y] =0;
			for(int x=n; x>=1; x--) {
				for(int y=1; y<=m; y++) {
					map[x][y] = map[x-1][y];
				}
			}
		}
		
		answer = Math.max(answer, res);
	}
	
	public static void main(String[] args) {
		Main T = new Main();
		Scanner kb = new Scanner(System.in);
		n = kb.nextInt();
		m = kb.nextInt();
		d = kb.nextInt();
		map = new int[n+1][m+1];
		initmap = new int[n+1][m+1];
		
		for(int i=1;i<=n;i++) {
			for(int j=1; j<=m; j++) {
				map[i][j] = kb.nextInt();
				initmap[i][j] = map[i][j];
			}
		}
		kb.close();
		ArrayList<Integer> archer = new ArrayList<>();
		T.arc_pos(1, m, 3, archer);
		
		System.out.print(answer);
	}
}