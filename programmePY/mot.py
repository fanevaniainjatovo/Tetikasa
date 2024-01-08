indice = "qvbcfawdve"
lettre = "~o_djk|_oh"
i = 0
toto = ''
while i < len(indice):
	if ord(indice[i]) < 109:
		toto=toto+chr(ord(lettre[i])+10)
    
	else:
		toto=toto+chr(ord(lettre[i])-10)
	
	i+=1
		
print(toto) 
