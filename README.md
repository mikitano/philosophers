# 🧠 Philosophers – 42 School

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![School](https://img.shields.io/badge/42-School-black.svg)]()
[![Threads](https://img.shields.io/badge/threads-pthreads-informational.svg)]()
[![Status](https://img.shields.io/badge/status-in_progress-success.svg)]()
[![Norminette](https://img.shields.io/badge/norminette-OK-brightgreen.svg)]()

This project is an implementation of the classic **Dining Philosophers Problem**, developed as part of the **42 School** curriculum.

The main objective is to work with **concurrent programming in C**, using **threads**, **mutexes**, and precise **time management**, while strictly avoiding **data races**, **deadlocks**, and undefined behavior.

---

## 📂 Project Structure

```text
philo/
├── include/
│   └── philo.h
│
├── src/
│   ├── clean.c
│   ├── init.c
│   ├── main.c
│   ├── monitor.c
│   ├── parsing.c
│   ├── philo.c
│   ├── sim_utils.c
│   └── utils.c
│
└── Makefile
```

---

## 🧩 Core Structures

```c
t_table
typedef struct s_table
{
    pthread_t   monitor;
    int         philo_nbr;
    time_t      start_sim;
    time_t      time_die;
    time_t      time_eat;
    time_t      time_sleep;
    int         limit_meals;
    bool        end_sim;
    t_mutex     sim_lock;
    t_philo     *philos;
    t_mutex     *forks;
    t_mutex     write_lock;
}   t_table;

t_philo
typedef struct s_philo
{
    int         id;
    pthread_t   thread_id;
    t_mutex     *left_fork;
    t_mutex     *right_fork;
    long        meals_count;
    t_mutex     eat_lock;
    time_t      last_meal_time;
    t_table     *table;
}   t_philo;
```

---

## 📁 File Overview

**include/philo.h**
-  Main header file
-  Structure definitions
-  Function prototypes
-  Required system headers
-  Macros and ANSI colors for debugging

 
**src/main.c**
-  Program entry point
-  Argument validation
-  Simulation startup

 
**src/parsing.c**
-  Command-line argument parsing
-  Safe numeric conversion
-  Input validation

 
**src/init.c**
-  Initialization of philosophers and forks
-  Mutex setup
-  Simulation timing initialization

 
**src/philo.c**
- Philosopher routine implementation
- Life cycle:
    - thinking
    - taking forks
    - eating
    - sleeping

 
**src/monitor.c**
-  Monitoring thread
-  Death detection
-  Simulation termination control

 
**src/sim_utils.c**
-  Time management utilities
-  Thread-safe output
-  Simulation helpers

 
**src/utils.c**
-  General utility functions
-  Shared helpers

 
**src/clean.c**
-  Resource cleanup
-  Mutex destruction
-  Safe program termination

---

## ⚙️ Compilation

```c
make
```

Other available rules:
```c
make clean
make fclean
make re
```

---

## ▶️ Usage

```text
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example
```text
./philo 5 800 200 200
./philo 5 800 200 200 7
```

---

## 🛑 Rules & Constraints

- Each philosopher is represented by a **thread**
- Each fork is protected by a **mutex**
- No **data races**
- No **deadlocks**
- Output is synchronized using a write mutex
- The simulation stops immediately when a philosopher dies

---

## 📚 Concepts Covered

- Multithreading with pthread
- Mutex-based synchronization
- Deadlock prevention
- Shared state protection
- Accurate time handling
- Safe input parsing
- Resource cleanup in concurrent systems

---

## 🧪 Tested Environment

- Linux
- macOS
- Compiler: cc
- Flags: -Wall -Wextra -Werror
