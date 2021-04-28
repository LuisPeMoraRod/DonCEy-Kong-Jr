

import java.io.*;
import java.util.*;
import java.net.*;

// Server class
public class Server2
{
    static Vector<ClientHandler2> players;
    static Vector<String> availableRoles;
    static int i;
    Integer playersCount;
    ServerSocket ss;
    Socket s;
    String playerName;

    public Server2() throws IOException {
        this.players = new Vector<>();
        this.playersCount = 0;
        this.ss  = new ServerSocket(1234);
        this.availableRoles = new Vector<>();
        availableRoles.add("Server");
        availableRoles.add("Player 1");
        availableRoles.add("Player 2");

        startServer();
    }

    public void startServer() throws IOException
    {

        Thread listenForConnection = new Thread(new Runnable()
        {
            @Override
            public void run() {
                while (true)
                {
                    // Accept the incoming request
                    playersCount = players.size();

                    if(playersCount<3){
                        System.out.println(players.size());
                        System.out.println("Listening for connection....");
                        try {
                            s = ss.accept();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        System.out.println("New client request received : " + s);

                        // obtain input and output streams
                        DataInputStream dis = null;
                        try {
                            dis = new DataInputStream(s.getInputStream());
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        DataOutputStream dos = null;
                        try {
                            dos = new DataOutputStream(s.getOutputStream());
                        } catch (IOException e) {
                            e.printStackTrace();
                        }

                        System.out.println("Creating a new handler for this client...");

                        playerName = availableRoles.get(0);

                        // Create a new handler object for handling this request.
                        ClientHandler2 mtch = new ClientHandler2(s,playerName, dis, dos);


                        availableRoles.remove(0);

                        // Create a new Thread with this object.
                        Thread t = new Thread(mtch);

                        System.out.println("Adding this client "+playerName+ " to active client list");

                        // add this client to active clients list
                        players.add(mtch);

                        // start the thread.
                        t.start();
/*
                        if(players.size()>1){
                            if(playerName.equals("Player 1")){
                                ServerGUIController.player1Active = true;
                            }
                            else{
                                ServerGUIController.player2Active = true;
                            }
                        }*/

                    }

                }
            }
        });

        listenForConnection.start();


    }

    public static void main(String[] args) throws IOException {
       Server2 server = new Server2();
    }
}


