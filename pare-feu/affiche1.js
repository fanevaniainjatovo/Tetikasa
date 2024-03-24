condIP=true;
condIface=true;
condProt=true;
condPort=true;
function testCheck(id){
	
	let check=document.querySelector('#'+id);

	if(check.value=='true'){check.value='false';}
	else{check.value='true';}

	return 	check.value;
}

function addMac(id){
	if(testCheck(id)=='true'){
		$('#divMAC').append("<input pattern='([a-fA-F0-9]{2}(:|-)){5}[a-fA-F0-9]{2}' type='text' name='mac'>");
	}
	else{
		$('#divMAC').children().remove();
	}
}

function addIP(){  
        if(condIP){
                $('#divIP').append("<input pattern='((25[0-5]{1})|(2[0-4]{1}[0-9]{1})|([01]?[0-9]?[0-9])){3}' type='text' name='ip'>");
                condIP=false;
        }
}

function addIfaceIn(){
	if(testCheck('ifaceIn')=='true'){
		$(document).ready(function(){
			$.ajax({
				url: "iface.php",
				success: function(resultat){
						$("#divIfaceIn").append(resultat);
					}
			});
		});		
	}
	else{
		$('#divIfaceIn').children().remove();
	}
}

function addIfaceOut(){
	if(testCheck('ifaceOut')=='true'){
                $('#divIfaceOut').append("<input type='text' name='ifaceOut'>");
        }
        else{
                $('#divIfaceOut').children().remove();
        }

}

function addProt(id){
	condPort=true;
	if(testCheck(id)=='true'){
                 $('#divProt').append("<select name='prot' onclick='checkPort()'>"+
                                        "<optgroup label='Protocole'>"+
                                           "<option value='udp'>udp</option>"+
                                           "<option value='tcp'>tcp</option>"+
                                           "<option value='icmp'>icmp</option>"+
                                        "</optgroup>"+
                                   "</select>");
        }
	else{
		$('#divProt').children().remove();
	}
}

function checkPort(){
    if(condPort){
	$('#divProt').append("<label>Port:</label><input type='checkbox' id='port' onclick=\"addPort('port')\"><div id='divPort'></div>");
	condPort=false;
    }
}

function addPort(id){
	if(testCheck(id)=='true'){
		$('#divPort').append("<label>Nombre de port(s)</label><input type='text' pattern='[1-9][0-9]*' title='Entrez un nombre strictement positif' name='nport' id='nport' onfocus='removeInputPort()'>"+
			"<button type='button' onclick='addInputPort()'>valider</button>");
		
		$('#divPort').append("<select name='optPort'>"+
                                        "<optgroup label='source/destination'>"+
                                           "<option value='destination'>destination</option>"+
                                           "<option value='source'>source</option>"+
                                        "</optgroup>"+
                                   "</select>");

	}
	
	else{
		$('#divPort').children().remove();
	}

}

function addInputPort(){
	if(condPort){
		console.log(condPort);	
		let port=document.querySelector('#nport');
		$('#divPort').append("<div id='divNport'></div>");
	
		for(let i=1;i<=port.value;i++){
			$('#divNport').append("<label>Port"+i+":</label><input type='text' pattern='[1-9][0-9]*' name='port"+i+"'></br>");		
		}
		condPort=false;
	}
}

function removeInputPort(){
	condPort=true;
	$('#divNport').remove();
}

function destination(id,name,func,div){
  	condIP=true;
	condIface=true;
	if(testCheck(id)=='true'){
                $('#'+div).append("<select name="+name+" onclick='"+func+"()'>"+
					"<optgroup label='source/destination'>"+
					   "<option value='destination'>destination</option>"+
					   "<option value='source'>source</option>"+
					"</optgroup>"+
				   "</select>");
				
        }
        else{
                $('#'+div).children().remove();
	}

}

