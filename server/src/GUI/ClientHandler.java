package GUI;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;
import java.util.StringTokenizer;

// ClientHandler class
class ClientHandler implements Runnable
{

    Scanner scn = new Scanner(System.in);
    private String name;
    final DataInputStream dis;
    final DataOutputStream dos;
    Socket s;
    boolean isloggedin;


    // constructor
    public ClientHandler(Socket s, String name, DataInputStream dis, DataOutputStream dos) {
        this.dis = dis;
        this.dos = dos;
        this.name = name;
        this.s = s;
        this.isloggedin=true;
    }


    @Override
    public void run() {

        String received;
        while (this.isloggedin)
        {
            try
            {
                // receive the string
                received = dis.readUTF();

                System.out.println(received);

                switch (received.charAt(0)){
                    case '0':
                        switch (received.charAt(2)){
                            case '0':
                                if(!ServerGUIController.player1Active){
                                    this.name = "Player 1";
                                    ServerGUIController.player1Active = true;
                                }
                                else{
                                    System.out.println("There's already a player 1");
                                }
                                break;
                            case '1':
                                if(!ServerGUIController.player2Active){
                                    this.name = "Player 2";
                                    ServerGUIController.player2Active = true;
                                }
                                else{
                                    System.out.println("There's already a player 2");
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case '1':
                        switch (received.charAt(2)){
                            case '0':
                                if(!Server.ob1P1Active){
                                    this.name = "Observer 1P1";
                                    Server.ob1P1Active = true;
                                }
                                else if(!Server.ob2P1Active){
                                    this.name = "Observer 2P1";
                                    Server.ob2P1Active = true;
                                }
                                else{
                                    System.out.println("There are already 2 observers for player 1");
                                }
                                break;
                            case '1':
                                if(!Server.ob1P2Active){
                                    this.name = "Observer 1P2";
                                    Server.ob1P2Active = true;
                                }
                                else if(!Server.ob2P2Active){
                                    this.name = "Observer 2P2";
                                    Server.ob2P2Active = true;
                                }
                                else{
                                    System.out.println("There are already 2 observers for player 2");
                                }
                                break;
                            default:
                                break;

                        }

                        break;

                    case '4':
                        StringTokenizer st = new StringTokenizer(received, ";");
                        String action = st.nextToken();
                        String movement = st.nextToken();

                        if(this.name.equals("Player 1")){
                            for (ClientHandler mc : Server.players) {
                                // if the recipient is found, write on its
                                // output stream
                                if (mc.name.equals("Observer 1P1") || mc.name.equals("Observer 2P1"))
                                {
                                    System.out.println("Observer pl1");
                                    mc.dos.writeUTF(movement);
                                }
                            }

                        }
                        else{

                            for (ClientHandler mc : Server.players) {
                                // if the recipient is found, write on its
                                // output stream
                                if (mc.name.equals("Observer 1P2") || mc.name.equals("Observer 2P2"))
                                {
                                    mc.dos.writeUTF(movement);
                                }
                            }

                        }

                    break;
                }

            } catch (IOException e) {

                try {
                    this.isloggedin = false;
                    if(this.name.equals("Player 1")){
                        ServerGUIController.controlLists.restartList("Player 1");
                        ServerGUIController.player1Active = false;
                    }
                    else if(this.name.equals("Player 2")){
                        ServerGUIController.controlLists.restartList("Player 2");
                        ServerGUIController.player2Active = false;
                    }
                    else if(this.name.equals("Observer 1P1")){
                        Server.ob1P1Active = false;
                    }

                    else if(this.name.equals("Observer 2P1")){
                        Server.ob2P1Active = false;
                    }
                    else if(this.name.equals("Observer 1P2")){
                        Server.ob1P2Active = false;
                    }
                    else{
                        Server.ob2P2Active = false;
                    }

                    Server.players.remove(this);

                    this.s.close();
                    this.dis.close();
                    this.dos.close();
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }

        }

    }
}