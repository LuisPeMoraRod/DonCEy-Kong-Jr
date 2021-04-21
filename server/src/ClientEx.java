
// A Java program for a Client
import java.net.UnknownHostException;
import java.net.Socket;
import java.io.*;

public class ClientEx
{
    // initialize socket and input output streams
    private Socket socket            = null;
    private DataInputStream  input   = null;
    private DataOutputStream out     = null;

    // constructor to put ip address and port
    public ClientEx(String address, int port)
    {
        // establish a connection
        try
        {
            socket = new Socket(address, port);
            System.out.println("Connected");
            InputStream input = socket.getInputStream();
            InputStreamReader reader = new InputStreamReader(input);
            int character;
            StringBuilder data = new StringBuilder();

            while ((character = reader.read()) != -1) {
                if ((char) character =='.') // indica al cliente que es el final
                    break;
                else{
                    data.append((char) character);
                }
            }

            System.out.println(data.toString());
            /*
            socket = new Socket(address, port);
            System.out.println("Connected");

            // takes input from terminal
            input  = new DataInputStream(System.in);

            // sends output to the socket
            out    = new DataOutputStream(socket.getOutputStream());
            System.out.println("Hi from java client.");
            out.writeUTF("Hi from java client");
            Socket sc = new Socket(HOST, port);

            //create the output stream object
            out = new DataOutputStream(sc.getOutputStream());

            //Send a new message to the Observer
            System.out.println("you can do this");
            out.writeUTF(message);

            //Close the socket
            sc.close();
            */
            out    = new DataOutputStream(socket.getOutputStream());
            String message = "you can do this";
            out.writeUTF(message);
        }
        catch(UnknownHostException u)
        {
            System.out.println(u);
        }
        catch(IOException i)
        {
            System.out.println(i);
        }

        input  = new DataInputStream(System.in);

        // string to read message from input
        String line = "";

        // keep reading until "Over" is input
        while (!line.equals("Over"))
        {
            try
            {
                line = input.readLine();
                out.writeUTF(line);
            }
            catch(IOException i)
            {
                System.out.println(i);
            }
        }

        // close the connection
        try
        {
            input.close();
            out.close();
            socket.close();
        }
        catch(IOException i)
        {
            System.out.println(i);
        }
    }

    public static void main(String args[])
    {
        ClientEx client = new ClientEx("127.0.0.1", 8080);
    }
}
