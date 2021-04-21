import java.net.*;
import java.io.*;

/**
 * Main class that instantiates a server socket, accepts a connection from
 * a client and send an int and a string.
 */
public class Server
{
    private int port = 0;
    private Socket socket            = null;
    private ServerSocket serverSocket = null;
    private DataInputStream inputUser = null;
    private InputStream inputStream = null;
    private DataOutputStream output     = null;
    /**
     * Constructor method
     */
    public Server(int port)
    {
        this.port = port;
        createSocket(this.port);
        //sendStream();
        //receiveStream();
        StreamReceiver streamReceiver = new StreamReceiver(socket, inputStream);
        Thread receiverThread = new Thread(streamReceiver);

        StreamSender streamSender = new StreamSender(this.inputUser, this.output);
        Thread senderThread = new Thread(streamSender);

        //senderThread.start();
        receiverThread.start();

    }

    /**
     * Creates socket as a server
     * @return void
     */
    private void createSocket(int port){
        try
        {
            this.serverSocket = new ServerSocket(this.port);
            System.out.println("Server started\nWaiting for a client...");
            //socket = new Socket(ipAddress, port);
            this.socket = serverSocket.accept();
            System.out.println("A client connected to Java server...");
            this.output = new DataOutputStream(this.socket.getOutputStream());
            this.inputUser = new DataInputStream(System.in); //input from console
            this.inputStream = socket.getInputStream(); //input from socket stream
        }
        catch(UnknownHostException u)
        {
            System.out.println(u);
        }
        catch(IOException i)
        {
            System.out.println(i);
        }

    }

    public static void main (String [] args)
    {
        new Server(8081);
    }
}

