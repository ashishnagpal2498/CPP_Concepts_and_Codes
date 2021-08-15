//K closest from origin 
import java.util.*;

public class Main {

    static void pClosest(int [][]pts, int k)
{
    int n = pts.length;
    int[] distance = new int[n];
    for(int i = 0; i < n; i++)
    {
        int x = pts[i][0], y = pts[i][1];
        distance[i] = (x * x) + (y * y);
    }
 
    Arrays.sort(distance);
     
    // Find the k-th distance
    int distk = distance[k - 1];
 
    // Print all distances which are
    // smaller than k-th distance
    for(int i = 0; i < n; i++)
    {
        int x = pts[i][0], y = pts[i][1];
        int dist = (x * x) + (y * y);
         
        if (dist <= distk)
           { System.out.println(x);
            System.out.println(y);
           }
    }
}
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int K=sc.nextInt();
         int n=sc.nextInt();
         int points[][]=new int[n][n];
         for(int i=0; i<n;i++)
         {            
            for(int j=0; j<n;j++)
            {
                points[i][j]=sc.nextInt();
            }
         }
     
    pClosest(points, K);

    }
}