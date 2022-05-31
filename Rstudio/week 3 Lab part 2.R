#Practical Question:

library(crayon)

# Create 5 students Progress Report with title "PFDA LAB Progress Report UC2F/APU2F2109"
# ***************************************
# PFDA LAB(Green colour)
  message(green("PFDA LAB"))
# Progress Report(magenta colour,italics,underline)
  message(magenta$italic$underline("Progress Report"))
# UC2F/APU2F2109(yellow background,bold,red colour)
  message(bgYellow$bold$red("UC2F/APU2F2109"))
# print * using repeat command
  rep("*",15)



# -1. Test-I marks have to generate using runif command(25)
  Test_1=runif(5,1,25)
  Test_1
# -2. Test-II marks have to generate using runif command(25)
  Test_2=runif(5,1,25)
  Test_2
# -3. Final Exam marks have to generate using sample command(50)
  Test_Final=sample(0:50,5,TRUE)
  Test_Final
# -4. Round off both the test marks
  round(Test_1,digit=0)
  round(Test_2,digit=0)
# -5. Generate Total Marks
  Total_Marks=Test_1+Test_2+Test_Final
  Total_Marks
# -6. Give names to each Total_Marks to represent students
  names(Total_Marks)=c("Ken","Jack","Jes","Rika","Tom")
  Total_Marks
# -7. Find out the total number of students we have in the report
  length(Total_Marks)
# -8. Find out who received the highest score 48 -> Tan (which.max(Totalmarks))
  names(Total_Marks)[which.max(Total_Marks)]
# -9. Find out who recieved the least mark 26
  names(Total_Marks)[which.min(Total_Marks)]
# -10. Find out the average of this class
  sum(Total_Marks)/length(Total_Marks)
#