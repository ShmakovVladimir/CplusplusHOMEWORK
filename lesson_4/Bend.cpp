#include <iostream>
#include <vector>
#include <string>

struct Lesson;
struct Student;
struct Student
{
    Student()
    {
        this->name = "None";
        this->course = 0;
    }
    Student(std::string name,unsigned int course): name {name},course {course}
    {

    }
    void addLesson(Lesson* lessonToAdd);
    std::string name;
    unsigned int course;
    std::vector<Lesson*> lessons;
};

struct Lesson
{
    Lesson()
    {
        this->lessonName = "None";
        this->placeName = "None";
        this->teacherName = "None";
    }
    Lesson(std::string lessonName,std::string teacherName,std::string placeName): lessonName {lessonName},teacherName {teacherName},placeName {placeName}
    {

    }
    void addStudent(Student* studentToAdd)
    {
        this->students.push_back(studentToAdd);
    }
    void printInfo() const;
    std::string lessonName;
    std::string teacherName;
    std::string placeName;
    std::vector<Student*> students;
};
void Student::addLesson(Lesson* lessonToAdd)
{
    this->lessons.push_back(lessonToAdd);
    lessonToAdd->addStudent(this);
}
void Lesson::printInfo() const{
    std::cout<<std::endl<<"Lesson: "<<this->lessonName<<" Teacher: "<<this->teacherName<<" Place: "<<this->placeName;
    std::cout<<std::endl<<"List of students on this lesson:";
    for(int i = 0;i<this->students.size();i++)
    {
        std::cout<<std::endl<<"student "<<i+1<<" : "<<students[i]->name;
    }
}

int main()
{
    std::vector<Student*> b04_105_students;
    std::vector<Lesson*> lessons;
    lessons.push_back(new Lesson("differential equation","Umnov E.A.","411 gk"));
    b04_105_students.push_back(new Student("Saltykova DiU",2));
    b04_105_students.push_back(new Student("Sifat M.D.",2));
    b04_105_students.push_back(new Student("Dolya Artemiy",2));
    b04_105_students.push_back(new Student("Shmakov V",2));
    for(int i = 0;i<b04_105_students.size();i++)
    {
        b04_105_students[i]->addLesson(lessons[0]);
    }
    lessons[0]->printInfo();
    for(int i = 0;i<b04_105_students.size();i++)
    {
        delete b04_105_students[i];
    }
    for(int i = 0;i<lessons.size();i++)
    {
        delete lessons[i];
    }
    return 0;
}