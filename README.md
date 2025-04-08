# 🧪 Lab Rat (CLI RPG)

A terminal-based, text-driven adventure game where you play as a lab rat navigating a research facility. Solve puzzles, escape traps, and find your way to freedom, all from the command line.

---

## 👩‍💻 Author

**Rebecca Lashua**  
🌐 [beckylashua.com](https://beckylashua.com)  
📧 [beckylashua@gmail.com](mailto:beckylashua@gmail.com)     
🔗 [LinkedIn](https://www.linkedin.com/in/rebecca-lashua-a75096231/)  
🐙 [GitHub](https://github.com/BeckyLashua)

---

## 🧩 Features

- 🧭 Text-based navigation between rooms like the Lab Floor, Break Room, and Vents
- 🧠 Puzzle-solving mechanics with multiple object interactions
- 🧳 Inventory management and progression
- 🔄 Branching outcomes based on player actions
- 🐀 A tiny rat protagonist with big escape plans

---


## 🛠️ Technologies Used

- **C++**
- **Object-Oriented Programming (OOP)**
- **Text-Based UI**
- **Command-Line Interface (CLI)**
- **Manual memory and input handling**

---

## 🚀 Getting Started

**1. Clone the repository:**
   ```bash
   git clone https://github.com/BeckyLashua/lab-rat.git
   ```
**2. Navigate to the project directory:**
  ```bash
  cd lab-rat
  ```
**3. Compile the program using a C++ compiler (e.g. g++):**
  ```bash
  g++ -o labrat main.cpp Game.cpp BreakRoom.cpp Cage.cpp Closet.cpp LabFloor.cpp Office.cpp Outside.cpp Space.cpp Vent.cpp utility.cpp
  ```
**4. Run the game:**
  ```bash
  ./labrat
```

---

## 🎮 Controls

- Type commands like:
  - `go north`, `go south`, `enter vent` to move between spaces
  - `examine object`, `take item`, `use key` to interact with your environment
  - `inventory` to check what you’ve collected
- Follow in-game prompts and clues to explore, solve, and escape

---

## 🎓 Educational Purpose

This project was built as part of a hands-on exploration into object-oriented design and command-line interface logic using C++. It emphasizes:

- Designing flexible class hierarchies
- Parsing and responding to user input
- Managing program state without a GUI
- Structuring code for modularity and scalability

