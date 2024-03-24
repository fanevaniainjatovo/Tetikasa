<?php

	$cmd="sudo iptables -R ".$_POST['chain']." ".$_POST['numero']." -j ".$_POST['target']." -p ".$_POST['prot']." -s ".$_POST['source']." -d ".$_POST['destination'];
	shell_exec($cmd);
	header("Location: ./list.php");
?>
