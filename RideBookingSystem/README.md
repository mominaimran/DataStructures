# 🚖 Ride Booking System (C++ DSA Project)

A console-based Ride Booking System built in C++ using multiple Data Structures.  
The project simulates a real-world ride-hailing service where passengers can book rides, drivers are assigned automatically, and the system manages ride flow efficiently.

---

## 📌 Features

- 👤 Passenger Registration & Management  
- 🚗 Driver Registration & Availability System  
- 🧭 Automatic Driver Assignment  
- 📍 Nearest Driver Selection (Graph-based)  
- ⏳ Ride Queue System (Waitlist when no driver available)  
- 📚 Ride History (Linked List)  
- 🔙 Cancel Last Ride (Stack-based)  
- 💰 Sort Rides by Fare  
- 🔎 Search Passenger & Driver  
- 💾 File Handling for Data Persistence  
- 📊 Clean Console UI with Menu System  

---

## 🧠 Data Structures Used

- Array → Store passengers, drivers, rides  
- Queue → Waiting list for rides  
- Stack → Last ride cancellation  
- Linked List → Ride history storage  
- Graph (Adjacency Matrix) → Nearest driver calculation  
- Linear Search → Searching passengers/drivers  
- Bubble Sort → Sorting rides by fare  

---

## 🏗️ System Flow
 
1. Register passengers and drivers
2. Passenger requests ride
3. System checks available drivers
4. If driver available → ride assigned
5. If not → ride added to queue
6. When driver becomes free → queued ride assigned
7. Completed rides stored in history
8. Last ride can be cancelled using stack

---

## 👩‍💻 Author
- [Momina](https://github.com/mominaimran)

---