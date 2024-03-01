import java.util.*;
public class Calculatrice{

	public int countPar(String a){
		int par=0;
		for(int i=0;i<a.length();i++){
			if(a.charAt(i)=='('){par++;}
		}
	
	return par;
	}

	public int count(String a){
		int op=0;
		boolean x=true;
		for(int i=0;i<a.length();i++){
			if(a.charAt(i)=='*' || a.charAt(i)=='/' || a.charAt(i)=='-' || a.charAt(i)=='+'){
				if(x){	op++;	}
				x = false;
			}
			else{x = true;}
		}
	
	return op;
	}

	public void del(String a[],int inDel,int taille){

		for(int i=inDel;i<taille-1;i++){
			a[i]=a[i+1];
		}

	}
	
	public String calcul(String a){

		a=(a.charAt(0)=='-' || a.charAt(0)=='+')?"0"+a:"0+"+a;

		int taille=count(a)+1;
		int tailleOp=count(a);
		
	//	ArrayList<String> nbr = new ArrayList<>();
	//	ArrayList<String> opr = new ArrayList<>();
		String []nbr=new String[taille];
		String []opr=new String[taille];
	
		String s="";
		int x=0;

		double result=0;
		
		//split
	
		for(int i=0;i<a.length();i++){
		
			if(a.charAt(i)=='*' || a.charAt(i)=='/'){
				opr[x]=a.charAt(i)+"";
				nbr[x]=s;
				s="";
				x++;
			}
		
			else if(a.charAt(i)=='-' || a.charAt(i)=='+'){
				opr[x]="$";
				if(a.charAt(i-1)<='9' && a.charAt(i-1)>='0'){nbr[x]=s;x++;}	
			
				if(a.charAt(i-1)=='-' && a.charAt(i)=='+' || a.charAt(i)=='-' && a.charAt(i-1)=='+'){
					String bf=a.substring(0,i);
					String nouv="-";
					String af=a.substring(i+1);
					a=bf+nouv+af;
				}
				
				else if(a.charAt(i-1)=='-' && a.charAt(i)=='-' || a.charAt(i-1)=='+' && a.charAt(i)=='+'){
					String bf=a.substring(0,i);
                                        String nouv="+";
                                        String af=a.substring(i+1);
					a=bf+nouv+af;
				}
			
				s=a.charAt(i)+"";
			}

			else if(a.charAt(i)<='9' && a.charAt(i)>='0' || a.charAt(i)=='.'){
				s+=a.charAt(i);
			}
		}
	
		nbr[taille-1]=s;
//		nbr.set(0,"0");
	
		//calcul
	
		for(int i=1;i<tailleOp;i++){
		
			if(opr[i].equals("*")==true){
				nbr[i]=Double.toString(Double.valueOf(nbr[i])*Double.valueOf(nbr[i+1]));		
				del(nbr,i+1,taille--);
				del(opr,i,tailleOp--);
			//	nbr.remove(i+1);
			//	opr.remove(i);
				i--;
			}

			else if(opr[i].equals("/")==true){		
				nbr[i]=Double.toString(Double.valueOf(nbr[i])/Double.valueOf(nbr[i+1])); 
				del(nbr,i+1,taille--);    
				del(opr,i,tailleOp--);
			//	nbr.remove(i+1);
			//	opr.remove(i);
				i--;
			}

		}
	
		for(int i=1;i<tailleOp;i++){
                
                        nbr[i]=Double.toString(Double.valueOf(nbr[i])+Double.valueOf(nbr[i+1]));          
                        del(nbr,i+1,taille--);
                        del(opr,i,tailleOp--);
                        //nbr.remove(i+1);
			//opr.remove(i);
			i--;

		}
		
		return Double.toString(Double.valueOf(nbr[0])+Double.valueOf(nbr[1]));	
	}

	
String includeToA(String a,String nbr,int y,int z){
	
	String b="";
	a+="$";
	for(int i=0;i<a.length();i++){

		if(i==y-1){
			if(a.charAt(i-1)<='9' && a.charAt(i-1)>='0'){b+="*";}
			b+=nbr;
			i=z+1;
			if(a.charAt(i)<='9' && a.charAt(i)>='0'){b+="*";}
		}
		if(i<a.length()){
			b+=a.charAt(i);
		}	
	}

	return b;

} 

String eval(String a){
	
	String []b=new String[countPar(a)];
	int taille=a.length();
	boolean par=false;
	int z=0;
	int j=0;
	int y=0;

	for(int i=taille-1;i>=0;i--){
		
		if(a.charAt(i)=='('){par=true;y=z=i+1;}
		
		while(par){
			b[j]+=a.charAt(z);
			z++;
			if(a.charAt(z)==')'){
				b[j]=calcul(b[j]);
				a=includeToA(a,b[j],y,z);
				//System.out.println(a);
				j++;
				par=false;
			}
		}
	}
	
	return a;	
}
}
