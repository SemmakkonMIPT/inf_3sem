/*
Реализуйте множественную двустороннюю связь, используя структуры и указатели. Для этого создайте два
массива, в которых будут храниться экземпляры некоторых структур. Например, пусть в первом массиве хранятся экземпляры структуры Student, а во втором массиве экземпляры структуры Lesson, при этом в каждом
экземпляре структуры Student должен существовать массив указателей на экземпляры структуры Lesson и
наоборот, то есть каждый студент связан с несколькими занятиями и каждое занятие связано с несколькими
студентами. Продемонстрируйте в main варианты использования реализованного Вами отображения.
*/

#include <iostream>

const auto MAX_STUDENTS = 3;
const auto MAX_LESSONS = 3;

struct Student;

struct Lesson {
    int lessonID;
    const char* lessonName;
    Student* students[MAX_STUDENTS];
    int studentCount;

    Lesson(int id, const char* name) : lessonID(id), lessonName(name), studentCount(0) {}

    void addStudent(Student* student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        }
    }
};

struct Student {
    int studentID;
    const char* studentName;
    Lesson* lessons[MAX_LESSONS]; // Массив указателей на уроки, на которые записан студент
    int lessonCount;

    Student(int id, const char* name) : studentID(id), studentName(name), lessonCount(0) {}

    void enrollInLesson(Lesson* lesson) {
        if (lessonCount < MAX_LESSONS) {
            lessons[lessonCount++] = lesson;
        }
    }
};

int main() {

    Lesson lessons[MAX_LESSONS] = {
        {1, "Math"},
        {2, "Physics"},
        {3, "History"}
    };

    Student students[MAX_STUDENTS] = {
        {101, "Ivanov"},
        {102, "Petrov"},
        {103, "Sidorov"}
    };

    students[0].enrollInLesson(&lessons[0]); 
    students[1].enrollInLesson(&lessons[1]); 
    students[2].enrollInLesson(&lessons[2]); 
    students[1].enrollInLesson(&lessons[0]); 
    lessons[0].addStudent(&students[0]);     
    lessons[1].addStudent(&students[1]);    
    lessons[2].addStudent(&students[2]);
    lessons[0].addStudent(&students[1]);    

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        std::cout << "Student " << students[i].studentName << " goes on:" << std::endl;
        for (int j = 0; j < students[i].lessonCount; ++j) {
            std::cout << students[i].lessons[j]->lessonName << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}


