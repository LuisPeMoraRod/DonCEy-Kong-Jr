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
    public ClientHandler(Socket s, String name,
                         DataInputStream dis, DataOutputStream dos) {
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

                if(received.equals("logout")){
                    this.isloggedin=false;
                    this.s.close();
                    break;
                }

                // break the string into message and recipient part
                StringTokenizer st = new StringTokenizer(received, "#");
                String MsgToSend = st.nextToken();
                String recipient = st.nextToken();

                // search for the recipient in the connected devices list.
                // ar is the vector storing client of active users
                for (ClientHandler mc : Server.players)
                {
                    // if the recipient is found, write on its
                    // output stream
                    if (mc.name.equals(recipient) && mc.isloggedin==true)
                    {
                        mc.dos.writeUTF(MsgToSend);
                        break;
                    }
                }

            } catch (IOException e) {

                try {
                    this.isloggedin = false;
                    if(this.name.equals("Player 1")){
                        ServerGUIController.controlLists.restartList("Player 1");
                        ServerGUIController.player1Active = false;
                    }
                    else{
                        ServerGUIController.controlLists.restartList("Player 2");
                        ServerGUIController.player2Active = false;
                    }

                    Server.availableRoles.add(0, this.name);
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