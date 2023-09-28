#include <iostream>

const int MAX_STUDENTS = 3;
const int MAX_LESSONS = 3;

struct Student;
struct Lesson;

struct Lesson {
    int lessonID;
    const char* lessonTitle;
    Student* enrolledStudents[MAX_STUDENTS];
    int studentCount;

    Lesson(int id, const char* title) : lessonID(id), lessonTitle(title), studentCount(0) {}

    void addStudent(Student* student) {
        if (studentCount < MAX_STUDENTS) {
            enrolledStudents[studentCount++] = student;
        }
    }
};

struct Student {
    int studentID;
    const char* studentName;
    Lesson* attendedLessons[MAX_LESSONS];
    int lessonCount;

    Student(int id, const char* name) : studentID(id), studentName(name), lessonCount(0) {}

    void enrollInLesson(Lesson* lesson) {
        if (lessonCount < MAX_LESSONS) {
            attendedLessons[lessonCount++] = lesson;
        }
    }
};

int main() {
    Lesson courseCatalog[MAX_LESSONS] = {
        {1, "Math"},
        {2, "Physics"},
        {3, "History"}
    };

    Student classRoster[MAX_STUDENTS] = {
        {101, "Ivanov"},
        {102, "Petrov"},
        {103, "Sidorov"}
    };

    classRoster[0].enrollInLesson(&courseCatalog[0]);
    classRoster[1].enrollInLesson(&courseCatalog[1]);
    classRoster[2].enrollInLesson(&courseCatalog[2]);
    classRoster[1].enrollInLesson(&courseCatalog[0]);
    courseCatalog[0].addStudent(&classRoster[0]);
    courseCatalog[1].addStudent(&classRoster[1]);
    courseCatalog[2].addStudent(&classRoster[2]);
    courseCatalog[0].addStudent(&classRoster[1]);

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        std::cout << "Student " << classRoster[i].studentName << " attends:" << std::endl;
        for (int j = 0; j < classRoster[i].lessonCount; ++j) {
            std::cout << classRoster[i].attendedLessons[j]->lessonTitle << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
