//reverse a string in Java using StingBuilder
import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner sc= new Scanner(System.in); //System.in is a standard input stream   
        String str= sc.nextLine();  
        StringBuilder lowerCase = new StringBuilder();
            lowerCase.append(str);
            lowerCase.reverse();
            System.out.print(lowerCase[0].toLowerCase());
            System.out.print("You have entered: "+lowerCase);
    }
}