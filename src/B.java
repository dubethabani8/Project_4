public class B{

     public static void main(String []args){
         String str = "[[(((";
        System.out.println(B(str));
     }
     
    static String B(String s){
    for(int i=0; i<s.length(); i++){
        if(s.charAt(i) == '(') s.charAt(i) = '[';
    }
    return s;
}
}
