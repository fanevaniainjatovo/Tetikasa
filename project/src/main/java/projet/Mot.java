package projet;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.sql.Statement;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Servlet implementation class Mot
 */
public class Mot extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Mot() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String cas=(String)request.getParameter("case");
		String rep=(String)request.getParameter("reponse");
		PrintWriter p=response.getWriter();
		
		p.println(cas);
		p.println(rep);
		
		Connection c=null;
		Statement st=null;
		ResultSet res=null;
		
		try {
		
			Class.forName("com.mysql.cj.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/project";
			String user="mit";
			String pwd="123456";
		
			c = DriverManager.getConnection(url,user,pwd);
			if(c != null) {
				p.println("Data ouvert");
				st = (Statement) c.createStatement();
				res = st.executeQuery("select * from mot where `case`='"+cas+"'");
				while(res.next()) {
					String vrep=res.getString("reponse");
					String message;
					if(vrep.equals(rep)){
						message="Bravo, bonne reponse";
						response.sendRedirect("http://localhost:8080/project/mot.jsp?msg="+message);	
					}
					else {
						message="Mauvaise reponse";
						response.sendRedirect("http://localhost:8080/project/mot.jsp?id="+cas+"&msg="+message);
					}
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
