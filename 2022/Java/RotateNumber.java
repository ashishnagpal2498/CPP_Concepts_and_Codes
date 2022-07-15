// Rotate number by K digits ->

// Given two integers n and k -

import java.util.*;

public class RotateNumber {
    private static void rotate(int n, int k) {
        int [] digits = new int[100];
        Boolean isPositive = n >= 0 ? true : false;
        int i = 0;
        while (n != 0) {
            digits[i++] = n % 10;
            n /= 10;
            //System.out.println(n);
        }
        // Indexes are from 0th so reducing i
        --i;
        // Digits are present in Opposite order 562984 -> 845629
        System.out.println("Number is " + isPositive);
        if (isPositive) {
            for (int j = k - 1; j > -1; j--) {
                n = n * 10 + digits[j];
            }
            while (i >= k) {
                n = n * 10 + digits[i];
                i--;
            }

        } else {
            System.out.println("Value i -> " + i + " k -> " + k);
            for (int j = i - k; j >=0; j--) {
                n = n * 10 + digits[j];
            }
            System.out.println(n);
            while (i > i - k) {
                n = n * 10 + digits[i];
                i--;
            }
        }
        System.out.println("Number after rotation " + n);
    }
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int k = scn.nextInt();
        rotate(n, k);
    }
}