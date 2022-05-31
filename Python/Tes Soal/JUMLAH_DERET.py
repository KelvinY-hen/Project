
i=int(input("Masukkan angka: "))
mid= (i+1)/2
mid= int(mid)
counter=0
counterchecker=0
for a in range (0,i+1):
    if a<=mid:
        for b in range (i,0,-1):
            if counter*2!=counterchecker:
                counterchecker+=1
                print (" ",end="")
                continue
            else:
                print ("*", end="")
    counter+=1
    counterchecker=0
    print ("\n")
    if a>mid:
        print (counter)
        counter-=1
        for b in range (mid,i+1,+1):
            if counter*2!=counterchecker:
                counterchecker+=1
                print (" ",end="")
                continue
            else:
                print ("*", end="")