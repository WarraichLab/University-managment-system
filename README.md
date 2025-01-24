# University Management System

This project is a **University Management System** built in C++ using foundational data structures like Linked Lists, Stacks, Queues, and Binary Trees. It is designed to manage students, sections, attendance, course enrollments, and prerequisites efficiently. The project runs in a terminal-based interface and does not use a GUI or database for simplicity.

---

## Features

### 1. Section and Student Management
- **Add Students**: Add students to specific sections. Automatically creates a section if it does not exist.
- **Display Students**: View students in a section, either sorted by roll number or in the order they were added.

### 2. Course Enrollment
- **Enroll Students**: Enroll students into a course queue, with a capacity limit.
- **Remove Students**: Remove the first student from the queue.
- **Display Queue**: View all students currently in the enrollment queue.

### 3. Attendance Management
- **Mark Attendance**: Record attendance interactively for students in a section.
- **View Attendance Records**: Display all attendance logs.

### 4. Course Prerequisites
- **Add Prerequisites**: Add courses to a binary tree structure.
- **View Prerequisites**: Display all courses in sorted order using in-order traversal.

---

## Data Structures Used

| **Data Structure** | **Purpose** |
|---------------------|-------------|
| Linked List         | Manage student lists dynamically in each section. |
| Queue               | Handle course enrollment efficiently in a FIFO manner. |
| Stack               | Record and manage attendance logs. |
| Binary Tree         | Organize course prerequisites in sorted order. |

---

## How to Install or Setup

1. **Prerequisites**:
   - A C++ compiler (e.g., GCC, Clang).
   - A text editor or IDE (e.g., Visual Studio Code, Code::Blocks).

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/university-management-system.git
   cd university-management-system
   ```

3. **Compile the Code**:
   ```bash
   g++ university_management_system.cpp -o ums
   ```

4. **Run the Program**:
   ```bash
   ./ums
   ```

---

## Functions

### 1. `addStudentToSection`
- **Purpose**: Add a student to a section.
- **Input**: Section name, roll number, student name.
- **Output**: Student added message or section created message.

### 2. `displayStudentsInSection`
- **Purpose**: Display all students in a section.
- **Input**: Section name, sorting preference (sorted/unsorted).
- **Output**: List of students.

### 3. `enqueue` (Queue)
- **Purpose**: Enroll a student in a course queue.
- **Input**: Roll number.
- **Output**: Enrollment confirmation or waiting list notification.

### 4. `dequeue` (Queue)
- **Purpose**: Remove the first student from the course queue.
- **Output**: Roll number of the removed student or a queue empty message.

### 5. `push` (Stack)
- **Purpose**: Record attendance for a student.
- **Input**: Roll number, presence status (1 for present, 0 for absent).
- **Output**: Attendance recorded message.

### 6. `displayAttendanceForSection`
- **Purpose**: Interactively mark attendance for a section.
- **Input**: Section name.
- **Output**: Attendance records.

### 7. `addCourse` (Binary Tree)
- **Purpose**: Add a course to the prerequisites tree.
- **Input**: Course name.
- **Output**: Course added message.

### 8. `inorderTraversal`
- **Purpose**: Display courses in sorted order.
- **Output**: Sorted list of course prerequisites.

---

## Possible Outputs

### 1. Adding a Student
```
Enter Section Name: CS101
Enter Roll Number: 101
Enter Name: John Doe
Student added to section CS101.
```

### 2. Displaying Students
#### Unsorted:
```
Students in Section CS101:
John Doe (Roll: 101)
Jane Smith (Roll: 102)
```
#### Sorted:
```
Students in Section CS101:
Jane Smith (Roll: 102)
John Doe (Roll: 101)
```

### 3. Course Enrollment
```
Enter Roll Number to Enroll: 101
Student with Roll 101 added to the course.
```

### 4. Attendance Recording
```
Mark attendance for section: CS101
Roll 101 - John Doe (1 for Present, 0 for Absent): 1
Roll 102 - Jane Smith (1 for Present, 0 for Absent): 0
Attendance recorded for Roll 101: Present
Attendance recorded for Roll 102: Absent
```

### 5. Course Prerequisites
#### Adding Courses:
```
Enter Course Name: Data Structures
Course added.
Enter Course Name: Algorithms
Course added.
```
#### Viewing Courses:
```
Course Prerequisites:
Algorithms Data Structures
```

---

## Project Scope and Limitations
- **Scope**:
  - Covers core university management tasks.
  - Demonstrates effective use of DSA concepts.
- **Limitations**:
  - No GUI or database integration.
  - Limited to terminal-based interaction.

---

## License
This project is licensed under the MIT License. Feel free to use and modify it as needed.

---

Feel free to contribute to the project by submitting issues or pull requests!

