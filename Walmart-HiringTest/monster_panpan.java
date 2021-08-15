import java.util.*;

public class Main {
        public static boolean notValid(Character a){
            String str = "PANpan";
            boolean ans = true;
            for (int i=0;i<6;i++){
                if( Character.compare(str.charAt(i),a)>0){
                    ans = false;
                    break;
                }
            }
            return ans;
        }
     public static void toLowerCase(StringBuilder builder) {
        for (int i = 0; i < builder.length(); i++) {
            if (Character.isUpperCase(builder.charAt(i))) {
                builder.setCharAt(i,
                        Character.toLowerCase(builder.charAt(i)));
            }
        }
    }
    public static void main(String args[]) {
        
        Scanner sc= new Scanner(System.in);
    
        String ab=sc.nextLine();
        int K=Integer.parseInt(ab);  
        while(K>0){ //System.in is a standard input stream   
        K--;
        String str= sc.nextLine();
                    //reads string   
        int n = str.length();
        int i=0;
        boolean ans = true;
        while(i<n){
         StringBuilder upperCase = new StringBuilder();
         StringBuilder lowerCase = new StringBuilder();
             for(;i<n;i++){
            if(notValid(str.charAt(i))){
                ans = false;
                break;
            }
            else if(Character.isUpperCase(str.charAt(i))){
                upperCase.append(str.charAt(i));
            }
            else break;
        }
        if(!ans) break;

        for(;i<n;i++){
            if(Character.isLowerCase(str.charAt(i))){
                lowerCase.append(str.charAt(i));
            }
            else if(notValid(str.charAt(i))){
                ans = false;
                break;
            }
            else break;
        }
        if(!ans) break;

        // reverse StringBuilder input1
        toLowerCase(upperCase);
        upperCase.reverse();
        ans = upperCase.toString().equals(lowerCase.toString());
        if(!ans) break;
    }
    if(ans){
        System.out.println("Feed");
    }
    else{
        System.out.println("Throw");
    }
    }
  }
}