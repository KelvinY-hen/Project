#1.for sequence (firstnum:lastnum)
#2.for exact values(c(1,2,.....))
#3.random values with decimal(runif(size,firstnum,lastnum))
#4.random values with integers(starnum:lastnum,size,T/F)T/F=Repitition


x=1:10
x
x=c(1,2,3,4,5)
x
z=runif(5,1,2)
z
j=sample(0:25,5,TRUE)
j

j=c(1,2,3,4,5,6,7,8,9,10)
min(j)
max(j)
sum(j)
mean(j)
median(j)
sort(j)
sort(j,decreasing=TRUE)

y=22/7
round(y,digit=2)
sqrt(25)

rep("*",10)
length(j)

x=10
y=20
z=x+y

message("Welcome to R Programmming Labs")
message("The sum value is",x+y)
print("Welcome to R programming")
message="Hello"
paste(message,"Welcome")

install.packages("crayon")
library(crayon)

message(yellow("Welcome to R Programmingng Lab"))

message(black$bgYellow("Welcome to"),blue$bold$underline(" R Programming Lab"))
