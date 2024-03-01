<html>
	<body>
	<?php
		$nl=$_POST["bouton"];	
		echo "<form action=\"./modifier.php\" method=\"get\">
                        <input name=\"x\" type=\"number\">
                        </br>
                        <input name=\"y\" type=\"number\">
                        <button type=\"submit\" name=\"line\" value=\"$nl\">modifier</button>
        	</form>
		";
	?>
	</body>
</html>
