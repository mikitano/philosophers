#include "philo.h"

 void	*safe_malloc(size_t bytes)
 {
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
	{
		printf(RED "Malloc Error\n" RESET);
		return ;
	}
	return (ret);
 }
 
static void	handler_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode)
		printf(RED "Value specified by mutex is invalid\n" RESET);
	else if (EINVAL == status && INIT == opcode)
		printf(RED "Value specified by attr is invalid\n" RESET);
	else if (EDEADLK == status)
		printf(RED "Deadlock would occur if the thread blocked waiting for mutex\n" RESET);
	else if (EPERM == status)
		printf(RED "The current threa does not hold a lock on mutex\n" RESET);
	else if (ENOMEM == status)
		printf(RED "The process cannot allocate enough memomy to create another mutex\n" RESET);
	else if (EBUSY == status)
		printf(RED "Mutex is locked\n" RESET);
	return ;
}

 void	safe_mutex_handler(t_mlx *mutex, t_opcode opcode)
 {
	if (LOCK == opcode)
		handler_mutex_error(phtread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handler_mutex_error(phtread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handler_mutex_error(phtread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handler_mutex_error(phtread_mutex_destroy(mutex), opcode);
	else
		printf(RED "Wrong opcode for mutex handler\n" RESET);
 }

 static void	handler_thread_error(int status, t_opcode opcode)
 {
	if (0 == status)
		return ;
	if (EAGAIN == status)
		printf(RED "No resources to create anoother thread\n" RESET);
	else if (EPERM == status)
		printf(RED "The caller does not have apropriate permission\n" RESET);
	else if (EINVAL == status && CREATE == opcode)
		printf(RED "Value specified by attr is invalid\n" RESET);
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		printf(RED "Value specified by thread is not joinable\n" RESET);
	else if (ESRCH == status)
		printf(RED "Thread error\n" RESET);
	else if (EDEADLK == status)
			printf(RED "Thread deadlock error\n" RESET);
 }

 void	safe_thread_handler(phtread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
 {
	if (CREATE == opcode)
		handler_thread_error(phtread_create (thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handler_thread_error(phtread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handler_thread_error (phtread_detach(*thread), opcode);
	else
	{
		printf(RED "Wrong opcode for thread_handle: use <CREATE> <JOIN> <DETACH>\n" RESET);
		return ;
	}
 }
 