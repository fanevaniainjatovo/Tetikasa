
let cond=true;

function affiche(id,idDiv,type){
	
	let op=(id=="prot")?true:false;
	let a=document.querySelector('#'+id);
	let div=document.querySelector('#'+idDiv);

		let input=document.createElement("input");   	
		let input1=document.createElement("input");	
		let input2=document.createElement("input");
		
		let label=document.createElement("label");      
                let label1=document.createElement("label");     
                let label2=document.createElement("label");

		input.setAttribute("id","child"+id);
		input1.setAttribute("id","child"+id+'1');					
		input2.setAttribute("id","child"+id+'2');				
		
		label.innerHTML="tcp:";	
		label1.innerHTML="udp:";	
		label2.innerHTML="icmp:";
		
		label.setAttribute("id","label"+id);
                label1.setAttribute("id","label"+id+'1');                                       
                label2.setAttribute("id","label"+id+'2');
		
		if(op){
			input.value="tcp";
			input1.value="udp";
			input2.value="icmp";
		}

/*		input.name="name";
                input1.name="name";                                       
                input2.name="name";                               
*/		
		let en=document.querySelector('#'+"child"+id);		
		let en1=document.querySelector('#'+"child"+id+'1');	
		let en2=document.querySelector('#'+"child"+id+'2');	
		
		let lab=document.querySelector('#'+"label"+id);          
                let lab1=document.querySelector('#'+"label"+id+'1');     
                let lab2=document.querySelector('#'+"label"+id+'2'); 	

		input.type=type;	
		input1.type=type;
		input2.type=type;

	if(a.value=="on"){
		if(op){	
			div.appendChild(label);
		}	
		div.appendChild(input);
		if(op){
			div.appendChild(label1);
			div.appendChild(input1);
			div.appendChild(label2);
			div.appendChild(input2);
		}
		a.value="off";
	}
	
	else{	
		en.remove();	
		if(op){
			lab.remove();
			lab1.remove();
			en1.remove();
			lab2.remove();
			en2.remove();
		}
		a.value="on";
	}	
}

function advanced(){
	
	if(cond){
		
		let adv=document.querySelector("#advanced");

		creation(adv,"Mac:","mac","divMac","text");	
		creation(adv,"Port:","port","divPort","number");	
		creation(adv,"Protocole:","prot","divProt","radio");

		cond=false;
	}
}
function creation(adv,nomLabel,id,idDiv,type){
	
	let div=document.createElement("div");
        let input=document.createElement("input");
        let labelInput=document.createElement("label");
                
        	console.log(input.name);
		labelInput.innerHTML=nomLabel;
                input.type="checkbox";
        	input.setAttribute("id",id);           
                div.setAttribute("id",idDiv);     
		input.onclick=function(){affiche(id,idDiv,type);}
	
	div.appendChild(labelInput);   
        div.appendChild(input);

        adv.appendChild(div);

}

function normal(){
	
	let adv=document.querySelector("#advanced");
        adv.innerHTML="";
	cond=true;

}
