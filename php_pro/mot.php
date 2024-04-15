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
    	<?	
    		$r=rand(1,10); 		
    		$id=$_GET["id"];    		
		$a=chr($r+64);

    		if(isset($id)){
    			$a=$id;	
    		}
    		
    		for($i=1;$i<=4;$i++){
    			echo "<img src='./images/".$a.$i.".jpeg'>";
    		}
    	?>    
    </div>
    	<form action="http://project/Traitement_mot.php" method="post">     
		    <input placeholder="reponse" type="text" name="reponse">
    	
    		<?php	
    		     echo "<button name=case value=".$a.">Valider</button>";
		?>
		
		</form>
			<?php
			$msg=$_GET["msg"];
			if(isset($msg)){
				$color;
				if($msg=="Mauvaise reponse"){
					$color="red";
				}	
				else{
					$color="green";
				}
				echo "<div style='background-color:".$color."' id='erreur'>";
				echo $msg."</div>";
			}
			?>

				
    </div>
    
</body>
</html>
