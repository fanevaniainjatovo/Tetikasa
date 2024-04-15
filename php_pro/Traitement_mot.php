<?php
	$file=fopen("connex.txt","r");
	$curuser=fgets($file);
	
	$case = $_POST["case"];
	$rep = $_POST["reponse"];
	
	$servername="127.0.0.1";
        $database="project";
        $user="mit";
        $mdp="123456";
	
	$connex=new mysqli($servername,$user,$mdp,$database);

        if($connex->connect_error){
                die("erreur");
        }
	
	$query="select * from mot where `case`='$case'";
	$data=$connex->query($query);
	$row=$data->fetch_assoc();
	
	if($row["reponse"] == $rep){
		header("Location: ./mot.php?msg=Bravo, bonne reponse");
	}
	
	else{
		header("Location: ./mot.php?msg=Mauvaise reponse&id=$case");
	}

?>
