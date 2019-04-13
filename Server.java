import java.io.*;
import java.net.*;
import java.lang.*;
public class Server 
{
	public static void main(String[] args) throws Exception
	{
		System.out.println("Server waiting for connection from client");
		ServerSocket ss = new ServerSocket(4444);
		Socket sock = ss.accept();
		
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
	                      
                OutputStream ostream = sock.getOutputStream(); 
                PrintWriter pwriter = new PrintWriter(ostream, true);

                InputStream istream = sock.getInputStream();
                BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));

      String receiveMessage, sendMessage;               
      while(true)
      {
        if((receiveMessage = receiveRead.readLine()) != null)  
        {
           System.out.println(receiveMessage);         
        }         
        sendMessage = keyRead.readLine(); 
        pwriter.println(sendMessage);             
        pwriter.flush();
      }               
    }                    
}                        
