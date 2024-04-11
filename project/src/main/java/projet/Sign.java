package projet;

import projet.Gamer;
import jakarta.servlet.ServletException;
import jakarta.servlet.ServletResponse;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Servlet implementation class Sign
 */
public class Sign extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Sign() {
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
				st = (Statement) c.createStatement();
				res = st.executeQuery("select * from gamer");
				
				while(res.next()) {
					String nom=res.getString("nom");
					p.print(nom+" "+g.nom+"\n");
					
					if(nom.equals(g.nom)) {
						a=0;
						response.sendRedirect("http://localhost:8080/project/inscription.jsp?msg=Utilisateur deja existant");
						break;
					}
					else {
						a=1;
					}
				
				}
				if(a==1){
					st.executeUpdate("insert into gamer(nom,mdp) values ('"+g.nom+"','"+g.mdp+"')");
					response.sendRedirect("http://localhost:8080/project/index.jsp");
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
