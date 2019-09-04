#include <stdio.h>

struct list
{
        struct list *next;
        int data;
};

/*
        - prints the list
*/
void print_list(struct list *head)
{
        while(head != NULL){
                printf("%d ", head->data);
                head = head->next;
        }
        printf("\n");
}

/*
        - returns new empty list
*/
struct list* make_new()
{
        struct list *_new = (struct list*)malloc(sizeof(struct list));
        _new->data = 0;
        _new->next = NULL;
        return _new;
};

/*
        inserts new data after node with _data
        if _data does not exist, inserts it from the back
*/
void insert_node(struct list **head, int _data, int new_data)
{
        struct list *new_var = make_new();
        new_var->data = new_data;
        if((*head) == NULL){
                (*head) = new_var;
        } else{
                struct list *cur = *head;
                while(cur->next != NULL && cur->data != _data){
                        cur = cur->next;
                }
                if(cur->next == NULL){
                        cur->next = new_var;
                } else{
                        new_var->next = cur->next;
                        cur->next = new_var;
                }
        }
}

/*
        deletes the first node with data equal to _data
*/
void delete_node(struct list **head, int _data)
{
        struct list *cur = (*head), *pre = NULL;
        while(cur != NULL && cur->data != _data){
                pre = cur;
                cur = cur->next;
        }
        if(cur == NULL){
                return;
        }
        if(pre != NULL){
                pre->next = cur->next;
        } else{
                (*head) = cur->next;
        }
        free(cur);
}

int main()
{
        struct list *head = NULL;

        insert_node(&head, 0, 3); print_list(head);
        insert_node(&head, 3, 4); print_list(head);
        insert_node(&head, 4, 10); print_list(head);
        delete_node(&head, 3);
        insert_node(&head, 4, 7); print_list(head);

}
