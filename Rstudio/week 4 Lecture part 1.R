df=data.frame()

n=c(2,3,5)
s=c("aa","bb","cc")
b=c(TRUE, FALSE, TRUE)
df=data.frame(n,s,b)
df

data.frame(df$s)

df[,1]

df=cbind(df,new=c("red","blue","yellow"))

df['"blue"']=NULL

mtcars

nrow(mtcars)

ncol(mtcars)

names(mtcars)

head(mtcars,2)
tail(mtcars)

x=list(n,s,b,3)
x
x[1]
y=list(x,1:5)
y
y[1]
