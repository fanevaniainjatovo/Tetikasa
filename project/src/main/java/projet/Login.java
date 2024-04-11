package projet;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Servlet implementation class Login
 */
public class Login extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Login() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		Gamer g=new Gamer();
		
		g.nom=request.getParameter("username");
		g.mdp=request.getParameter("pwd");
		
		Connection c=null;
		Statement st=null;
		ResultSet res=null;
		PrintWriter p=response.getWriter();
		
		try {
		
			Class.forName("com.mysql.cj.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/project";
			String user="mit";
			String pwd="123456";
			int a=0;
			
			c = DriverManager.getConnection(url,user,pwd);
			if(c != null) {
				p.println("Data ouvert");
				st = (Statement) c.createStatement();
				res = st.executeQuery("select * from gamer");
				while(res.next()) {
					String nom=res.getString("nom");
					String mdp=res.getString("mdp");
					if(nom.equals(g.nom) && mdp.equals(g.mdp)) {
						a=1;
						
						try {
							BufferedWriter f=new BufferedWriter(new FileWriter("/home/faneva/eclipse-workspace/project/src/main/webapp/connex.txt"));
							p.println(g.nom);
							f.write(g.nom+"\n");
							f.close();
						}
						
						catch(IOException e) {
							p.println("Tsy voasokatra");
						}
						
						response.sendRedirect("http://localhost:8080/project/mot.jsp");
						break;
					}
					else {
						a=0;
					}
				}
				if(a==0){
						response.sendRedirect("http://localhost:8080/project/index.jsp?msg=Login ou Mot de passe incorrect");
				}	
			}		
		}
		catch(ClassNotFoundException e) {
			e.printStackTrace();	
		}
		catch(SQLException e) {
			e.printStackTrace();
		}
		finally {
			try {
				if(c!=null) {c.close();}
			}
			catch(SQLException e) {
				e.printStackTrace();
			}
		}
	}

}
