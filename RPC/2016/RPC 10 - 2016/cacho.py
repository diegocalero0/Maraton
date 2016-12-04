casos = int(raw_input())

while(casos>0):
	seq = raw_input()
	dif = 0
	i=0
	while i < len(seq):
		if (i+2)<=len(seq)-1:
			dif = int(seq[i+2]) - int(seq[i])
			if dif==1:
				bandera = True
			else:
				bandera = False
				break

		i+=2
	casos-=1
	if bandera:
		print 'Y'
	else:
		print 'N'