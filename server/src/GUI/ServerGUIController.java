package GUI;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.layout.VBox;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

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
    private VBox playerVb;
    @FXML
    private ChoiceBox colorSelection;
    @FXML
    private ChoiceBox platformSelectionAdd;
    @FXML
    private ChoiceBox platformSelectionRemove;
    @FXML
    private ChoiceBox lianaSelection;
    @FXML
    private ChoiceBox fruitSelection;
    @FXML
    private Button addCocoBtn;
    @FXML
    private Button addBananaBtn;
    @FXML
    private Button removeBananaBtn;
    @FXML
    private Button player1Btn;
    @FXML
    private Button player2Btn;

    private VBox curentVB;
    private String playerSelected = "Player 1";


    Scanner scn = new Scanner(System.in);

    // getting localhost ip
    InetAddress ip = InetAddress.getByName("localhost");

    // establish the connection
    Socket s = new Socket(ip, 1234);

    // obtaining input and out streams
    DataInputStream dis = new DataInputStream(s.getInputStream());
    DataOutputStream dos = new DataOutputStream(s.getOutputStream());



    ControlLists controlLists = ControlLists.getInstance();

    public ServerGUIController() throws IOException {
    }

    public void goBack(ActionEvent actionEvent) {
        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(optionsVb);
    }

    public void goToCocoMenu(ActionEvent actionEvent) {

        if(controlLists.lianasList.size()==0){
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
       for(int i = 0; i < controlLists.lianasList.size(); i++){
           lianaSelection.getItems().add(controlLists.lianasList.get(i));
       }

       lianaSelection.getSelectionModel().selectFirst();
       colorSelection.getSelectionModel().selectFirst();



       curentVB = cocoVb;
    }

    public void goToFruitMenu(ActionEvent actionEvent) {

        if(controlLists.availablePlatformP1list.size()==0){
            platformSelectionAdd.setDisable(true);
            addBananaBtn.setDisable(true);
        }

        else{
            platformSelectionAdd.setDisable(false);
            addBananaBtn.setDisable(false);
        }

        if(controlLists.usedPlatformP1List.size()==0){
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

        for(int i = 0; i<controlLists.availablePlatformP1list.size(); i++){
            platformSelectionAdd.getItems().add(controlLists.availablePlatformP1list.get(i));
        }

        platformSelectionRemove.getItems().clear();

        for(int i = 0; i < controlLists.usedPlatformP1List.size(); i++){
            platformSelectionRemove.getItems().add(controlLists.usedPlatformP1List.get(i));
        }

        fruitSelection.getItems().clear();
        fruitSelection.getItems().add("Banana");
        fruitSelection.getItems().add("Mango");
        fruitSelection.getItems().add("Apple");

        platformSelectionAdd.getSelectionModel().selectFirst();
        platformSelectionRemove.getSelectionModel().selectFirst();
        fruitSelection.getSelectionModel().selectFirst();


        curentVB = fruitVb;
    }

    public void addCoco(ActionEvent actionEvent) {
        String cocoColorSelected = colorSelection.getSelectionModel().getSelectedItem().toString();
        String lianaSelected = lianaSelection.getSelectionModel().getSelectedItem().toString();
        String cocoCode;

        if(cocoColorSelected.equals("Red")){
            cocoCode = "0";
        }
        else{
            cocoCode = "1";
        }

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(playerVb);

        String message = "1;"+cocoCode+";"+lianaSelected+"#"+this.playerSelected;

        System.out.println(message);

        Platform.runLater(()->{
        try {
            // write on the output stream
            dos.writeUTF(message);
        } catch (IOException e) {
            e.printStackTrace();
        }});

    }

    public void addBanana(ActionEvent actionEvent) {
        String selectedPlatform = platformSelectionAdd.getSelectionModel().getSelectedItem().toString();
        String selectedFruit = fruitSelection.getSelectionModel().getSelectedItem().toString();
        String fruitCode;

        if(selectedFruit.equals("Banana")){
            fruitCode = "0";
        }
        else if(selectedFruit.equals("Mango")){
            fruitCode = "1";
        }
        else{
            fruitCode = "2";
        }

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(playerVb);

        this.controlLists.availablePlatformP1list.remove(selectedPlatform);
        this.controlLists.usedPlatformP1List.add(selectedPlatform);

        String message = "2;"+fruitCode+";"+selectedPlatform+"#"+this.playerSelected;

        Platform.runLater(()->{
            try {
                // write on the output stream
                dos.writeUTF(message);
            } catch (IOException e) {
                e.printStackTrace();
            }});

    }

    public void removeBanana(ActionEvent actionEvent) {

        String selectedPlatform = platformSelectionRemove.getSelectionModel().getSelectedItem().toString();

        mainVb.getChildren().remove(curentVB);
        mainVb.getChildren().add(playerVb);

        this.controlLists.usedPlatformP1List.remove(selectedPlatform);
        this.controlLists.availablePlatformP1list.add(selectedPlatform);

        String message = "3;Fruit;"+selectedPlatform+"#"+this.playerSelected;

        System.out.println(message);

        Platform.runLater(()->{
            try {
                // write on the output stream
                dos.writeUTF(message);
            } catch (IOException e) {
                e.printStackTrace();
            }});

    }

    public void goBackToPlayers(ActionEvent actionEvent) {
        mainVb.getChildren().remove(optionsVb);
        mainVb.getChildren().add(playerVb);
    }

    public void goToMainMenuP1(ActionEvent actionEvent) {
        this.playerSelected = player1Btn.getText();
        System.out.println(playerSelected);
        goToMainMenu();
    }

    public void goToMainMenuP2(ActionEvent actionEvent) {
        this.playerSelected = player2Btn.getText();
        System.out.println(playerSelected);
        goToMainMenu();
    }

    private void goToMainMenu() {
        mainVb.getChildren().remove(playerVb);
        mainVb.getChildren().add(optionsVb);
    }

}
