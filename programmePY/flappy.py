
import random
import py5

score=0
x=500 
y=300
rectx=[770,1000,1230,1460,1690]
taille=[random.randint(100,300),random.randint(100,300),random.randint(100,300),random.randint(100,300),random.randint(100,300)]
img = 0
tuyau1= 0
tuyau = 0
background = 0

def setup():
	
	global img,tuyau,tuyau1,background,x,y
	py5.size(x*2,y*2)
	img=py5.load_image("flappy.png")
	tuyau=py5.load_image("tuyau.jpeg")
	tuyau1=py5.load_image("tuyau_inv.jpeg")
	background=py5.load_image("foret.jpg")
	
def key_pressed():
	global x,y
	
	if py5.key== ' ':
		y=y-50
		
def draw():
	
	global x,y,rectx,taille,img,tuyau,tuyau1,background,score
		
	py5.image(background,0,0,1000,600)
	
	py5.fill(10,255,0)
	py5.image(img,x,y,80,50)

	y+=10
		
	for i in range(5):
				
		py5.fill(255,0,0)
		py5.image(tuyau1,rectx[i],0,80,taille[i])
	
		py5.fill(255,0,0)
		py5.image(tuyau,rectx[i],taille[i]+200,80,400-taille[i])
		rectx[i]-=10
	      		
		if(rectx[i]<=-80):
			rectx[i]=rectx[i-1]+230
			taille[i]=random.randint(100,300)
		
		
		if  (y>=550) or (x>=rectx[i]-60 and x<=rectx[i]+60) and (y<=taille[i]+5 or y>=taille[i]+160 and y<=600):
			
			py5.fill(255,0,0)
			py5.text_size(100)
			py5.text("GAME OVER",300,300)
			py5.no_loop()	      	
		
		elif rectx[i]==x-90:
			score+=1
	
	py5.fill(0,0,0)
	py5.text_size(50)
	py5.text("score:",50,100)
	py5.text(score,200,100)
	
	if y<0:
		y=0
    
	elif y>550:
		y=550	
    
py5.run_sketch()		

