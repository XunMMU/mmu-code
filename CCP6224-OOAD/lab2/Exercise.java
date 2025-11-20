import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.OptionalInt;

public class Exercise {
    final private static Student stud = new Student(System.getProperty("user.name"), System.getProperty("os.name"));
    
    final private static BufferedReader inscanner = new BufferedReader(new InputStreamReader(System.in));

    private static void menu_out() {
        System.out.println("Choose an option to continue:");
        System.out.println("[1] Enter new subject\t\t[2] Remove subject");
        System.out.println("[3] Show Results \t\t[4] Quit");
    }

    private static String menu_in() throws IOException {
        System.out.print("-> ");
        return inscanner.readLine();
    }

    private static void menu_s1(){
        String sub,grd ;

        System.out.println("Enter subject code:");
        
        try {
            sub = inscanner.readLine().trim();
        } catch(IOException ioe) {
            System.err.println("IO Exception!!");
            return;
        }
        
        System.out.println("Enter result obtained");
        
        try {
            grd = inscanner.readLine().trim().toUpperCase();
        } catch(IOException ioe) {
            System.err.println("IO Exception!!");
            return;
        }
        if (grd.length() != 1){
            System.err.println("Not a Grade");
            return;
        }
        if ( ! stud.addSubject(sub, grd.charAt(0)) ){
            System.err.println("Dup Subject!!");
        }
    };

    private static void menu_s2(){
        String sub;
        System.out.println("Enter subject code to remove:");
        try {
            sub = inscanner.readLine().trim();
        } catch(IOException ioe) {
            System.err.println("IO Exception!!");
            return;
        }
        if ( stud.remSubject(sub) ){
            System.out.printf("Subject %s removed%n", sub);
        } else {
            System.err.println("Not such Subject!!");
        }
    }

    private static void menu_s3(){
        stud.printTranscript();
    }
    
    public static void main(String[] args) {
        OptionalInt menu_int;
         
        do{
            menu_int = OptionalInt.empty();
            
            menu_out();
            
            while (menu_int.isEmpty()){
                try{
                    String x = menu_in().trim();
                    if (x.length() ==0){
                        continue;
                    }
                    menu_int = OptionalInt.of(Integer.parseInt(x));
                }catch(IOException ioe){
                    System.err.println("IO Exception!!");
                    System.exit(1);
                }catch(NumberFormatException nfe){
                    System.err.println("Enter a number!!");
                }
            }

            switch (menu_int.getAsInt()) {
                case 1:
                menu_s1();
                break;
                case 2:
                menu_s2();
                break;
                case 3:
                menu_s3();
                break;
                case 4:
                continue;
              default:
                  System.err.println("OUT OF RANGE");
                break;
            }

            System.out.print("\n");
          
        } while (menu_int.getAsInt() != 4);
    }
}
