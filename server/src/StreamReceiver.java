import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class StreamReceiver implements Runnable{
    private Socket socket = null;
    private InputStream inputStream = null;
    private InputStreamReader reader = null;

    public StreamReceiver(Socket socket, InputStream inputStream){
        this.socket = socket;
        this.inputStream = inputStream;
        this.reader = new InputStreamReader(inputStream);
        receiveStream();
        closeConnection();
    }

    @Override
    public void run(){
        receiveStream();
        closeConnection();
    }

    private void receiveStream() {
        try{
            boolean game_over = false;
           // while(!game_over){
                int character;
                StringBuilder data = new StringBuilder();
                while ((character = this.reader.read()) != -1) {
                    if ((char) character =='.') // indica al cliente que es el final
                        break;
                    else{
                        data.append((char) character);
                    }
                }
                if (data.toString().equals("Over")){
                    game_over = true;
                }
                System.out.println(data);
           // }
        }
        catch (UnknownHostException ex) {
            System.out.println("Server not found: " + ex.getMessage());

        } catch (IOException ex) {
            System.out.println("I/O error: " + ex.getMessage());
        }
    }

    /**
     * Closes connections
     */
    private void closeConnection(){
        try{
            this.socket.close();
            this.inputStream.close();
        }
        catch(IOException i)
        {
            System.out.println(i);
        }

    }
}
