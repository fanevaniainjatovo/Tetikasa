<?php
	$cmd="sudo iptables ";

	if(isset($_GET['action'])){
		$cmd=$cmd."-j ".$_GET['action']." ";
	}
	
	if(isset($_GET['chain'])){
		$cmd=$cmd."-A ".$_GET['chain']." ";	
	}

	if(isset($_GET['prot'])){ 
                $cmd=$cmd."-p ".$_GET['prot']." ";     
		
		if($_GET['nport']==1){
			if($_GET['optPort']=='destination'){
				$cmd=$cmd."--dport ".$_GET['port1'];
			}
			else{	
				$cmd=$cmd."--sport ".$_GET['port1'];
			}
		}

		else{
			if($_GET['optPort']=='destination'){	
				$cmd=$cmd."-m multiport --sports ";
			}
			else{	
				$cmd=$cmd."-m multiport --dports ";
			}
			for($i=1;$i<=$_GET['nport'];$i++){
				$cmd=$cmd.$_GET['port'.$i];
				if($i!=$_GET['nport']){$cmd=$cmd.',';}	
			}
		}
	}

	if(isset($_GET['ifaceOut'])){
		$cmd=$cmd."-o ".$_GET['ifaceOut'];
	}
	
	if(isset($_GET['ifaceIn'])){
                $cmd=$cmd."-i ".$_GET['ifaceIn'];
        }

	if(isset($_GET['optIP'])){
		if($_GET['optIP']=='destination'){$cmd=$cmd."-s ".$_GET['ip'];}
		else{$cmd=$cmd." -d ".$_GET['ip'];}
	}

	if(isset($_GET['mac'])){
		$cmd=$cmd." -m mac --mac-source ".$_GET['mac'];
	}

	echo $cmd;
	shell_exec($cmd);
?>
