<!DOCTYPE html>
	<head>
	    <div id='title'>NETFILTER</div>
		<LINK rel=stylesheet type="text/css" href="./css/add.css">
		 <h2><center>
			 Ajout de nouveaux regles
		</center></h3>
	</head>
	<body>	
		<center>
			<a href="./list.php"><button>list of rules</button></a>
        </center>
		<fieldset>	
			<form action="./pare-feu.php" method="get">	
					
				Policy:<select name="action">
					<option value="ACCEPT">ACCEPT</option>
					<option value="DROP">DROP</option>
				</select>
				</br></br></br>
				Protocole:<input type="checkbox" id="prot" onclick="addProt('prot')"><div id="divProt"></div>			
				</br></br>
		<?php
			if($_GET['chain']=='INPUT'){
				echo "Interface d'entree:<input type='checkbox' id='ifaceIn' onclick='addIfaceIn()'><div id='divIfaceIn'></div></br></br>";
			}
			
			else if($_GET['chain']=='OUTPUT'){
				echo "Interface de sortie:<input type='checkbox' id='ifaceOut' onclick='addIfaceOut()'><div id='divIfaceOut'></div></br></br>";
                        }

			else{
				echo "Interface de sortie:<input type='checkbox' id='ifaceOut' onclick='addIfaceOut()'><div id='divIfaceOut'></div></br></br>";
				echo "Interface d'entree:<input type='checkbox' id='ifaceIn' onclick='addIfaceIn()'><div id='divIfaceIn'></div></br></br>";
			}
	
		echo "Adresse IP:<input type=\"checkbox\" id=\"ip\" onclick=\"destination('ip','optIP','addIP','divIP')\"><div id=\"divIP\"></div></br></br>";
		echo "Adresse MAC:<input type=\"checkbox\" id=\"mac\" onclick=\"addMac('mac')\"><div id=\"divMAC\"></div></br></br>";
				
				echo "<button id='valider' type='submit' name='chain' value=".$_GET['chain'].">appliquer</button></br></br>";
		?>

			</form>
		</fieldset>
		
	</body>
	
	<script src="./jquery-3.7.1.min.js"></script>	
	<script src="./affiche1.js"></script>
</html>	
