# 🛫 DSU Airline Management System

## 🧾 Project Overview
The **DSU Airline Management System** is a simple console-based application written in **C** that manages passenger flight reservations.  
It allows users to **reserve seats**, **cancel bookings**, **display passenger records**, and **automatically store data in a file**.

This project was our **first programming project**, developed in **November 2022** during the **1st Semester (Programming Fundamentals Course)**.  
It demonstrates the use of **linked lists for dynamic data management** and **basic file handling in C**, making it a practical example of foundational programming concepts.

---

## 🎯 Key Features
- ✅ **Seat Reservation** – Allows booking of seats for passengers (up to 15).
- ✅ **Cancellation** – Deletes passenger record using a passport number.
- ✅ **Record Display** – Shows all current bookings neatly formatted.
- ✅ **File Storage** – Saves all booking details in a text file (`DSU_Airline_Records.txt`) on exit.
- ✅ **Dynamic Memory Allocation** – Uses `malloc()` and `free()` for flexible data storage.
- ✅ **Menu-Driven Interface** – Simple and interactive command-line navigation.

---

## 🧩 Data Structure Used
The system is implemented using a **Singly Linked List** where each node stores a passenger’s information:
```
[Passenger1] → [Passenger2] → [Passenger3] → NULL
```

### Each node contains:
- Passport Number
- Name
- Email
- Destination
- Seat Number

---

## ⚙️ Functional Flow
| Step | Function | Description |
|------|-----------|-------------|
| 1️⃣ | `main()` | Displays the menu and controls the program loop |
| 2️⃣ | `reserve()` | Adds a new passenger record (allocates memory dynamically) |
| 3️⃣ | `cancel()` | Removes a booking by matching the passport number |
| 4️⃣ | `display()` | Shows all current passengers with details |
| 5️⃣ | `saveToFile()` | Saves all records into a text file before exiting |
| 6️⃣ | `inputDetails()` | Collects user input for new bookings |

---

## 💻 How to Run
### 🧱 1. Compile the Program
If you’re using Code::Blocks, Dev-C++, or Turbo C, simply paste the code and run.
Or via command line:
```bash
gcc dsu_airline_management.c -o dsu_airline
```

### ▶️ 2. Run the Executable
```bash
./dsu_airline
```

---

## 🧠 Program Menu
```
Welcome to DSU Airline System

1. Reservation
2. Cancel
3. Display Records
4. Exit
Enter your choice:
```

---

## 📊 Sample Output
### ✈️ Reservation Example
```
Enter your passport number: AB123
Enter your name: Ahmed
Enter your email address: ahmed@gmail.com
Enter your destination: Dubai

Seat booking successful!
Your seat number is: A-1
```

### 📋 Display Example
```
Passport Number: AB123
Name: Rumaisa Fatima
Email: rumaisa@gmail.com
Seat Number: A-1
Destination: Germany
-------------------------------------------------------------
```

### ❌ Cancel Example
```
Enter passport number to delete booking: AB123
Booking has been deleted successfully.
```

### 💾 Exit Example
```
Details have been saved to 'DSU_Airline_Records.txt'.
Thank you for using DSU Airline System!
```



---

## 🧩 Concepts Demonstrated
- Linked Lists
- Structures (`struct`)
- Dynamic Memory Allocation (`malloc`, `free`)
- File Handling (`fopen`, `fprintf`, `fclose`)
- Menu-Driven Programming
- String Functions (`strcmp`, `gets`, `fflush`)

