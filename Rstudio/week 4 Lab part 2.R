#Practice Problems
#1. Consider A=matrix(c(2,0,1,3), ncol=2) and B=matrix(c(5,2,4,-1), ncol=2).
A=matrix(c(2,0,1,3), ncol=2)
A
B=matrix(c(5,2,4,-1), ncol=2)
B
# a) Find A + B
A+B
# b) Find A - B
A-B
#2. Find the solution for aA where a=3
3*A
#3. Find the solution for Ab,where b=c(7,4).
b=c(7,4)
A*b
#4. Create three vectors v1,v2,v3 with integers and each vector has 3 elements.
# Combine the three vectors to become a 3×3 matrix( V)where each column represents
# a vector and name it. Check if V is a vector or matrix.
data1=c(1,2,3)
data2=c(4,5,6)
data3=c(7,8,9)
v1=factor(data1)
v2=factor(data2)
v3=factor(data3)
vector_matrix=matrix(c(v1,v2,v3),3,3,FALSE,list(c("1","2","3"),c("v1","v2","v3")))
vector_matrix
#5. Create a 5X2 two dimensional array with multiples of 5 values
arrayof5=array(0:19,dim=c(5,2,2))
arrayof5*5
