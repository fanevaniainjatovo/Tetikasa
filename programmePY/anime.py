
import py5

x=50 
velx=5
y=50 
vely=2
rayon=20
velrayon=10
r=20
ro=10

def setup():
	py5.size(480,480)
	
def mouse_pressed():
	global r,ro
	
	if r<0 or r>255:
		ro=-ro
	
	print("nandalo")
	r+=ro
				
def draw():
	
	global x,y,velx,vely,rayon,velrayon,r
	
	py5.background(r,r+10,r*2)
	py5.fill(10*r,3*r-1,r+3)
	py5.no_stroke()
	py5.ellipse(py5.mouse_x,py5.mouse_y,50,50)
	
	py5.fill(r*r,r+10,r+6*r)
	py5.stroke_weight(4)
	py5.ellipse(x,y,40,50)
	
	py5.fill(r,r,r)
	py5.no_stroke()
	py5.ellipse(240,240,rayon,rayon)
	
		
	if rayon>480 or rayon<0:
		velrayon=-velrayon
			
	 	
	if x>480 or x<0:
		velx=-velx
	
	if y>480 or y<0:
		vely=-vely
		
	x=x+velx
	y=y+vely
	rayon+=velrayon
    
	  
	
    
py5.run_sketch()		
