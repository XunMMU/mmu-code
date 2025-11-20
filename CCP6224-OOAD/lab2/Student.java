import java.util.ArrayList;

public class Student extends Person {
  private final ArrayList<Subject> sub_arr = new ArrayList<>();
  
  public Student(String nm, String gen){
    super(nm, gen);
  }

  public String toString(){
    return String.format("");
  }

  boolean addSubject(String cd,char res){
    for(final Subject x : this.sub_arr){
      if(x.getCode() == cd){
        return false;
      }      
    }
    this.sub_arr.add(new Subject(cd, res));
    return true;
  }

  boolean remSubject(String cd){
    return this.sub_arr.removeIf((x)->{
      return x.getCode().equals(cd); // may remove more than one subject, add subject needed to prevent that.
    });
  }

  void printTranscript(){
    System.out.printf("Student name: %s%n", this.getName());
    this.sub_arr.forEach((x) -> {
      System.out.printf("Subject:%s - %c%n", x.getCode(), x.getResult());
    });
  }
}
