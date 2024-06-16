async function getData(url){
    let response =  await fetch(url);
    let data = await response.json();
    return await data;
}

async function display(){
    let data = await getData("./data.json");
    let all=localStorage.getItem("all");
    if(all){
        all=JSON.parse(all);            
    }
    else{
        all=[];
    }        

    data = data.concat(all);
    let cbooks = document.getElementById("livre");
    cbooks.innerHTML="";
    data.forEach(livre => {
        let ebook = document.createElement("span");
            let img = document.createElement("img");
            img.id="image";
            img.src="img/"+livre.image;
            if(livre.image==""){img.src="img/x.svg";}

            let title = document.createElement("h3");
            title.textContent=livre.titre;
        
            let details = document.createElement("ul");
            Object.keys(livre).forEach(key => {
                let li = document.createElement("li");
                li.textContent = key +": "+livre[key]; 
                details.appendChild(li);
            });


        ebook.appendChild(img);
        ebook.appendChild(title);

        let c=0;
        ebook.addEventListener("click",()=>{
            if(c%2==0){ebook.appendChild(details);}
            else{ebook.removeChild(details);}  
            c++;
        });

        let cat = document.getElementById("cat");
        if(cat.value == "all"){
            cbooks.appendChild(ebook);
        }

        else if(cat.value == livre.genre){
            cbooks.appendChild(ebook);
        }

        else if(cat.value == "autre"){
            let opt= document.querySelectorAll("#search option");
            let cond = false;
            let i1=0;
            for(let i=0;i<opt.length;i++){
                if(opt[i].value!=livre.genre){
                    i1++;
                }

                else{
                    break;
                }
            }
            if(i1==opt.length){
                console.log(livre.genre);
                cbooks.appendChild(ebook);
            }
        }
    });
}

let cat = document.getElementById("cat");

cat.addEventListener("change",()=>{
    display();
});