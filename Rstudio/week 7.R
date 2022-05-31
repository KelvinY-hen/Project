a=c(1,2,3)
names(a)=b
a
b=c("green","blue","red")
pie(a,b,radius=1,main="SAMPLE",col=c("green","blue","red"))
city_data[,2]
a=2
b=city_data[,1]
pie(a,b,0.5)

install.packages("plotrix")
library(plotrix)

pie3D(a,labels=b,explode=.5, main="CITY_DATA")

class(a)
plot(a)

plot(a,type="o")

plot(a,type="o",xlab="COUNTRY",ylab="TEMP",main="CITY")
text(a,type="o",labels=b,cex=0.5,pos=2,col="red")

lines(b,type="o",xlab="COUNTRY",ylab="TEMP",main="CITY")
colnames(c)=c("a","b","c","d","e")
sample_data$
iv=nrow(sample_data[sample_data$SPECIES=="Iris-versicolor",])
iv
ise=iv=nrow(sample_data[sample_data$SPECIES=="Iris-setosa",])
ivir=iv=nrow(sample_data[sample_data$SPECIES=="Iris-virginica",])
a=c(iv,ise,ivir)
l=c("Iris_versicolor","Iris_setosa","Iris-virgnica")
pie(a,l,radius=1,main="IRIS_FLOWER",col=c("green","blue","red"))
class(sample_data)
plot(x=sample_data$LEN_PETAL,type = "o")
plot(x=sample_data$LEN_PETAL,y=sample_data$WID_PETAL , type = "p")

sample_data$WID_PETAL
  
ggplot(sample_data, aes(x=LEN_PETAL, y=WID_PETAL)) +
  geom_point(aes(shape =factor(SPECIES), colour =(SPECIES)))+
  ggtitle("PETAL_LENGTH vs PETAL_WIDTH based on Species")+
  stat_smooth(method=lm)

ggplot(city_data, aes(x=City, y=Workers))+ geom_bar()
  geom_p
ggplot(a)
