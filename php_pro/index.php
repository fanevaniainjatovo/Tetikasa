
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
	    <form action="./login.php" method="post">
    		<input placeholder="username" required type="text" name="username">
    		<input placeholder="password" required type="password" name="pwd">
    		<button>Se connecter</button>
    	</form>
    	<button><a href="./inscription.php">S'inscrire</a></button>
    </div>
	<div id="erreur">
		<?php
			echo $_GET["msg"];	
		?>
	</div>	
    </div>
        
</body>
</html>
