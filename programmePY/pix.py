mots ='FORGES POIGNET CLAPET COFFRET FLORES ASTRILD CREPES NOIRCIR HANSES POULAIN'
a = 0
b = len(mots)
tutu =''
for i in range(0, int(len(mots)/2)):
    if (mots[i]==' '):
        tutu = tutu + mots[abs(a-b)]
    a = a + 2
    b = b - 1
    
print(tutu)
