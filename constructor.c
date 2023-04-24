#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct Person {
    char name[10];
    uint8_t age;
    uint8_t height;
    void(*show)(struct Person *);
};

void person_print(struct Person *self) {
    printf("nome: %s age: %d height: %d\n", self->name, self->age, self->height);
}

struct Person * newPerson(char name[], uint8_t age, uint8_t height) {
    struct Person *self = (struct Person *)malloc(sizeof(struct Person *));
    strcpy(self->name, name);
    self->age = age;
    self->height = height;
    self->show = &person_print;
    return self;
}

void main() {
    struct Person *person2 = (struct Person *) newPerson("Eduardo", 29, 187);
    person2->show(person2);

    return;
}