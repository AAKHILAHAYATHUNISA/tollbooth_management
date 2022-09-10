#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[100], type[100], entry[100], exittime[100], date[100];
    int fare;
    struct node *next;
};

struct node *push(struct node *a, char *name1, char *type1, char *entry1, char *exittime1,char *date1){
    struct node *temp;
    if(a==NULL){
        temp = malloc(sizeof(struct node));
        strcpy(temp->name,name1);
        strcpy(temp->type,type1);
        strcpy(temp->entry,entry1);
        strcpy(temp->exittime,exittime1);
        strcpy(temp->date,date1);
        temp->next = NULL;
    }
    else{
        temp = malloc(sizeof(struct node));
        strcpy(temp->name,name1);
        strcpy(temp->type,type1);
        strcpy(temp->entry,entry1);
        strcpy(temp->exittime,exittime1);
        strcpy(temp->date,date1);
        temp->next = NULL;
        
        a->next = temp;
    }
    return temp;
}

struct node *begpop(struct node *head){
    struct node *temp = head->next;
    
    // head->name = NULL;
    // head->type = NULL;
    // head->entry = NULL;
    // head->exittime = NULL;
    // head->date = NULL;
    // head->next = NULL;
    free(head);
    
    return temp;
}

int main(){
    int num_of_entry;
    char name[100],type[100],entry[100],exittime[100],date[100];
    printf("Enter : ");
    scanf("%d", &num_of_entry);
    printf("\nEnter NAME : ");
    scanf("%s", &name);
    printf("\nEnter TYPE : ");
    scanf("%s", &type);
    printf("\nEnter TIME OF ENTRY : ");
    scanf("%s", &entry);
    printf("\nEnter TIME OF EXIT : ");
    scanf("%s", &exittime);
    printf("\nEnter DATE : ");
    scanf("%s", &date);
    
    struct node *head = push(head, name, type, entry, exittime, date);
    struct node *ptr = head;
    for(int i=0; i<num_of_entry; i++){
        printf("\nEnter NAME : ");
        scanf("%s", &name);
        printf("\nEnter TYPE : ");
        scanf("%s", &type);
        printf("\nEnter TIME OF ENTRY : ");
        scanf("%s", &entry);
        printf("\nEnter TIME OF EXIT : ");
        scanf("%s", &exittime);
        printf("\nEnter DATE : ");
        scanf("%s", &date);
        ptr = push(ptr, name, type, entry, exittime, date);
    }
    struct node *tail = ptr;
    printf("\nbefore deletion of head : ");
    ptr = head;
     while(ptr!=NULL){
         printf("\n");
         printf("%s %s %s %s %s", ptr->name, ptr->type, ptr->entry, ptr->exittime, ptr->date);
         ptr = ptr->next;
     }
    
    printf("\n\n\nafter deletion of head : ");
    head = begpop(head);
    ptr = head;
     while(ptr!=NULL){
         printf("\n");
         printf("%s %s %s %s %s", ptr->name, ptr->type, ptr->entry, ptr->exittime, ptr->date);
         ptr = ptr->next;
     }
    printf("\n"); 
    printf("\nnew head : %s %s %s %s %s ", head->name, head->type, head->entry, head->exittime, head->date);
    printf("\nnew tail : %s %s %s %s %s ", tail->name, tail->type, tail->entry, tail->exittime, tail->date);    
    
    printf("\n");
    head = begpop(head);
    ptr = head;
     while(ptr!=NULL){
         printf("\n");
         printf("%s %s %s %s %s", ptr->name, ptr->type, ptr->entry, ptr->exittime, ptr->date);
         ptr = ptr->next;
     }
    printf("\n"); 
    printf("\nnew head : %s %s %s %s %s ", head->name, head->type, head->entry, head->exittime, head->date);
    printf("\nnew tail : %s %s %s %s %s ", tail->name, tail->type, tail->entry, tail->exittime, tail->date);
    
    // head = begpop(head);
    // ptr = head;
    // while(ptr!=NULL){
    //      printf("%d ", ptr->data);
    //      ptr = ptr->next;
    //  }
    // printf("\ntail : %d ", tail->data); 
    // printf("\nhead : %d ", head->data);
    

    return 0;
}


