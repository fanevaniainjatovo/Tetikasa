<?php	
	shell_exec("sudo iptables -D ".$_POST['chain']." ".$_POST['remove']);
	header("Location: ./list.php");
?>

