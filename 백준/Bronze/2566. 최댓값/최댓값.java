import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    
	    int[][] arr = new int[10][10];
	    
	    for (int i = 1; i <= 9; i++) 
	        for (int j = 1; j <= 9; j++)
	            arr[i][j] = sc.nextInt();
        
        int mx = -1, y = 0, x = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (arr[i][j] > mx) {
                    mx = arr[i][j];
                    y = i;
                    x = j;
                }
            }
        }
        
        System.out.println(mx);
        System.out.printf("%d %d", y, x);
	}
}