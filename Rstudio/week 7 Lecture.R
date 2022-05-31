data=data.frame(name=c("a","b","c","d","e"),value=c(3,12,5,18,45))
data

ggplot(termresign_agedata,aes(x=Age,y=Resignation, fill=Resignation))+geom_bar(stat="identity",width=0.5)+
  geom_text(aes(label=Resignation), vjust=-1, size=5)+
    scale_fill_gradient(low="green", high="red", space='Lab')

ggplot(sample_data, aes(x=LEN_PETAL, y=WID_PETAL)) + 
  geom_bar(stat="identity",color="blue",fill="white")+
  geom_text(aes(label=WID_PETAL))

ggplot(termresign_agedata, aes(x=Resignation))+
  geom_histogram(colour="cyan",aes(fill=..count..))+
  scale_fill_gradient("Count",low="green",high="red")

ggplot(sample_data, aes(x=LEN_PETAL, y=WID_PETAL)) +
  geom_point(aes(color=WID_PETAL))+
  facet_wrap(~WID_PETAL)

ggplot(termresign_agedata, aes(x=Age,y=Resignation))+geom_point(aes(Age))+facet_wrap(~Age)

ggplot(sample_data,aes(y=WID_PETAL,x=SPECIES, color=SPECIES)) + geom_boxplot()
    
    