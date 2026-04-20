package q4;

import java.util.ArrayList;

public class Warship extends Starship {

    private ArrayList<Weapon> weapons;

    public Warship(String name, ArrayList<Weapon> weapons) {
        super(name);
    }

    public Warship(String name, Weapon weapon) {
        super(name);
    }

    public Warship(String name) {
        super(name);
    }

    public ArrayList<Weapon> getWeapons() {
        return weapons;
    }

    public void addWeapon(Weapon weapon) {}

    public boolean removeWeapon(Weapon weapon) {
        return true;
    }
}
