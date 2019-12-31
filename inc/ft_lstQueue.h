#ifndef		FT_LIST_QUEUE
# define	FT_LIST_QUEUE

#include "libft.h"

typedef struct		s_lstQ
{
	t_list*		head;
	t_list*		tail;
}			t_lstQ;

t_lstQ			ft_newlstQueue( void );
void			ft_lstQ( t_lstQ *queue, void *content, size_t content_size );
void			*ft_lstDQ( t_lstQ *queue );

#endif
