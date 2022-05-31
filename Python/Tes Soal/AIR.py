air= int(input("Input Temperatur Air: "))
if (air < 0):
    print ("\n\tAir dalam kondisi PADAT\n")
elif (air == 0):
    print ("\n\tAir dalam kondisi PADAT-CAIR\n")
elif (100> air > 0):
    print ("\n\tAir dalam kondisi CAIR\n")
elif (air == 100):
    print ("\n\tAir dalam kondisi CAIR-GAS\n")
elif (air > 100):
    print ("\n\tAir dalam kondisi GAS\n")