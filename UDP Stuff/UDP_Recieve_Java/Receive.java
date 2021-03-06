import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Receive extends Thread {
 
    private DatagramSocket socket;
    private boolean running;
    private byte[] buf = new byte[256];
 
    public Receive() {
        socket = new DatagramSocket(50000);
    }
 
    public void run() {
        running = true;
 
        while (running) {
            DatagramPacket packet 
              = new DatagramPacket(buf, buf.length);
            socket.receive(packet);
             
            InetAddress address = packet.getAddress();
            int port = packet.getPort();
            packet = new DatagramPacket(buf, buf.length, address, port);
            String received 
              = new String(packet.getData(), 0, packet.getLength());
             
            if (received.equals("end")) {
                //running = false;
                continue;
            }
            socket.send(packet);
        }
        socket.close();
    }
}