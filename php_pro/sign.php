<?php
	$nom=$_POST["username"];	
	
	$servername="localhost";
	$database="project";
	$user="mit";
	$mdp="123456";

	$connex=new mysqli($servername,$user,$mdp,$database);
	
	if($connex->connect_error){
		die("erreur");
	}
	
	$a=0;
	$query = "select * from gamer";
	$data = $connex->query($query);
	
	while($row = $data->fetch_assoc()){
		if($nom == $row["nom"]){
			header("Location: http://project/index.jsp?msg=Utilisateur existant deja!!");
			break;
		}
		else{
			$a=1;
		}

	}

	if($a==1){
		$connex->query("insert into gamer(nom,mdp) values ('$nom','$password')");
		header("Location: http://project/index.php?msg=Vous etes inscrits $nom");
		
	}

?>
