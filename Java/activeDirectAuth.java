import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

import com.microsoft.sqlserver.jdbc.SQLServerDataSource;


public class ActiveDirectoryAuthentication {

    public static void main(String[] args) {

        String serverName = null;
        String portNumber = null;
        String databaseName = null;
        String username = null;
        String password = null;
        String authentication = null;
        String hostNameInCertificate = null;

        try (InputStreamReader in = new InputStreamReader(System.in); BufferedReader br = new BufferedReader(in)) {

            System.out.println("For testing 'ActiveDirectoryIntegrated' Authentication, do one of the following:");
            System.out.println("   1. Generate Kerberos Ticket and validate its availability with klist tool, or");
            System.out.println("   2. Place sqljdbc_auth.dll in the same directory as the pom.xml file.");
            System.out.println(
                    "For testing 'ActiveDirectoryPassword' Authentication, none of the above setup is not required.");//
            System.out.println();

            // Start capturing database info
            System.out.print("Enter server name: ");
            serverName = br.readLine();
            System.out.print("Enter port number: ");
            portNumber = br.readLine();
            System.out.print("Enter database name: ");
            databaseName = br.readLine();
            System.out.print("Enter username: ");
            username = br.readLine();
            System.out.print("Enter password: ");
            password = br.readLine();
            System.out.print("Enter authentication: "); // e.g. ActiveDirectoryPassword / ActiveDirectoryIntegrated
            authentication = br.readLine();
            System.out.print("Enter host name in certificate: "); // e.g. *.database.windows.net
            hostNameInCertificate = br.readLine();

            // Establish the connection.
            SQLServerDataSource ds = new SQLServerDataSource();
            ds.setServerName(serverName);
            ds.setPortNumber(Integer.parseInt(portNumber));
            ds.setDatabaseName(databaseName);
            ds.setUser(username);
            ds.setPassword(password);
            ds.setAuthentication(authentication);
            ds.setHostNameInCertificate(hostNameInCertificate);

            try (Connection con = ds.getConnection(); Statement stmt = con.createStatement();) {
                System.out.println();
                System.out.println("Connection established successfully.");

                // Create and execute an SQL statement that returns user name.
                String SQL = "SELECT SUSER_SNAME()";
                try (ResultSet rs = stmt.executeQuery(SQL)) {

                    // Iterate through the data in the result set and display it.
                    while (rs.next()) {
                        System.out.println("user name: " + rs.getString(1));
                    }
                }
            }
        }
        // Handle any errors that may have occurred.
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}