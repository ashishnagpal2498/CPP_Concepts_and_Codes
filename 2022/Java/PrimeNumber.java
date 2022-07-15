// Number is a Prime or not
// Create different functions

import java.util.*;

public class PrimeNumber{
    private static Boolean isPrime(int n){
        for(int i=2; i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    public static void main(String [] args ){
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        Boolean ans = isPrime(n);
        if (ans) System.out.println("Number " + n + " is Prime");
        else System.out.println("Number " + n + " is not Prime");
    }
}