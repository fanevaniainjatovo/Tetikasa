<?php
	$cmd=shell_exec("ifconfig");
	$T=explode("\n\n",$cmd);
	$iface=array();

	for($i=0;$i<count($T);$i++){
		sscanf($T[$i],"%[^:]",$iface[$i]);
	}

	echo "<select name='ifaceIn'>".
		"<optgroup label='Interface reseau'>";
		for($i=0;$i<count($T);$i++){	
                        echo "<option value=".$iface[$i].">".$iface[$i]."</option>";
		}		
	echo	"</optgroup>".
        "</select>";
?>
