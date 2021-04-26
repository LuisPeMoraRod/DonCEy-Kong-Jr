package ServerGUI;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.layout.VBox;
import java.util.List;
import java.util.Vector;

public class ServerGUIController {

    @FXML
    private VBox optionsVb;
    @FXML
    private VBox mainVb;
    @FXML
    private VBox cocoVb;
    @FXML
    private VBox fruitVb;
    @FXML
    private ChoiceBox colorSelection;
    @FXML
    private ChoiceBox platformSelectionAdd;
    @FXML
    private ChoiceBox platformSelectionRemove;
    @FXML
    private ChoiceBox lianaSelection;
    @FXML
    private Button addCocoBtn;
    @FXML
    private Button addBananaBtn;
    @FXML
    private Button removeBananaBtn;


    private VBox curentVB;
    private List<String> lianasList = new Vector<String>(11);
    private List<String> availablePlatfformList = new Vector<String>(11);
    private List<String> usedPlatfformList= new Vector<String>(11);

    public void initLists(){
        for(int i = 1; i<=11; i++){
            this.lianasList.add(String.valueOf(i));
        }

        for (int i = 1; i<=10; i++){
            this.availablePlatfformList.add(String.valueOf(i));
        }
    }

    public void goBack(ActionEvent actionEvent) {
        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);
    }

    public void goToCocoMenu(ActionEvent actionEvent) {

        if(lianasList.size()==0){
            lianaSelection.setDisable(true);
            addCocoBtn.setDisable(true);
        }

        else{
            lianaSelection.setDisable(false);
            addCocoBtn.setDisable(false);
        }

       mainVb.getChildren().remove(optionsVb);
       mainVb.getChildren().add(cocoVb);
       colorSelection.getItems().clear();

       colorSelection.getItems().add("Red");
       colorSelection.getItems().add("Blue");

       lianaSelection.getItems().clear();
       for(int i = 0; i < lianasList.size(); i++){
           lianaSelection.getItems().add(lianasList.get(i));
       }

       lianaSelection.getSelectionModel().selectFirst();
       colorSelection.getSelectionModel().selectFirst();



       curentVB = cocoVb;
    }

    public void goToFruitMenu(ActionEvent actionEvent) {

        if(availablePlatfformList.size()==0){
            platformSelectionAdd.setDisable(true);
            addBananaBtn.setDisable(true);
        }

        else{
            platformSelectionAdd.setDisable(false);
            addBananaBtn.setDisable(false);
        }

        if(usedPlatfformList.size()==0){
            platformSelectionRemove.setDisable(true);
            removeBananaBtn.setDisable(true);
        }

        else{
            platformSelectionRemove.setDisable(false);
            removeBananaBtn.setDisable(false);
        }

        mainVb.getChildren().remove(optionsVb);
        mainVb.getChildren().add(fruitVb);

        platformSelectionAdd.getItems().clear();

        for(int i = 0; i<availablePlatfformList.size(); i++){
            platformSelectionAdd.getItems().add(availablePlatfformList.get(i));
        }

        platformSelectionRemove.getItems().clear();

        for(int i = 0; i < usedPlatfformList.size(); i++){
            platformSelectionRemove.getItems().add(usedPlatfformList.get(i));
        }

        platformSelectionAdd.getSelectionModel().selectFirst();
        platformSelectionRemove.getSelectionModel().selectFirst();

        curentVB = fruitVb;
    }

    public String addCoco(ActionEvent actionEvent) {
        String cocoColorSelected = colorSelection.getSelectionModel().getSelectedItem().toString();
        String lianaSelected = lianaSelection.getSelectionModel().getSelectedItem().toString();

        this.lianasList.remove(lianaSelected);

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);

        String message = "1;"+cocoColorSelected+";"+lianaSelected;

        System.out.println(message);

        return message;
    }

    public String addBanana(ActionEvent actionEvent) {
        String selectedPlatform = platformSelectionAdd.getSelectionModel().getSelectedItem().toString();

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);

        this.availablePlatfformList.remove(selectedPlatform);
        this.usedPlatfformList.add(selectedPlatform);

        String message = "2;"+selectedPlatform;

        System.out.println(message);

        return message;
    }

    public String removeBanana(ActionEvent actionEvent) {

        String selectedPlatform = platformSelectionRemove.getSelectionModel().getSelectedItem().toString();

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);

        this.usedPlatfformList.remove(selectedPlatform);
        this.availablePlatfformList.add(selectedPlatform);

        String message = "3;"+selectedPlatform;

        System.out.println(message);

        return message;
    }

}
