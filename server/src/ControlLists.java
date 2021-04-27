import java.util.List;
import java.util.Vector;

public final class ControlLists {

    private static ControlLists instance;

    public List<String> lianasList = new Vector<String>(11);
    public List<String> availablePlatformP1list = new Vector<String>(10);
    public List<String> usedPlatformP1List = new Vector<String>(10);
    public List<String> availablePlatformP2list = new Vector<String>(10);
    public List<String> usedPlatformP2List = new Vector<String>(10);

    private ControlLists(){
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }

        for(int i = 0; i<=10; i++){
            this.lianasList.add(String.valueOf(i));
        }

        for (int i = 0; i<=9; i++){
            this.availablePlatformP1list.add(String.valueOf(i));
        }

        for (int i = 0; i<=9; i++){
            this.availablePlatformP2list.add(String.valueOf(i));
        }
    }

    public void restartList(String player){
        if(player.equals("Player 1")){
            availablePlatformP1list.clear();
            for (int i = 0; i<=9; i++){
                this.availablePlatformP1list.add(String.valueOf(i));
            }
            this.usedPlatformP1List.clear();

        }
        else{
            availablePlatformP2list.clear();
            for (int i = 0; i<=9; i++){
                this.availablePlatformP2list.add(String.valueOf(i));
            }
            this.usedPlatformP2List.clear();
        }
    }

    public static ControlLists getInstance(){
        if (instance == null) {
            instance = new ControlLists();
        }
        return instance;
    }
}
