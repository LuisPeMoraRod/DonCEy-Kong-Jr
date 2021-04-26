package ServerGUI;

import java.util.List;
import java.util.Vector;

public final class ControlLists {

    private static ControlLists instance;

    public List<String> lianasList = new Vector<String>(11);
    public List<String> availablePlatfformList = new Vector<String>(10);
    public List<String> usedPlatfformList= new Vector<String>(10);

    private ControlLists(){
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }

        for(int i = 1; i<=11; i++){
            this.lianasList.add(String.valueOf(i));
        }

        for (int i = 1; i<=10; i++){
            this.availablePlatfformList.add(String.valueOf(i));
        }
    }

    public static ControlLists getInstance(){
        if (instance == null) {
            instance = new ControlLists();
        }
        return instance;
    }
}
