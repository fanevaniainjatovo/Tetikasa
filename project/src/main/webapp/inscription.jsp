<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<link rel="stylesheet" href="index.css">
<title>Inscription</title>
</head>
<body>
	<div id="container">
	<div id="form">
		<h1>Inscription</h1>
	 <form onsubmit="return validatePassWord()" action="http://localhost:8080/project/Sign" method="post">
    	<input required type="text" name="username">
    	<input id="p1" required type="password" name="pwd">
    	<input id="p2" required type="password" name="pwd1">
    	<button>S'inscrire</button>
    </form>
    <button><a href="./index.jsp">Se connecter</a></button>
    </div>
    	<div id="erreur">
			<%
			String msg=request.getParameter("msg");
			if(msg!=null){out.println(msg);}
			%>
		</div>
    </div>
    
    <script src="./passwd.js">	
    </script>
</body>
</html>