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
	 <form onsubmit="return validatePassWord()" action="http://project/sign.php" method="post">
    	<input required type="text" name="username">
    	<input id="p1" required type="password" name="pwd">
    	<input id="p2" required type="password" name="pwd1">
    	<button>S'inscrire</button>
    </form>
    <button><a href="./index.php">Se connecter</a></button>
    </div>
    	<div id="erreur">
		<?php
			echo $_GET["msg"];
			
		?>
	</div>
    </div>
    
    <script src="./passwd.js">	
    </script>
</body>
</html>
