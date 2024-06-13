#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    long long num;
    struct node *next;
};

struct node *head = NULL;

void singleInsert() {
    char in_name[50];
    long long in_num;
    printf("Enter name and number: ");
    scanf("%s %lld", in_name, &in_num);

    struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Cast to (struct node*)
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(new_node->name, in_name);
    new_node->num = in_num;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    fprintf(file, "%s %lld\n", in_name, in_num);
    fclose(file);

    printf("Inserted successfully\n");
}

void multiInsert() {
    int n;
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    if (n >= 1) {
        for (int i = 0; i < n; i++) {
            char in_name[50];
            long long in_num;
            printf("Enter name and number for entry %d: ", i + 1);
            scanf("%s %lld", in_name, &in_num);

            struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Cast to (struct node*)
            if (new_node == NULL) {
                printf("Memory allocation failed.\n");
                return;
            }
            strcpy(new_node->name, in_name);
            new_node->num = in_num;
            new_node->next = NULL;

            if (head == NULL) {
                head = new_node;
            } else {
                struct node *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }

            FILE *file = fopen("data.txt", "a");
            if (file == NULL) {
                printf("Unable to open file.\n");
                return;
            }
            fprintf(file, "%s %lld\n", in_name, in_num);
            fclose(file);

            printf("Inserted successfully\n");
        }
    }
}

void printList() {
    struct node *temp = head;
    printf("Linked list:\n");
    while (temp != NULL) {
        printf("Name: %s, Number: %lld\n", temp->name, temp->num);
        temp = temp->next;
    }
}

void search() {
    char ask[50];
    printf("Enter name you want to search: ");
    scanf("%s", ask);
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(ask, temp->name) == 0) {
            printf("The number for %s is %lld\n", ask, temp->num);
            return;
        }
        temp = temp->next;
    }
    printf("Name not found\n");
}

void fileHandling() {
printf("Hello\n");
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return;
    }
    char name[50];
    long long num;
    while (fscanf(file, "%s %lld", name, &num) == 2) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        strcpy(new_node->name, name);
        new_node->num = num;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    fclose(file);
}

void menu() {
    int c;
    while (1) {
        printf("Enter your choice:\n1: Single Insert\n2: Multi Insert\n3: Search\n4: Print all\n5: Exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                singleInsert();
                break;
            case 2:
                multiInsert();
                break;
            case 3:
                search();
                break;
            case 4:
                printList();
                break;
            case 5:
                exit(0);
            default:
                printf("Please enter a valid option\n");
        }
    }
}

int main() {
    fileHandling();
    menu();
    return 0;
}

