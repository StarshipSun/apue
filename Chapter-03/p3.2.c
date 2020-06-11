#include "apue.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
	int fd;
	struct Node *next;
};

int my_dup2(int, int);

void free_fd(struct Node *head);

int main(void) {
    int newfd = my_dup2(STDIN_FILENO, 10);
	if (newfd < 0) {
		err_sys("my_dup2 error");
	} else {
    	printf("my_dup2 stdin_fileno: %d, newfd: %d\n", STDIN_FILENO, newfd);
	}
    exit(0);
}

int my_dup2(int fd, int fd2) {
    if (fd == fd2) {
        return fd2;
    }

    if (close(fd2) < 0) {
        if (errno == EBADF) {
            printf("fd2:%d no open\n", fd2);
        } else {
            err_sys("close fd2 error");
        }
    }

    int newfd;
	struct Node *head = (struct Node *) malloc(sizeof(struct Node));
	struct Node *cur = head;

    while ((newfd = dup(fd)) != fd2)
    {
        if (newfd < 0) {
			free_fd(head);
            printf("dup error for %d\n", fd);
			return -1;
        } else {
			printf("create fd:%d\n", newfd);
			struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
			temp->fd = newfd;
			temp->next = NULL;
			cur->next = temp;
			cur = temp;
		}
    }
    free_fd(head);
    return newfd;
}

void free_fd(struct Node *head) {
	struct Node *cur;
	while (head->next != NULL) {
		if (close(head->next->fd) == -1) {
			printf("close fd:%d error\n", head->next->fd);
		} else {
			printf("close fd:%d success\n", head->next->fd);
		}
		cur = head->next;
		free(head);
		head = cur;
	}
	free(head);
}
