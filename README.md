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

---

## 🧩 Core Structures
t_table
```text
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

