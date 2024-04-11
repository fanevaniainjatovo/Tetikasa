<%@page import="java.util.Random"
		import="java.io.BufferedReader"
		import="java.io.File"
		import="java.io.FileReader"
		import="java.io.IOException"
%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<link rel="stylesheet" href="mot.css">
<title>Mot</title>
</head>
<body>
	<div id="container">
	<div id="grid">
    	<%	
    		int r=(int)(1+Math.random()*10);
    		
    		String id=(String)request.getParameter("id");
    		char a=(char)(r+64);
    		if(id!=null){
    			char[] tmp=id.toCharArray();
    			a=tmp[0];	
    		}
    		
    		for(int i=1;i<=4;i++){
    			out.print("<img src='./images/"+a+i+".jpeg'>");
    		}
    	%>    
    </div>
    	<form action="http://localhost:8080/project/Mot" method="post">     
		    <input placeholder="reponse" type="text" name="reponse">
    	
    		<% 	
    			out.print("<button name=case value="+a+">Valider</button>");
			%>
		
		</form>
			<%
			String msg=request.getParameter("msg");
			if(msg!=null){
				String color;
				if(msg.equals("Mauvaise reponse")){
					color="red";
				}	
				else{
					color="green";
				}
				out.println("<div style='background-color:"+color+"' id='erreur'>");
				out.println(msg+"</div>");
			}
			%>

				
    </div>
    
</body>
</html>