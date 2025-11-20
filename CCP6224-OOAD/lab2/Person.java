public abstract class Person {

    private String name;
    private String gender;

    public Person(String nm, String gen) {
        this.name = nm;
        this.gender = gen;
    }

    public String getName() {
        return name;
    }

    public String getGender() {
        return gender;
    }

    //abstract method
    public abstract String toString();
}
