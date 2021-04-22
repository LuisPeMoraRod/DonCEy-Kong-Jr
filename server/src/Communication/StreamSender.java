package Communication;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class StreamSender implements Runnable{
    private DataInputStream inputUser = null;
    private DataOutputStream output     = null;
    public StreamSender(DataInputStream inputUser, DataOutputStream output){
        this.inputUser = inputUser;
        this.output = output;
    }

    @Override
    public void run(){
        sendStream();
        closeConnections();
    }

    /**
     * Sends data to C client
     */
    private void sendStream(){
        System.out.println("Write your message: \n");
        String message = "";
        // keep reading until "Over" is input
        while (!message.equals("Over"))
        {
            try
            {
                message = this.inputUser.readLine();
                this.output.writeUTF(message);
            }
            catch(IOException i)
            {
                System.out.println(i);
            }
        }
    }

    /**
     * Closes streams I/O
     */
    private void closeConnections(){
        try
        {
            System.out.println("Closing socket...");
            this.inputUser.close();
            this.output.close();
        }
        catch(IOException i)
        {
            System.out.println(i);
        }
    }
}
