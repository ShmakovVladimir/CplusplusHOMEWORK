#include <iostream>
#include <string.h>

struct Student;
struct Lesson
{
    std::string name;
    std::string teacherName;
    std::string place;
    Student** studentsOnThisLesson;
    int maxStudentQ;
    int studentPos = 0;
    Lesson(std::string name,std::string teacherName,std::string place,int maxStudentQ){
        this->name = name;
        this->place = place;
        this->maxStudentQ = maxStudentQ;
        this->teacherName = teacherName;
        this->studentsOnThisLesson = new Student*[maxStudentQ];
        for(int i = 0;i<this->maxStudentQ;i++){
            this->studentsOnThisLesson[i] = nullptr;
        }
    }
    void addStudent(Student* studentOnThisLesson){
        this->studentsOnThisLesson[studentPos] = studentOnThisLesson;
        this->studentPos++;
    }
    ~Lesson(){
        delete[] this->studentsOnThisLesson;
    }
	void printStudents();
    
};



struct Student
{
    std::string name;
    unsigned int course;
    Lesson** lessons;
    int maxLessonsQ;
    int lessonPosition = 0;
    Student(std::string name,unsigned int course,int maxLessonsQ){
        this->name = name;
        this->course = course;
        this->maxLessonsQ = maxLessonsQ;
        this->lessons = new Lesson*[maxLessonsQ];
        for(int i = 0;i<maxLessonsQ;i++){
            this->lessons[i] = nullptr;
        }

    }
    void addLesson(Lesson* lessonToAdd){
        this->lessons[lessonPosition] = lessonToAdd;
        this->lessonPosition++;
        lessonToAdd->addStudent(this);
    }
    void printLessons(){
        std::cout<<this->name<<" "<<"lectures: "<<std::endl;
        for(int i = 0;i<this->maxLessonsQ&&this->lessons[i];i++){
            std::cout<<this->lessons[i]->name<<"  "<<this->lessons[i]->teacherName<<"  "<<this->lessons[i]->place<<std::endl;
        }
    }
    ~Student(){
        delete[] lessons;
    }

};

void Lesson::printStudents(){
		std::cout<<"Lesction: "<<this->name<<"  Auditory: "<<this->place<<" Teacher: "<<this->teacherName<<std::endl;
		for(int i = 0;i<this->maxStudentQ&&this->studentsOnThisLesson[i];i++){
			std::cout<<this->studentsOnThisLesson[i]->name<<" course: "<<this->studentsOnThisLesson[i]->course<<std::endl;
		}
	}


int main(){
    Lesson** lessons = new Lesson*[3];
    Student** student = new Student*[10];
    lessons[0] = new Lesson("diff equations","Umnov Egor Sanych","411GK",15);
    lessons[1] = new Lesson("math analysis","Umnov Aleksandr Evgenievich - the best teacher of all times(this is not a joke)","paradise",15);
    lessons[2] = new Lesson("Chemistry","Gnatko Nadezhda Nikolaevna - the best women in the world(this was a joke)","hell",7);
    student[0] = new Student("Saltykova Daria",1,2000);
    student[1] = new Student("Trent Reznor(NIN)",20,1);
    student[2] = new Student("Alessandro Cortini(NIN)",2,3);
    student[3] = new Student("Atticus Ross(NIN)",5,1);
    student[4] = new Student("Really fat cat",1,400);
    student[5] = new Student("Sifat Md Abdullah",1,2000);
    student[6] = new Student("Dolya Artemyy",1,2000);
    student[7] = new Student("Shmakov Vladimir",1,2000);
    student[8] = new Student("Svirelkin Georgiy",1,2000);
    student[9] = new Student("Kent is zhata",0,1);

    student[9]->addLesson(lessons[0]);
    student[0]->addLesson(lessons[2]);
    student[5]->addLesson(lessons[2]);
    student[1]->addLesson(lessons[2]); //ох не повезло не повезло
    student[2]->addLesson(lessons[0]);
    student[7]->addLesson(lessons[2]);
	student[0]->addLesson(lessons[1]);
	student[6]->addLesson(lessons[1]);
	student[5]->addLesson(lessons[1]);
	student[8]->addLesson(lessons[1]);
	student[7]->addLesson(lessons[1]);
    for(int i =0;i<3;i++){
        lessons[i]->printStudents();
        std::cout<<std::endl;
    }
	for(int i = 0;i<10;i++){
		delete student[i];
	}
	for(int i = 0;i<3;i++){
		delete lessons[i];
	}
	delete[] student;
	delete[] lessons;

    return 0;
}
