<?php
	$nom=$_POST["username"];	
	$password=$POST["password"];

	$servername="127.0.0.1";
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
		if($nom == $row["nom"] && $mdp == $row["mdp"]){
		 	$a=1;
			$f= fopen("connex.txt","w");
			fwrite($f,$nom);			
			header("Location: ./mot.php");
		}
	}

	if($a==0){
		header("Location: http://project/index.php?msg=Login incorrect");
	}

?>

