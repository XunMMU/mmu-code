package q2;

public class Employee {

    private int id;
    private String department = "Sales";

    private Employee() {}

    protected Employee(int i) {}

    public String getDepartment() {
        return department;
    }

    public int getID() {
        return id;
    }
}
