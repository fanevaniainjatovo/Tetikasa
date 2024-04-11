
function validatePassWord(){
	var password1=document.getElementById("p1").value;
	var password2=document.getElementById("p2").value;
	
	if(password1!=password2){
		alert("les mots de passe ne correspondent pas");
		return false;
	}
	
	else{
		return true;
	}	
}