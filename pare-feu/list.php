<!DOCTYPE html>

	<head>
		<div id='title'>NETFILTER</div>
		<LINK rel=stylesheet type="text/css" href="./css/list.css">
	</head>	
	
	<body>
		<?php
		echo "<center>";	
		$list=shell_exec("sudo iptables --line-number -L");
		$T=explode("\n\n",$list);
		
		$Tin=explode("\n",$T[0]);	
		$Tfor=explode("\n",$T[1]);	
		$Tout=explode("\n",$T[2]);
		unset($Tout[count($Tout)-1]);
		
		$chain=$_POST["chain"];
		if(empty($chain)){$chain='ALL';}
		echo "<form action='./list.php' method='POST'>";
			echo "<div id='change'><button name='chain' value='INPUT'>INPUT</button>";	
			echo "<button name='chain' value='OUTPUT'>OUTPUT</button>";
			echo "<button name='chain' value='FORWARD'>FORWARD</button>";	
			echo "<button name='chain' value='ALL'>ALL</button></div>";
		echo "</form>";
				
		if($chain=="INPUT"){
			afficheTab($Tin,$chain);
		}

		else if($chain=="OUTPUT"){ 
                        afficheTab($Tout,$chain);
                }
			
		else if($chain=="FORWARD"){ 
                        afficheTab($Tfor,$chain);
                }

		else if($chain=="ALL"){
			afficheTab($Tin,$chain);
			afficheTab($Tout,$chain);
			afficheTab($Tfor,$chain);
		}
		function afficheTab($T,$chain){
		
		echo "<h3>$T[0]</h3>";		
		if($chain!="ALL" && isset($chain)){
			echo "<form action='./add.php' method='get'>";	
			echo "<button name='chain' value='$chain'>ADD RULES</button>";	
			echo "</form>";

			echo "<form action='./default.php' method='get'>";  
			echo "<select name='policy'>";
			echo "<optgroup label='Default target'>";
			echo "<option value='ACCEPT'>ACCEPT</option>";
			echo "<option value='DROP'>DROP</option>";
			echo "</optgroup>";
			echo "</select>";
			echo "<button name='chain' value='$chain'>valider</button>";	
            echo "</form>";
		}
		echo "<table>";
	                for($i=1;$i<count($T);$i++){
								
				sscanf($T[$i],"%s %s %s %s %s %s %[^\n]",$numero,$target,$prot,$opt,$source,$destination,$details);
				if($i==1){$details="details";}				
				echo "<tr>";
				echo "<td>$numero</td>";
				if($_POST['modify']+1==$i && $i!=1 && $chain!='ALL'){
					
					echo "<form action='./modify.php' method='POST'>";
					echo "<input type='text' style='display:none' name='chain' value=$chain>";
					echo "<td><select name='target'>".
					      "<option value='DROP'>DROP</option>".
				     	      "<option value='ACCEPT'>ACCEPT</option>".		     	
				     	      "<option value='REJECT'>REJECT</option>".		     
					      "</select></td>";
					
					echo "<td><select name='prot'>".
                                               "<option value='udp'>udp</option>".
                                               "<option value='tcp'>tcp</option>".         
                                               "<option value='icmp'>icmp</option>".      
                                               "<option value='all'>all</option>".      
					       "</select></td>";
														
					echo "<td>$opt</td>";

					echo "<td><input type='text' name='source'></td>";		
					echo "<td><input type='text' name='destination'></td>";
					echo "<td>$details</td>";

					echo "<td><button name='numero' value=$numero>valider les modifications</button></td>";
					echo "</form>";	
				}
				
				else{
                                        echo "<td>$target</td>";
                                        echo "<td>$prot</td>";
                                        echo "<td>$opt</td>";
                                        echo "<td>$source</td>";
                                        echo "<td>$destination</td>";   
					echo "<td>$details</td>";
                                        
                                        if($i!=1 && $chain!="ALL" && isset($chain)){
                                                                     
                                                echo "<td><form action='./remove.php' method='post'>".
                                                        "<input name='chain' style='display:none' value='$chain'>".
                                                        "<button name='remove' value=\"$numero\">remove</button>".
                                                        "</form></td>";

                                                echo "<td><form action='./list.php' method='post'>".
                                                        "<input name='chain' style='display:none' value=$chain>".
                                                        "<button name='modify' value=$numero>modify</button>".
                                                        "</form></td>";
                                        }

				}
				
				echo "</tr>";
			}
                echo "</table>";
			echo "<center>";
		}

		?>
	</body>		

</html>
