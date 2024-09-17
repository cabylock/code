
import java.util.*;




public class recursive_digit_sum {
     public static int superDigit(String n, int k) 
    {
    // Write your code here
    Long sum = 0l  ;
    if(n.length()==1)
    {
        return n.charAt(0) - '0';
    }
    for( int i = 0 ; i< n.length(); i++)
    {
        sum+= n.charAt(i) -'0';
        
    }
    
    sum *=k;
    return superDigit( sum.toString(), 1);

    }

    public static void main(String[] args) 
    {    
         Scanner sc = new Scanner(System.in);
         String n = sc.next();
         int k = sc.nextInt();
         System.out.println(superDigit(n, k));
         sc.close();
    }

  
}









