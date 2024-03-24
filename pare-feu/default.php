<?php

	shell_exec("sudo iptables -P ".$_GET["chain"]." ".$_GET["policy"]);
	header("Location: ./list.php");
?>
