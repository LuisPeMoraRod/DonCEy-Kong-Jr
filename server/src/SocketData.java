
import java.io.*;

/**
 * Class that defines data to be sent via socket.
 */
public class SocketData implements Serializable
{
    private int length = 0;
    private String message = null;
    /**
     * Constructor method. Saves the String in word and gets its length to save it in length attribute.
     */
    public SocketData (String message)
    {
        if (message != null)
        {
            this.length = message.length();
            this.message = message;
        }
    }

    /**
     *  Returns string representation of data (length--message)
     */
    @Override
    public String toString ()
    {
        String result;
        result = Integer.toString(this.length) + " -- " + this.message;
        return result;
    }

    /**
     * Method to write the attributes of SocketData class in a DataOutputStream
     * so that C program is able to read them.
     */
    public void writeObject(java.io.DataOutputStream out)
            throws IOException
    {

        out.writeInt (this.length+1); //Send length of string + 1 because C requires to add \0 character

        out.writeBytes (this.message); //Sends string as bytes

        out.writeByte ('\0'); //appends \0 character
    }

    /**
     * Method that sets class attributes based on DataInputStream received from C program
     */
    public void readObject(java.io.DataInputStream in)
            throws IOException
    {
        this.length = in.readInt() - 1; //Reads the length of stream sent by C program and subtracts 1 (remove \0 char)

        byte [] aux = null; //Bytes array for the reading of the stream

        aux = new byte[this.length];
        in.read(aux, 0, this.length);
        this.message = new String (aux);
        in.read(aux,0,1);     // Reads \0
    }
}