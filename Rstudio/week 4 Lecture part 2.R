#Practice Questions:
  
  #I. Write a program to create a data frame from given vectors.
  # 1. Assign slno in vector with 1 to 5
  slno=c(1:5)
  # 2. Assign gender in vector with 'M' and 'F'
  gender=c('m','m','f','m','f')
  # 3. Assign name in vector with characters
  name=c("tom","jack","rika","brock","putri")
  # 4. Assign account no according to your choice
  acc_no=c(1:5)
  # 5. Assign amount with random numbers within 1000 and 5000 using runif command(2 decimal point only)
  amount=runif(5,1000,5000)
  amount=round(amount,digit=2)
  # 5. Assign 'bank_record' in data frame with no, name, gender, amount
  bank_record=data.frame(acc_no,name,gender,amount)
  # 6. Rename the coloumn names appropriate for the data.
  colnames(bank_record)=c("acc_no","acc_name","acc_gender","acc_amount")
  bank_record
  #II. Extract specific column "name" and "account no" from the data frame.
  bank_record[,1:2]
#III.Extract the first two rows from the given data frame.
  bank_record[1:2,]
#IV. Add a new column called "Nominee"
  bank_record=cbind(bank_record,Nominee=c(1,2,3,4,5))
#V. Create one csv file with 5 rows of data and merge these data with 'bank_record' data frame.
  csv_data=read.csv('C:\\Users\\kelvin\\Downloads\\1.csv',header=TRUE)
  csv_data
  bank_record=rbind(bank_record,csv_data)
#VI. Rename the name of the rows into "I", "II", "III", "IV", "V"....(Clue:rownames())
  rownames(bank_record)=c('I','II','III','IV','V','VI','VII','VIII','IX','X')
  bank_record
#VI. Delete column "nominee" from the given data frame.
  bank_record['Nominee']=NULL
  bank_record
  