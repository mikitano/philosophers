# 🧠 Philosophers – 42 School

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![School](https://img.shields.io/badge/42-School-black.svg)]()
[![Threads](https://img.shields.io/badge/threads-pthreads-informational.svg)]()
[![Status](https://img.shields.io/badge/status-in_progress-success.svg)]()
[![Norminette](https://img.shields.io/badge/norminette-OK-brightgreen.svg)]()

This project is an implementation of the classic **Dining Philosophers Problem**, developed as part of the **42 School** curriculum.

The main objective is to work with **concurrent programming in C**, using **threads**, **mutexes**, and **precise time control**, while strictly avoiding **data races**, **deadlocks**, and undefined behavior.

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
🧩 Core Structures
t_table
c
Copiar código
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
Global simulation state

Shared timing parameters

Fork mutex array

Simulation control and synchronization

t_philo
c
Copiar código
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
Represents a single philosopher

Holds fork references

Tracks last meal time and meals count

Linked to the shared table structure

📁 File Overview
main.c
Entry point of the program

Argument validation

Simulation startup

parsing.c
Command-line argument parsing

Safe numeric conversion

Input validation according to the subject

init.c
Initialization of philosophers and forks

Mutex setup

Simulation timing initialization

philo.c
Philosopher routine

Life cycle:

thinking

taking forks

eating

sleeping

Fork locking strategy to avoid deadlocks

monitor.c
Dedicated monitoring thread

Checks philosopher death conditions

Ends simulation when a philosopher dies or meal limit is reached

sim_utils.c
Time management utilities

Thread-safe printing

Simulation helpers

utils.c
General helper functions

Shared utilities across the project

clean.c
Resource cleanup

Mutex destruction

Safe simulation termination

⚙️ Compilation
bash
Copiar código
make
Other rules:

bash
Copiar código
make clean
make fclean
make re
▶️ Usage
bash
Copiar código
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
Example
bash
Copiar código
./philo 5 800 200 200
With meal limit:

bash
Copiar código
./philo 5 800 200 200 7
🛑 Rules & Constraints
Each philosopher is a thread

Each fork is protected by a mutex

No data races

No deadlocks

Output is synchronized using a write mutex

Simulation stops immediately when a philosopher dies

📚 Concepts Covered
Multithreading with pthread

Mutex-based synchronization

Deadlock prevention strategies

Shared state protection

Accurate time handling

Safe input parsing

Resource cleanup in concurrent systems

🧪 Tested Environment
Linux

macOS

Compiler: cc

Flags: -Wall -Wextra -Werror
