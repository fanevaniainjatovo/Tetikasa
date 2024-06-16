function addToJson(form){
    let formData = new FormData(form);
    let data ={};
    formData.forEach((value,key)=>{
        data[key] = value;   
    });

    const jsonString = JSON.stringify(data,null,2);
    const blob = new Blob(
                [jsonString],
                {type: 'application/json'}
                );
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'data.json';
    a.click();
    URL.revokeObjectURL(url);
    console.log('ato');
    
}

// const a = document.getElementById('ajout');
// a.addEventListener('click',()=>{
//     let form=document.getElementById("form");
//     addToJson(form);
// });


function ajout(){
    let form = document.getElementById("form");
    let formData = new FormData(form);
    let data ={};
    
    formData.forEach((value,key)=>{
        data[key] = value;
        if(key=="image"){
            data[key]= value.name;
        }
    });


    let all=localStorage.getItem("all");
        if(all){
            all=JSON.parse(all);            
        }
        else{
            all=[];
        }        
        console.log(data);
        all.push(data);
        localStorage.setItem("all",JSON.stringify(all));
}

let button = document.getElementById("ajout");
button.addEventListener("click",()=>{
    ajout();
});