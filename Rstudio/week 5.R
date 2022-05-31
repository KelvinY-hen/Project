#Practice Questions

# - Assign x with a random integer within range 0 to 10000
x= sample(0:10000,1)
x
# - Write a program to check if x greater or equal to 1000, assign first digit of x to y,
# else, check if x greater or equal to 100, assign first digit of y,
# else, check if x greater, first digit of y,
# else, assign one to y
# Print the first digit using paste/print/message function paste(y)
if (x>=1000){
  y=as.integer(x/1000)
}else if (x>=100)
{
  y=as.integer(x/100)
}else if(x>=10)
{
  y=as.integer(x/10)
}else
{
  y=1
}
paste("first digit of x is", y)
# Pass the result into switch function, then
# display the number in words.
result=switch(y,"one","two","three","four","five","six","seven","eight","nine")
result

for (i in 1:30)
{
  print(i)
}

i
while(i>=0)
{
  print(i)
  i=i-1
}

i=1
repeat
{
  print(i)
  i=i+1
  if(i>30)
  {
  break
  }
}

#print squares of the numbers
for (i in 1:20)
{
  print(i*i)
}

i=1
while(i<=20)
{
  print(i*i)
  i=i+1
}

i=1
repeat
{
  print(i*i)
  i=i+1
  if(i>20)
  {
    break
  }
}

score=scan(file="C:\\Users\\kelvin\\Downloads\\1.txt")
score
for(i in score)
{
  num=i/2
  print (num)
}

for(i in score)
{
  num=i*2
  message(num,rep("$",num))
}
