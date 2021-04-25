package ServerGUI;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;

import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

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


    private VBox curentVB;
    private List<Integer> lianasList = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    private List<Integer> availablePlatfformList = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    private List<Integer> usedPlatfformList = Arrays.asList(0);



    public void goBack(ActionEvent actionEvent) {
        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);
    }

    public void goToCocoMenu(ActionEvent actionEvent) {
       mainVb.getChildren().remove(optionsVb);
       mainVb.getChildren().add(cocoVb);
       colorSelection.getItems().clear();

       colorSelection.getItems().add("Red");
       colorSelection.getItems().add("Blue");

       lianaSelection.getItems().clear();
       for(int i = 0; i < lianasList.size(); i++){
           lianaSelection.getItems().add(lianasList.get(i));
       }

       curentVB = cocoVb;
    }

    public void goToFruitMenu(ActionEvent actionEvent) {
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

        curentVB = fruitVb;
    }


    public List<String> removeBanana(ActionEvent actionEvent) {

        String selectedPlatform = (String) platformSelectionRemove.getValue();
        System.out.println(selectedPlatform);
        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);

        return null;
    }

    public void addCoco(ActionEvent actionEvent) {

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);
    }

    public void addBanana(ActionEvent actionEvent) {

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);
    }
}
