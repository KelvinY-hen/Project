# func_name <- function (arguements)
# {
#   //statements
#    //return
# }

#create function called "display" and print "welcome"
display=function()
{
  print ("welcome")
}

display()

plus=function(x,y)
{
  z=x+y
  return(z)
}
tempe=plus(24,55)
tempe


input_plus=function()
{
  x=as.integer(readline(prompt="Enter the number: "))
  y=as.integer(readline(prompt="enter the number"))
  z=x+y
  return(z)
}

input_plus()

calculator=function(x,y)
{
  add=x+y
  sub=x-y
  mul=x*y
  div=x/y
  return(c(addition=add,substraction=sub,multiply=mul,division=div))
}
calculator(20,10)


calculator_2=function()
{
  x=as.integer(readline(prompt="Enter the number: "))
  y=as.integer(readline(promp="Enter the number: "))
  add=x+y
  sub=x-y
  mul=x*y
  div=x/y
  return(c(addition=add,substraction=sub,multiply=mul,division=div))
}
calculator_2()


get_details=function()
{
  name=readline(prompt="Enter your name: ")
  ID=readline(prompt="Enter ID: ")
  mark_1=as.integer(readline(prompt="Enter your 1st mark: "))
  mark_2=as.integer(readline(prompt="Enter your 2nd mark: "))
  data=data.frame(name,ID,mark_1,mark_2,total_marks=mark_1+mark_2,average=(mark_1+mark_2)/2)
  return(data)
}

get_details=function()
{
  name=readline(prompt="Enter your name: ")
  ID=readline(prompt="Enter ID: ")
  mark_1=as.integer(readline(prompt="Enter your 1st mark: "))
  mark_2=as.integer(readline(prompt="Enter your 2nd mark: "))
  data=data.frame(name,ID,mark_1,mark_2,total_marks=mark_1+mark_2,average=(mark_1+mark_2)/2)
  return(c(Name=name,ID=ID,mark_1=mark_1,mark_2=mark_2,total_marks=mark_1+mark_2,average=(mark_1+mark_2)/2))
}
get_details()

diameter=function(x)
{
  return (2*x)
}

circumfernce=function(x)
{
  return(2*3.14*x)
}

area=function(x)
{
  return(3.14*x*x)
}

rad=as.integer(readline(prompt="Enter circle radius: "))
cat("selection menu:\n\t[1]diameter\n\t[2]circumference\n\t[3]area\n")
choice=as.integer(readline(prompt="Enter choice: "))

if(choice==1)
{
 results=diameter(rad) 
}else if(choice==2)
{
 results=circumfernce(rad) 
}else if(choice==3)
{
 results=area(rad)  
} else
{
 print("invalid input") 
}

paste("Results of selected circle formula: ",results)