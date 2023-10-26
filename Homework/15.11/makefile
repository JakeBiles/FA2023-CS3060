cc = gcc

JacobBilesHW8: GraddedActivity.o Exam.o PassFailExam.o CourseGrades.o Main.o
	g++ GraddedActivity.o Exam.o PassFailExam.o CourseGrades.o Main.o -o JacobBilesHW8

GraddedActivity.o: GraddedActivity.cpp
	g++ -c GraddedActivity.cpp

Exam.o: Exam.cpp
	g++ -c Exam.cpp

PassFailExam.o: PassFailExam.cpp
	g++ -c PassFailExam.cpp

CourseGrades.o: CourseGrades.cpp
	g++ -c CourseGrades.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	del -rf *.o *.exe