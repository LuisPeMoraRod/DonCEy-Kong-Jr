// Java implementation of Server side
// It contains two classes : Server and ClientHandler
// Save file as Server.java

import java.io.*;
import java.util.*;
import java.net.*;

// Server class
public class Server
{
    static Vector<ClientHandler> players;
    static boolean ob1P1Active = false;
    static boolean ob2P1Active = false;
    static boolean ob1P2Active = false;
    static boolean ob2P2Active = false;

    Integer playersCount;
    ServerSocket ss;
    Socket s;

    public Server() throws IOException {
        this.players = new Vector<>();
        this.playersCount = 0;
        this.ss  = new ServerSocket(1234);

        startServer();
    }

    public void startServer() throws IOException {

        Thread listenForConnection = new Thread(new Runnable()
        {
            @Override
            public void run() {
                while (true) {

                    playersCount = players.size();

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


                        // Create a new handler object for handling this request.
                        ClientHandler mtch = new ClientHandler(s," ", dis, dos);


                        // Create a new Thread with this object.
                        Thread t = new Thread(mtch);

                        System.out.println("Adding this client to active client list");

                        // add this client to active clients list
                        players.add(mtch);

                        // start the thread.
                        t.start();

                    }

                }
        });

        listenForConnection.start();


    }
}


