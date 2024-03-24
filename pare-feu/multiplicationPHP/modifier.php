<?php
	$numeroL=$_GET["line"];
	$del=$_GET["del"];
	if(!isset($del)){$del=1;}	
		
	echo $del;
		
	$x=$_GET["x"];
        $y=$_GET["y"];
        $rep=$x*$y;
		
	$fichier=fopen("table.txt","r");
	$fichier1=fopen("table1.txt","w+");
		
	$i=1;
	while(!feof($fichier)){
		$line=fgets($fichier);
		if($i!=$numeroL){
			fwrite($fichier1,$line);
		}
		else{
			if($del)fwrite($fichier1,$x.",".$y.",".$rep."\n");
		}
		
		$i++;
	}
	fclose($fichier1);
	fclose($fichier);
	
	$fichier2=fopen("table1.txt","r");
	$fichier3=fopen("table.txt","w+");

	while(!feof($fichier2)){
		$line=fgets($fichier2);
		fwrite($fichier3,$line);
	}
	
	fclose($fichier2);
	fclose($fichier3);
	
	header("Location: ./tabMulti.php?modif=0");	
	exit;
?>
