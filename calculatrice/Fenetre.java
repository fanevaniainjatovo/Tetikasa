import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.*;

public class Fenetre extends JFrame
{
	public Fenetre(String title,int x,int y,boolean test){
		this.setTitle(title);
		this.setVisible(test);
		this.setSize(x,y);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public String affiche="";

	public void createCalculatrice(Fenetre win){
		
		ArrayList <JButton>tab=new ArrayList<>();
		JPanel pan=new JPanel(new GridLayout(2,1));
		
		JPanel pan1=new JPanel(new GridLayout(2,1));
		JPanel pan2=new JPanel(new GridLayout(5,3));

		JLabel reponse=new JLabel("<html><h1 style=\"margin-left:80px\">CALCULATRICE</h1></html>");
		JTextArea entry=new JTextArea();

		pan1.setBackground(Color.BLACK);

		pan1.add(reponse);
		pan1.add(entry);
		
		ArrayList <JButton> nb =new ArrayList<JButton>();
		for(int i=0;i<=10;i++){
			nb.add(new JButton(Integer.toString(i)));
			pan2.add(nb.get(i));
			int a=i;
                        nb.get(a).addActionListener(new ActionListener(){
                                        public void actionPerformed(ActionEvent e){
                                                String tmp=nb.get(a).getText();
                                                affiche+=tmp;
                                                entry.setText(affiche);
                                        }
                                });

		}	
		
		ArrayList <JButton>op =new ArrayList<JButton>(Arrays.asList(new JButton("+"),new JButton("-"),new JButton("*"),new JButton("/"),new JButton("("),new JButton(")")));		      for(int i=0;i<op.size();i++){
		
			pan2.add(op.get(i));	
			int a=i;	
			op.get(a).addActionListener(new ActionListener(){
                        	        public void actionPerformed(ActionEvent e){
                                	        String tmp=op.get(a).getText();
						affiche+=tmp;
						entry.setText(affiche);
                                	}
                        	});				
		}
		
		JButton clear=new JButton("AC");
		clear.addActionListener(new ActionListener(){
                                        public void actionPerformed(ActionEvent e){
						affiche="";
                                                entry.setText(affiche);
                                        }
                                });

		JButton del=new JButton("DEL");
		del.addActionListener(new ActionListener(){       
                                        public void actionPerformed(ActionEvent e){
                                                affiche=affiche.substring(0,affiche.length()-1);                
                                                entry.setText(affiche);
                                        }
                                });

		JButton egal=new JButton("=");
		egal.addActionListener(new ActionListener(){    
                                        public void actionPerformed(ActionEvent e){
                                                Calculatrice test=new Calculatrice();
						String av=test.calcul(test.eval(affiche));
						affiche=affiche+"=\n"+av;
                                                entry.setText(affiche);
						affiche=av;
                                        }
                                });

		pan2.add(clear);
		pan2.add(del);
		pan2.add(egal);

		pan.add(pan1);
		pan.add(pan2);
		
		win.add(pan);
	}
}
