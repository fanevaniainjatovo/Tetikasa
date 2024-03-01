<html>
	<head>
		<h1>TABLE DE MULTIPLICATION</h1>
	</head>
	<body>
		<form action="./tabMulti.php" method="post">
			<input name="a" type="number">
			</br>
			<input name="b" type="number">
			<button type="submit">envoyer</button>
		</form>	
	<?php

	$x=$_POST["a"];
	$y=$_POST["b"];
	
	$modif=$_GET["modif"];
	if(!isset($modif)){$modif=1;}
	if($modif){
		$fichier=fopen("table.txt","w+");
		for($i=1;$i<=$y;$i++){		
			$rep=$i*$x;
			fwrite($fichier,$i.",".$x.",".$rep."\n");		
		}
		fclose($fichier);
	}	
	echo "<style>
			td{
				padding-left:50px;	
				padding-right:50px;
				
				padding-top:10px;
				padding-bottom:10px;
			}
			
			h1{
				text-align: center;
			}
			
			table{
				display: flex;
				justify-content: center;
			}		
	     </style>	
		";
	$fichier1=fopen("table.txt","r");	
	
	echo "<table border=\"1\">
	<tr style=\"background-color:#5CC05C;color: #00044A;font-size: 15pt;\">
		<td>A</td>
		<td>B</td>
		<td>A*B</td>
		<td>MODIFICATION</td>
		<td>SUPPRESSION</td>
	</tr>	
	";
	for($i=1;$line=fgets($fichier1);$i++){
		$elmt=explode(",",$line);

		$color=($i%2==0)?"#827EB8":"#4BA84D";
		echo "<tr style=\"background-color:$color\"> 
 				<td>$elmt[0]</td> 
		   		<td>$elmt[1]</td> 
				<td>$elmt[2]</td>
				<td> 
				   <form method=\"post\" action=\"formModif.php\">	
					<button type=\"submit\" name=\"bouton\" value=$i>modifier</button> 
				   </form>
				</td>
				<td>
				   <a href=\"./modifier.php?line=$i&del=0\">supprimer</a>
				</td>
		      </tr>";	
	}
 	echo "</table>";
	fclose($fichier); 
	?>

      </body>
</html>
