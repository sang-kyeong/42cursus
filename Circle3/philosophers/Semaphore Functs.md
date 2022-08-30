# sem_open

### SYNOPSIS
```c
#include <semaphore.h>
sem_t	*sem_open(const char *name, int oflag, ...);
```
`mode_t mode` 와 `unsigned int value` 가 뒤에 올 수 있다.

### DESCRIPTION
`name`이라는 이름을 가진 semaphore를 초기화하고 `oflag`에 있는 속성으로 설정한다. 초기화한 semaphore descriptor를 반환한다.

`oflag`는 다음 속성을 or로 합쳐 나타낸다.
-	`O_CREAT`	해당 이름의 semaphore가 없다면 생성한다.
-	`O_EXCL`	새로 생성한 것과 이름이 같은 semaphore가 있다면 error를 반환한다.

`O_CREAT`을 사용했다면 추가로 두 개의 인자를 필요로 한다. `mode`는 chmod(2)와 같이 semaphore의 권한을 설정하며, 프로세스의 umask에 영향을 받는다(umask(2) 참조). semaphore는 생성될 때 `value`로 초기화되며 `value`는 SEM_VALUE_MAX보다 작거나 같아야 한다.

`O_EXCL`을 사용하면 해당 semaphore가 이미 있을 때 실패한다. `O_CREAT`와 `O_EXCL`을 사용해서 sem_open을 한다면 다른 process에게 간섭받지 않고 한번에 해당 semaphore가 있는지 확인하면서 생성할 수 있다.

semaphore가 생성된다면 process


# sem_close

# sem_post

# sem_wait

# sem_unlink