<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Accueil</title>
<link rel="stylesheet" href="index.css">
</head>

<body>
	<div id="container">
	<div id="form">
		<h1>Connexion</h1>
	    <form action="http://localhost:8080/project/Login" method="post">
    		<input placeholder="username" required type="text" name="username">
    		<input placeholder="password" required type="password" name="pwd">
    		<button>Se connecter</button>
    	</form>
    	<button><a href="./inscription.jsp">S'inscrire</a></button>
    </div>
    	<div id="erreur">
			<%
			String msg=request.getParameter("msg");
			if(msg!=null){out.println(msg);}
			%>
		</div>
    </div>
        
</body>
</html>