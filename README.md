# 🧠 Task Simulator – CLI Project in C

A simple, menu-driven **Task Management Simulator** written in C. This project demonstrates the use of arrays, structures, user input handling, and control flow to simulate a basic task tracker via the command line.

## 🚀 Features
- Add new tasks with descriptions  
- View all added tasks in a numbered list  
- Gracefully handles edge cases (e.g., max limit reached, no tasks yet)  
- Clean CLI interface with a loop-based menu system  

## 📁 File Structure
task_simulator/
├── task_simulator.c       # Main source code
└── README.md              # Project documentation
## 💡 Concepts Used
- `struct` in C to define a custom Task object  
- Array of structs to manage task list  
- Dynamic user input using `fgets()` and buffer clearing  
- Menu-driven UI using loops and switch-case logic  

## 🛠 How to Run
1. Open the folder in **VS Code**
2. Compile the program using:
   ```bash
   gcc task_simulator.c -o task_simulator
   ./task_simulator
