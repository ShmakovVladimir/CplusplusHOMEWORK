#include <iostream>
#include <vector>
#include <string>

struct Lesson;
struct Student;
struct Student
{
    Student(): name {"None"},course {0}
    {
        
    }
    Student(const std::string& studentName,unsigned int course): name {studentName},course {course}
    {

    }
    void addLesson(Lesson* lessonToAdd)
    {
        lessons.push_back(lessonToAdd);
    }
    void printInfo() const;
    std::string name;
    unsigned int course;
    std::vector<Lesson*> lessons;
};

struct Lesson
{
    Lesson(): lessonName {"None"}, placeName {"None"}, teacherName {"None"}
    {

    }
    Lesson(const std::string& lesson,const std::string& teacher,const std::string& place): lessonName {lesson},teacherName {teacher},placeName {place}
    {

    }
    void addStudent(Student* studentToAdd)
    {
        students.push_back(studentToAdd);
    }
    void printInfo() const;
    std::string lessonName;
    std::string teacherName;
    std::string placeName;
    std::vector<Student*> students;
};

void Lesson::printInfo() const
{
    std::cout<<std::endl<<"Lesson: "<<this->lessonName<<" Teacher: "<<this->teacherName<<" Place: "<<this->placeName;
    std::cout<<std::endl<<"List of students on this lesson:";
    for(int i = 0;i<this->students.size();i++)
    {
        std::cout<<std::endl<<"student "<<i+1<<" : "<<students[i]->name;
    }
}

void Student::printInfo() const
{
    std::cout<<std::endl<<"Student: "<<name<<" course: "<<course;
    std::cout<<std::endl<<"List of lessons for this student: ";
    for(int i = 0; i< lessons.size();i++)
    {
        std::cout<<std::endl<<"lesson "<<i+1<<" : "<<lessons[i]->lessonName;
    }
}


void addLessonForStudent(Student* studentForALesson,Lesson* lessonForAStudent)
{
    studentForALesson->addLesson(lessonForAStudent);
    lessonForAStudent->addStudent(studentForALesson);
}

int main()
{
    std::vector<Student> b04_105_students;
    std::vector<Lesson> lessons;
    lessons.push_back(Lesson("differential equation","Umnov E.A.","411 gk"));
    b04_105_students.push_back(Student("Saltykova DiU",2));
    b04_105_students.push_back(Student("Sifat M.D.",2));
    b04_105_students.push_back(Student("Dolya Artemiy",2));
    b04_105_students.push_back(Student("Shmakov V",2));
    for(int i = 0;i<b04_105_students.size();i++)
    {
        addLessonForStudent(&b04_105_students[i],&lessons[0]);
    }
    lessons[0].printInfo();
    std::cout<<"\n \n";
    b04_105_students[0].printInfo();
    return 0;
}